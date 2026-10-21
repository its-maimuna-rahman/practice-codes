#  1. Importing CSV Files

# Using read.csv():
data1 <- read.csv("tidyverse-data/prawnGR.CSV")
head(data1)

# Using readr::read_csv():
library(readr)
data1.1 <- read_csv("tidyverse-data/prawnGR.CSV")
head(data1.1)

# 2. Importing Excel Files
library(readxl)
data2 <- read_excel("tidyverse-data/whaledata.xls")
head(data2)

# 3. Importing Text Files
data3 <- read.table("tidyverse-data/atmosphere.txt", header = TRUE)
head(data3)

# 4. Importing SPSS Files
library(haven)
data4 <- read_sav("tidyverse-data/hw_dat.sav")
head(data4)

# 5. Importing Stata Files
library(haven)
data5 <- read_dta("tidyverse-data/hw_dat.dta")
head(data5)

# 6. Importing SAS Files
library(haven)
data6 <- read_sas("tidyverse-data/airline.sas7bdat")
head(data6)

# 7. Importing R’s native format
load("tidyverse-data/TemoraBR.RData")
head(TemoraBR)

# 8. Data Entry in R

# directly create a tibble:
library(tidyverse)
tibble(
  x = c(1, 2, 5),
  y = c("h", "m", "g"),
  z = c(0.08, 0.83, 0.60)
)

# using built-in (in base R) datasets
data()    # to list datasets
data(mtcars)
head(mtcars)

# Importing Datasets from Packages
library(gapminder)
data(gapminder)
head(gapminder)

# Exporting data

# Exporting to R objects (.RData)
save(mtcars, TemoraBR, file = "two-data-sets.RData")

# Exporting to CSV
write.csv(mtcars, "mtcars.csv")
readr::write_excel_csv(mtcars, "mtcars2.csv")

# Exporting to Text Files

# Export as space-separated text
write.table(mtcars, "mtcars.txt")

# Export as tab-separated text
write.table(mtcars, "mtcars_tab.txt", sep = "\t")

# Export as CSV using write.table
write.table(mtcars, "mtcars_custom.csv",
            sep = ",", row.names = FALSE)