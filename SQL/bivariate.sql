USE northwind;

-- FREQUENCY
-- How are customers distributed geographically
SELECT country, city, COUNT(*) AS frequency
FROM Customer
GROUP BY country, city;

-- How are products distributed across categories and suppliers?
SELECT productId, categoryId, COUNT(*) AS frequency
FROM Product
GROUP BY productId, categoryId;

-- CORRELATION COEFFICIENT
SELECT
((COUNT(*) * SUM(quantity * discount)) - (SUM(quantity) * SUM(discount)))/
SQRT((COUNT(*) * SUM(quantity * quantity) - (POW(SUM(quantity), 2))) * (COUNT(*) * SUM(discount * discount) - (POW(SUM(discount), 2))))
AS corr_coeff
FROM OrderDetail;

-- the correlation between unit price and discount rate
SELECT
((COUNT(*) * SUM(unitPrice * discount)) - (SUM(unitPrice) * SUM(discount))) / 
SQRT((COUNT(*) * SUM(unitPrice * unitPrice) - (POW(SUM(unitPrice), 2))) * (COUNT(*) * SUM(discount * discount) - (POW(SUM(discount), 2))))
AS corr_coeff
FROM OrderDetail;

-- regression between quantity and discount
SELECT
((COUNT(*) * SUM(quantity * discount)) - (SUM(quantity) * SUM(discount))) /
((COUNT(*) * SUM(discount * discount)) - POW(SUM(discount), 2))
AS slope,
AVG(quantity) - (AVG(discount) * 
(((COUNT(*) * SUM(quantity * discount)) - (SUM(quantity) * SUM(discount))) /
((COUNT(*) * SUM(discount * discount)) - POW(SUM(discount), 2))))
AS intercept
FROM OrderDetail;