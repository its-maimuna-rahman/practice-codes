
"""Train and evaluate the World Bank GDP-per-capita model."""

from pathlib import Path

import numpy as np
import pandas as pd
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

from model import build_model


# Locate the project and dataset
PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA_PATH = PROJECT_ROOT / "data" / "world_bank_clean.parquet"

# Location for saving test-set predictions
OUTPUT_DIR = PROJECT_ROOT / "outputs"
PREDICTIONS_PATH = OUTPUT_DIR / "gdp_predictions.csv"


def main():
    # 1. Load and validate the data
    if not DATA_PATH.exists():
        raise FileNotFoundError(f"Dataset not found: {DATA_PATH}")

    df = pd.read_parquet(DATA_PATH)

    # Remove accidental whitespace from column names
    df.columns = df.columns.str.strip()

    features = ["edu_spend", "electricity_access"]
    target = "gdp_per_capita"

    required_columns = ["country_code", "year", *features, target]

    missing_columns = set(required_columns) - set(df.columns)

    if missing_columns:
        raise ValueError(
            f"Missing required columns: {sorted(missing_columns)}"
        )

    # 2. Convert relevant columns to appropriate data types
    numeric_columns = ["year", *features, target]

    for column in numeric_columns:
        df[column] = pd.to_numeric(df[column], errors="coerce")

    df["country_code"] = (
        df["country_code"].astype("string").str.strip().str.upper()
    )

    # A missing year or target makes a row unsuitable for this model
    df = df.dropna(subset=["country_code", "year", target]).copy()
    df["year"] = df["year"].astype(int)

    # Check that each country-year combination is unique
    if df.duplicated(subset=["country_code", "year"]).any():
        raise ValueError(
            "Duplicate country-year rows found. "
            "Resolve them before training the model."
        )

    df = df.sort_values(["year", "country_code"]).copy()

    # 3. Split by time: earlier years for training, later years for testing
    years = sorted(df["year"].unique())

    if len(years) < 2:
        raise ValueError("At least two distinct years are required.")

    split_index = max(1, int(len(years) * 0.8))
    test_start_year = years[split_index]

    train_df = df[df["year"] < test_start_year].copy()
    test_df = df[df["year"] >= test_start_year].copy()

    if train_df.empty or test_df.empty:
        raise ValueError("The time-based train-test split is empty.")

    X_train = train_df[features]
    y_train = train_df[target]

    X_test = test_df[features]
    y_test = test_df[target]

    # Check that each feature has at least one observed training value
    for column in features:
        if X_train[column].notna().sum() == 0:
            raise ValueError(
                f"Feature '{column}' has no observed values in training data."
            )

    # 4. Build the pipeline (median imputer + random forest, defined in model.py)
    model = build_model()

    # 5. Train the model using training data only
    print(f"Training years: {train_df['year'].min()}–{train_df['year'].max()}")
    print(f"Testing years:  {test_df['year'].min()}–{test_df['year'].max()}")
    print(f"Training rows: {len(train_df)}")
    print(f"Testing rows:  {len(test_df)}")

    model.fit(X_train, y_train)

    # 6. Predict GDP per capita for the test data
    y_pred = model.predict(X_test)

    # 7. Evaluate model performance
    mae = mean_absolute_error(y_test, y_pred)
    rmse = np.sqrt(mean_squared_error(y_test, y_pred))
    r2 = r2_score(y_test, y_pred) if len(y_test) >= 2 else float("nan")

    print("\nModel Evaluation")
    print("----------------")
    print(f"Mean Absolute Error (MAE): {mae:,.2f}")
    print(f"Root Mean Squared Error (RMSE): {rmse:,.2f}")
    print(f"R-squared (R²): {r2:.4f}")

    # 8. Save actual and predicted values for further analysis
    results = test_df[["country_code", "year"]].copy()
    results["actual_gdp_per_capita"] = y_test.to_numpy()
    results["predicted_gdp_per_capita"] = y_pred
    results["absolute_error"] = np.abs(
        results["actual_gdp_per_capita"]
        - results["predicted_gdp_per_capita"]
    )

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    results.to_csv(PREDICTIONS_PATH, index=False)

    print(f"\nPredictions saved to: {PREDICTIONS_PATH}")

    return model, results


if __name__ == "__main__":
    main()
