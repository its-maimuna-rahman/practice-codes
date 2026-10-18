"""Define the regression model and missing-value preprocessing."""

from sklearn.ensemble import RandomForestRegressor
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline

def build_model() :
    """Create a pipeline that imputes missing predictors and fits a regressor."""

    model = Pipeline([
        ("imputer", SimpleImputer(strategy="median")),
        (
            "regressor",
            RandomForestRegressor(
                n_estimators = 100,
                max_depth = 12,
                random_state = 42,
                n_jobs = -1,
            )
        )
    ])

    return model