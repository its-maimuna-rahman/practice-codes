from pathlib import Path

import pandas as pd

# load the saved dataset we imported from the world bank api through data_loader.py
PROJECT_ROOT = Path(__file__).resolve().parent.parent
df = pd.read_parquet(PROJECT_ROOT / "data" / "world_bank_clean.parquet")
df.columns = df.columns.str.strip()

# 1. basic structure
print("\ndata shape:", df.shape)
print("\ncolumn names:")
print(df.columns.tolist())

# 2. to preview observations
print("\nfirst 5 rows:")
print(df.head())

print("\nlast 5 rows:")
print(df.tail())

#  3. Data types and non-missing values
print("\ndataset information:")
df.info()

# 4. Summary statistics
print("\nsummary statistics:")
print(df.describe())

# 5. missing values
print("\nmissing values:")
print(df.isnull().sum())

print("\nmissing value percentage:")
print((df.isnull().mean() * 100).round(2))

# 6. Duplicate rows
print("\nduplicate rows:")
print(df.duplicated().sum())

# 7. Country and year coverage
print("\nNumber of unique countries:", df["country_code"].nunique())
print("Year range:", df["year"].min(), "-", df["year"].max())