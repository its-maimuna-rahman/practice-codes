# World Bank GDP per Capita Model

A small project I built to learn the ML workflow end to end: pull data, explore it, check missing values, then train and evaluate a model.

The model predicts GDP per capita from education spending (% of GDP) and electricity access (% of population), using a random forest.

## Structure

```
.
├── README.md
├── requirements.txt
├── data/
│   ├── world_bank_clean.parquet      # dataset from the World Bank API
│   └── audit/                        # missing-data audit results (CSV)
├── outputs/                          # created by train.py
└── src/
    ├── data_loader.py                # fetch indicators from the World Bank API
    ├── explore_data.py               # shape, dtypes, summary stats, missing values
    ├── missing_data_audit.py         # missingness by overall / year / country
    ├── model.py                      # median imputer + RandomForestRegressor pipeline
    └── train.py                      # time-based split, training, evaluation
```

## Setup

```
pip install -r requirements.txt
```

## Run

Run from the project root, in this order:

```
python src/data_loader.py          # needs internet; saves data/world_bank_clean.parquet
python src/explore_data.py
python src/missing_data_audit.py   # saves CSVs to data/audit/
python src/train.py                # saves outputs/gdp_predictions.csv
```

A copy of the dataset is already in `data/`, so you can skip the first step.

## Data

- Source: World Bank API (via `wbgapi`), 2000–2023
- Indicators: GDP per capita, education spending, health spending, electricity access, CO2 per capita
- The included parquet only has GDP per capita, education spending and electricity access, and still contains regional/income aggregates (World, EU, IDA, etc.). `data_loader.py` now skips aggregates, so re-run it to get a clean country-only file.
- Missing values: education spending is about 33% missing, GDP per capita about 3%, electricity access about 1.5%

## Model

- Features: `edu_spend`, `electricity_access`. Target: `gdp_per_capita`
- Rows with a missing target are dropped. Missing features are filled with the training-set median.
- Split by time, not randomly: 2000–2018 for training, 2019–2023 for testing

## Results (included dataset)

| Metric | Value |
|---|---|
| MAE | 12,635 |
| RMSE | 23,407 |
| R² | 0.30 |

## Limitations

- Only two features, so the R² is low
- Random forests can't predict beyond the range they saw in training, which hurts on a time split since GDP keeps growing
- Median imputation hides the fact that education spending is missing for many country-years
