# ======================== 1. starting =====================================================
library(tidyverse)
library(palmerpenguins)

glimpse(penguins)
head(penguins)

# =============== 2. The pipe: reading steps in order ======================================

# nested form
filter(penguins, species == "Chinstrap")
# piped form
penguins |>
  filter(species == "Chinstrap")

# Saving a result
chainstrap <- penguins |>
  filter(species == "Chinstrap")
chainstrap

# ====================== 3. working with rows ==============================================

#find Chinstrap penguins whose bill length exceeds 52 mm.
penguins |>
  filter(species == "Chinstrap", bill_length_mm > 52)

# or condition
penguins |>
  filter(species == "Chinstrap" | species == "Gentoo")

penguins |>
  filter(species %in% c("Chinstrap", "Gentoo"))

# ========================= exercise 1 ======================================================

# 1. Keep Gentoo penguins with bill depth at least 15.5 mm.
penguins |>
  filter(species == "Gentoo", bill_depth_mm >= 15.5)

# 2. Keep male penguins recorded on Dream or Biscoe Island.
penguins |>
  filter(sex == "male", island %in% c("Dream", "Biscoe"))

# 3. Keep penguins that are either Gentoo or have body mass greater than 4500 g.
penguins |>
  filter(species == "Gentoo"| body_mass_g > 4500)

# Order rows with arrange()
penguins |> 
  arrange(bill_length_mm)   # asc

penguins |> 
  arrange(desc(bill_length_mm))   # desc

# several columns
penguins |>
  arrange(desc(bill_depth_mm),
          desc(flipper_length_mm))

# Select rows by position with slice()
penguins |> slice(1:5)
penguins |> slice(c(3, 10))

# Largest and smallest values

# find the three largest bill lengths.
penguins |>
  slice_max(order_by = bill_length_mm, n = 3)

# find the three smallest body masses.
penguins |>
  slice_min(order_by = body_mass_g, n = 3)

# sample rows
penguins |> slice_sample(n = 3)                     # sample 3 penguins
penguins |> slice_sample(prop = 0.1)                # sample 10% of the data
penguins |> slice_sample(n = 5, replace = TRUE)     # sample with replacement

# Unique rows with distinct()
penguins |>
  distinct(species, year)

# ========================== exercise 2 ======================================================

# 1. Sort penguins by species, then by decreasing body mass within species.
penguins |> arrange(species, desc(body_mass_g))

# 2. Return exactly five rows with the largest non-missing flipper lengths.
penguins |> slice_max(n = 5, flipper_length_mm, with_ties = F)

# 3. List the distinct combinations of species and island.
penguins |> distinct(species, island)

# ====================== 4. working with columns ===============================================
penguins |> select(year, island, species)

names(penguins)                           # all column names
penguins |> select(species:body_mass_g)   # all column from species to body_mass
penguins |> select(species:bill_depth_mm, -island)  # from species to bill depth
                                                    # but without island
# rename and reorder
penguins |> select(species, year, bill_len = bill_length_mm)

penguins |> select(starts_with("bill"))
penguins |> select(ends_with("mm"))
penguins |> select(contains("_"))

# Rename columns with rename()
penguins |>
  rename(location = island)

# ============================== exercise 3 ==================================================

# 1. Keep only the body_mass_g variable.
penguins |> select(body_mass_g)

# 2. Keep columns from bill_length_mm to body_mass_g, and year.
penguins |> select(bill_length_mm:body_mass_g, year)

# 3. Keep all columns except island.
penguins |> select(-island)

# 4. Keep the species column and any columns that end with "mm".
penguins |> select(species, ends_with("mm"))

# 5. Rename bill_length_mm to bill_length, keeping all other columns.
penguins |> rename(bill_length = bill_length_mm)

# Create variables with mutate()
penguins |> mutate(body_mass_kg = body_mass_g / 1000)

# to create mutate column in the beginning
penguins |>
  mutate(body_mass_kg = body_mass_g / 1000,
         .before = 1)

# Recode into two categories: if_else()
penguins |>
  mutate(
    flip_size = if_else(
      flipper_length_mm > 210, "large", "short"
    )
  )

# Recode into several categories: case_when()
penguins |>
  mutate(
    mass_c = case_when(
      body_mass_g > 4500 ~ "large",
      body_mass_g > 3000 & body_mass_g <= 4500 ~ "medium",
      body_mass_g <= 3000 ~ "small"
    ), .before = 1
  )

# ==================== 5. Combining row and column steps =====================================

# find female Adelie penguins, show their bill measurements, and order them
# from longest to shortest bill.

penguins |>
  filter(species == "Adelie", sex == "female") |>
  select(species, sex, starts_with("bill")) |>
  arrange(desc(bill_length_mm))

# ============================= exercise 4 ==================================================

# 1. Keep female penguins from Dream Island, then select species and all
# columns starting with "bill".
penguins |>
  filter(sex == "female", island == "Dream") |>
  select(species, starts_with("bill"))

# 2. Create flipper_m by converting flipper_length_mm to metres.
penguins |>
  mutate(fiipper_m = flipper_length_mm / 1000)

# 3. Create year_fct by converting year to a factor using as.factor().
penguins |>
  mutate(year_fct = as.factor(year))

# 4. Within a single mutate() call: convert species to character; create 
# flipper_cm in centimetres; convert island to lowercase with tolower().
penguins |>
  mutate(
    species = as.character(species),
    flipper_cm = flipper_length_mm / 10,
    island = tolower(island)
  )

# 5. Create a body-mass category using the boundaries above, then keep only 
# Gentoo penguins in the large category.
penguins |>
  mutate(
    mass_c = case_when(
      body_mass_g > 4500 ~ "large",
      body_mass_g > 3000 & body_mass_g <= 4500 ~ "medium",
      body_mass_g <= 3000 ~ "small"
    )
  ) |>
  filter(species == "Gentoo", mass_c == "large")
  
# ================== 6. overall and grouped summaries =======================================

# the mean and standard deviation of body mass for all penguins.
penguins |>
  summarise(
    mean_mass = mean(body_mass_g, na.rm = TRUE),
    sd_mass = sd(body_mass_g, na.rm = TRUE)
  )

# to get a separate summary for each species, first define the groups.
penguins |> group_by(species)

# Summarise within groups
penguins |>
  group_by(species) |>
  summarise(
    mean_mass = mean(body_mass_g, na.rm = T),
    sd_mass = sd(body_mass_g, na.rm = T)
  )

# temporary grouping
penguins |>
  summarise(
    mean_mass = mean(body_mass_g, na.rm = TRUE),
    sd_mass = sd(body_mass_g, na.rm = TRUE),
    .by = species
  )

# =============================== exercise 5 ===============================================

# 1. For Chinstrap penguins, find the maximum and minimum flipper lengths by
# island. Name the columns flip_max and flip_min; exclude missing values. How
# many islands appear?
penguins |>
  filter(species == "Chinstrap") |>
  summarise(
    flip_max = max(flipper_length_mm, na.rm = TRUE),
    flip_min = min(flipper_length_mm, na.rm = TRUE),
    .by = island
  )
  
  

# 2. In one pipeline: create bill_ratio (bill length divided by bill depth);
# keep only species and bill_ratio; group by species; calculate the mean bill
# ratio (excluding missing values) and name it bill_ratio_mean.

penguins |>
  mutate(
    bill_ratio = bill_length_mm / bill_depth_mm
  ) |>
  select(species, bill_ratio) |>
  group_by(species) |>
  summarise(
    bill_ratio_mean = mean(bill_ratio, na.rm = T)
  )

# Rewrite the summary in question 2 using .by instead of group_by().
penguins |>
  mutate(
    bill_ratio = bill_length_mm / bill_depth_mm
  ) |>
  select(species, bill_ratio) |>
  summarise(
    bill_ratio_mean = mean(bill_ratio, na.rm = T),
    .by = species
  )

# ======================= 7. Frequencies and proportions ======================================

# count()
penguins |>
  count(species)

penguins |>
  count(species, name = "freq", sort = T)

# what proportion of the observations belongs to each species?
penguins |>
  count(species) |>
  mutate(
    proportion = n / sum(n)
  )

# Count a newly created category
penguins |>
  mutate(
    flip_size = if_else(flipper_length_mm > 210, "large", "small")
  ) |>
  count(flip_size) |>
  mutate(
    prop = n / sum(n)
  )

penguins |>
  mutate(
    mass_c = case_when(
      body_mass_g > 4500 ~ "large",
      body_mass_g > 3000 & body_mass_g <= 4500 ~ "medium",
      body_mass_g <= 3000 ~ "small"
    )
  ) |>
  count(mass_c)

# count each combination of species and year.
penguins |>
  count(species, year, sort = T)

penguins |>
  count(species, year) |>
  mutate(prop = n / sum(n))

# using .by() : within each species, what share was observed in each year?
penguins |>
  count(species, year) |>
  mutate(prop = n / sum(n), .by = species)

# within each year what share was observed in each species?
penguins |>
  count(species, year) |>
  mutate(prop = n / sum(n), .by = year)

# ============================== exercise 6 ===================================================

# 1. Find the frequency and relative frequency of each island.
penguins |>
  count(island, name = "freq") |>
  mutate(rel_freq = freq / sum(freq))

# 2. Count penguins by species and sex, retaining missing sex as a separate
# category.
penguins |>
  count(species, sex)

# 3. Using those counts, calculate the proportions of sex categories within
# each species.
penguins |>
  count(species, sex) |>
  mutate(prop = n / sum(n), .by = species)

# ==================== 8. Repeating operations across columns ==================================

penguins |>
  summarise(
    mean_bill_length = mean(bill_length_mm, na.rm = T),
    mean_bill_depth = mean(bill_depth_mm, na.rm = T),
    mean_flipper = mean(flipper_length_mm, na.rm = T),
    .by = species
  )

penguins |>
  summarise(
    across(
      .cols = ends_with("mm"),
      .fns = \(x) mean(x, na.rm = TRUE)
    ),
    .by = species
  )

penguins |>
  summarise(
    across(3:6, \(x) sd(x, na.rm = T))
  )

penguins |>
  summarise(
    across(3:6, ~sd(.x, na.rm = T))
  )

penguins |>
  summarise(
    across(where(is.numeric), \(x) mean(x, na.rm = T))
  )

# ============================== exercise 7 ==================================================

# 1. Find the standard deviation of every column ending in "mm", by species.
penguins |>
  summarise(
    across(ends_with("mm"), \(x) sd(x, na.rm = TRUE)),
    .by = species
  )

# 2. Convert all columns ending in "mm" to centimetres using
# mutate(across(...)). Explain why their column names would then need updating.
penguins |>
  mutate(
    across(ends_with("mm"), \(x) x/10)
  )

# =============================== exercise 8 ================================================

#Using one pipeline, start with penguins and:
  
# keep female penguins from Dream or Biscoe Island;
# create body_mass_kg from body_mass_g;
# find the mean body mass in kg for each species, excluding missing measurements;
# arrange the summary from largest to smallest mean.

penguins |>
  filter(sex == "female", island %in% c("Dream", "Biscoe")) |>
  mutate(body_mass_kg = body_mass_g / 1000) |>
  summarise(
    mean_kg = mean(body_mass_kg, na.rm = TRUE),
    .by = species
  ) |>
  arrange(desc(mean_kg))
