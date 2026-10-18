import wbgapi as wb
import pandas as pd
from pathlib import Path

INDICATORS = {
    "NY.GDP.PCAP.CD" : "gdp_per_capita",
    "SE.XPD.TOTL.GD.ZS" : "edu_spend",
    "SE.XPD.CHEX.GD.ZS" : "health_spend",
    "EG.ELC.ACCS.ZS" : "electricity_access",
    "EN.ATM.CO2E.PC" : "co2_per_capita",
}

def fetch_data(start_year = 2000, end_year = 2023):
    df = wb.data.DataFrame(
        list(INDICATORS.keys()),
        time=range(start_year, end_year + 1),
        numericTimeKeys=True,
        columns="series",
        skipAggs=True,
    )

    df = df.reset_index()
    df = df.rename(columns=INDICATORS)
    df = df.rename(
        columns={"economy": "country_code", "time": "year"}
    )

    return df


if __name__ == "__main__":
    print("Main block started")

    df = fetch_data()

    project_root = Path(__file__).resolve().parent.parent
    output_path = project_root / "data" / "world_bank_clean.parquet"

    output_path.parent.mkdir(parents=True, exist_ok=True)
    df.to_parquet(output_path, index=False)
    print("Dataset saved successfully!")

    print(df.head())
    print("Shape:", df.shape)
    print("Columns:", df.columns.tolist())