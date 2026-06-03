-- ------------------------------------ WORLD DB --------------------------------------------
USE world;

-- 1. Write a query to display the Name, Continent, and Region of all
--  countries in the country table, sorted alphabetically by name.
SELECT Name, Continent, Region
FROM country
ORDER BY Name;

--  2. Find the names of all cities in the city table that
--  have a population between 1,000,000 and 2,000,000
SELECT Name, Population
FROM city
WHERE Population BETWEEN 1000000 AND 2000000;


--  3. List all the unique GovernmentForm types available in the country table
SELECT DISTINCT GovernmentForm
FROM country;

-- 4. Retrieve the details of all countries whose name ends with the suffix 'land'
SELECT *
FROM country
WHERE Name LIKE '%land';

-- 5. Find the maximum and minimum LifeExpectancy recorded in the country table
SELECT MIN(LifeExpectancy) AS min_life_exp, MAX(LifeExpectancy) AS max_life_exp
FROM country;

-- 6. Count the total number of cities in each country and
-- display only those countries that have more than 100 cities.
SELECT CountryCode, COUNT(*) AS city_count
FROM city
GROUP BY CountryCode
HAVING city_count > 100;

-- 7. Retrieve the Name of the country and its corresponding official Language for
-- all countries where the official language is 'Spanish'
SELECT c.Name, cl.Language 
FROM country c 
INNER JOIN countrylanguage cl ON c.Code = cl.CountryCode 
WHERE cl.Language = 'Spanish' AND cl.IsOfficial = 'T';

-- 8. Find the names of countries that have a GNP higher than the overall
-- average GNP of all countries in the database.
SELECT Name, GNP
FROM country
WHERE GNP > (SELECT AVG(GNP) FROM country);

-- 9. Write a query to calculate the population density (Population / SurfaceArea) for 
-- every country, naming the column Density, and display the top 10 most densely populated countriesj
SELECT Name, (Population / SurfaceArea) AS Density
FROM country
ORDER BY Density DESC
LIMIT 10;

-- *******************************************************************************
-- 10. Retrieve the name of each country and the name of its capital city.
SELECT co.Name AS Country, ci.Name AS Capital 
FROM country co 
INNER JOIN city ci ON co.Capital = ci.ID;

-- ********************************************************************************
-- 11. Find the names of countries where the total number of non-official languages
-- spoken is greater than the number of official languages
SELECT Name 
FROM country c 
WHERE (
    SELECT COUNT(*) 
    FROM countrylanguage cl 
    WHERE cl.CountryCode = c.Code AND cl.IsOfficial = 'F'
) > (
    SELECT COUNT(*) 
    FROM countrylanguage cl 
    WHERE cl.CountryCode = c.Code AND cl.IsOfficial = 'T'
);

-- ******************************************************************************************************
-- 12. Perform a LEFT JOIN to list all countries and their official languages, ensuring
--  that countries with no official language listed (or no language records at all) are still included in the result
SELECT co.Name, cl.Language 
FROM country co 
LEFT JOIN countrylanguage cl ON co.Code = cl.CountryCode AND cl.IsOfficial = 'T';

-- 13. Create a view named Region_Stats that displays the Region, the total population
-- of that region, and the average LifeExpectancy of countries within that region
CREATE VIEW Region_Stats AS
SELECT Region, SUM(Population), AVG(LifeExpectancy)
FROM country
GROUP BY Region;
SELECT * FROM Region_Stats;

-- 14. Write a query to show the distribution of countries by Continent and GovernmentForm,
-- displaying the Continent, GovernmentForm, and the frequency (count) of countries for each pair
SELECT Continent, GovernmentForm, COUNT(*) AS freq
FROM country 
GROUP BY Continent, GovernmentForm;

-- 15. Using the mathematical formulas for regression provided in the lecture, write a SQL query to
-- calculate the intercept (β1 for the relationship between a country's SurfaceArea (X) and its GNP (Y)
SELECT 
(COUNT(*) * SUM(SurfaceArea * GNP) - SUM(SurfaceArea) * SUM(GNP)) /
(COUNT(*) * SUM(SurfaceArea * SurfaceArea) - SUM(SurfaceArea) * SUM(SurfaceArea))
AS b1
FROM country;
