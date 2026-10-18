from pathlib import Path
import pandas as pd

# 1. Locate the project data file reliably
PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA_PATH = PROJECT_ROOT / "data" / "world_bank_clean.parquet"

df = pd.read_parquet(DATA_PATH)

# 2. Standardize column names
df.columns = df.columns.str.strip()

# 3. Define the columns we want to investigate
indicators = [
    "gdp_per_capita",
    "edu_spend",
    "electricity_access",
]

# 4. Overall missingness
missing_summary = pd.DataFrame({
    "missing_count": df[indicators].isna().sum(),
    "missing_percent": df[indicators].isna().mean() * 100,
})

print("\n--- Overall missingness ---")
print(missing_summary.round(2))

# 5. Missingness by year
missing_by_year = (
    df.groupby("year")[indicators]
    .apply(lambda group: group.isna().mean() * 100)
)

print("\n--- Missing percentage by year ---")
print(missing_by_year.round(2).to_string())

# 6. Missingness by country
missing_by_country = (
    df.groupby("country_code")[indicators]
    .apply(lambda group: group.isna().mean() * 100)
)

print("\n--- Countries with the most missing values ---")
print(
    missing_by_country
    .assign(total_missing=missing_by_country.sum(axis=1))
    .sort_values("total_missing", ascending=False)
    .head(15)
    .round(2)
    .to_string()
)

# 7. Count rows with different numbers of missing indicators
missing_count_per_row = df[indicators].isna().sum(axis=1)

print("\n--- Missing indicators per row ---")
print(missing_count_per_row.value_counts().sort_index())

# 8. Check whether entire rows are missing for any indicator
for column in indicators:
    yearly_summary = (
        df.groupby("year")[column]
        .agg(
            total_rows="size",
            missing_count=lambda values: values.isna().sum(),
        )
    )

    yearly_summary["missing_percent"] = (
        yearly_summary["missing_count"]
        / yearly_summary["total_rows"]
        * 100
    )

    print(f"\n--- {column}: missingness by year ---")
    print(yearly_summary.round(2).to_string())

    

# 9. Save audit results without changing the original dataset
OUTPUT_DIR = PROJECT_ROOT / "data" / "audit"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

missing_summary.to_csv(
    OUTPUT_DIR / "overall_missingness.csv"
)
missing_by_year.to_csv(
    OUTPUT_DIR / "missingness_by_year.csv"
)
missing_by_country.to_csv(
    OUTPUT_DIR / "missingness_by_country.csv"
)

print("\nAudit complete. Original dataset unchanged.")
