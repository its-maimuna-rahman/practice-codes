-- --------------------- NORTHWIND PRACTICE -------------------------------------
USE northwind;

-- 1. Write a query to select all columns from the Employee table.
SELECT * 
FROM Employee;

-- 2. Display the ProductName and UnitPrice for all items.
SELECT ProductName, UnitPrice 
FROM Product;

-- 3. List all customers, sorted alphabetically by their CompanyName.
SELECT * 
FROM Customer 
ORDER BY CompanyName;

-- 4. Find all products in the Product table that have a UnitPrice greater than 50.
SELECT productId, productName, unitPrice 
FROM Product 
WHERE UnitPrice > 50;

-- 5. List all the distinct Country values where the Northwind company has suppliers.
SELECT DISTINCT country
FROM Supplier;

-- 6. Count the total number of customers located in each Country and sort the results in descending order.
SELECT country, COUNT(*) AS cust_count
FROM Customer
GROUP BY country
ORDER BY cust_count DESC;

-- ******************************************************************************
-- 7. Identify the CategoryID groups in the Products table that have an average UnitPrice higher than 25.
SELECT CategoryId, AVG(unitPrice) AS avg_unitprice
FROM Product
GROUP BY CategoryId
HAVING avg_unitprice > 25;

-- 8. Show the ProductName and the corresponding CategoryName for each product 
SELECT p.productName, c.categoryName
FROM Product p
INNER JOIN Category c ON p.categoryId =  c.categoryId;

-- 9. Retrieve the first name and last name of all employees whose LastName starts with the letter 'D'.
SELECT firstname, lastname
FROM Employee
WHERE lastname LIKE 'D%';

-- 10. Display the OrderID and the total value for each line item in Order Details
-- (calculated as UnitPrice * Quantity * (1 - Discount)), naming the column SalesValue.
SELECT orderId, (unitPrice * Quantity * (1 - discount)) AS SalesValue
FROM OrderDetail;

-- 11. Find the names of products that have a UnitPrice higher than the overall average price
-- of all products in the database.

SELECT ProductName
FROM Product
WHERE UnitPrice > (SELECT AVG(UnitPrice) FROM Product);

-- 12. List all Customers and their OrderIDs.
-- Ensure that customers who have never placed an order are still included.

SELECT c.custId, c.companyName, s.orderId
FROM Customer c
LEFT JOIN SalesOrder s ON c.custId = s.custId;

-- 13. Create a view named Employee_Performance that displays each employee's
-- FirstName, LastName, and the total number of orders they have processed.

CREATE VIEW Employee_Performance AS
SELECT e.employeeId,
       e.firstname,
       e.lastname,
       COUNT(s.orderId) AS TotalOrders
FROM Employee e
LEFT JOIN SalesOrder s ON e.employeeId = s.employeeId
GROUP BY e.employeeId, e.firstname, e.lastname;

-- View contents
SELECT *
FROM Employee_Performance;

-- 14. Show the distribution of orders geographically by displaying the
-- ShipCountry, the EmployeeID who handled the order,
-- and the frequency (count) of orders for each pair.

SELECT shipCountry, employeeId, COUNT(*) AS OrderFrequency
FROM SalesOrder
GROUP BY shipCountry, employeeId
ORDER BY shipCountry, employeeId;

-- 15. Calculate the Slope (β1) for the relationship between
-- UnitPrice (X) and Quantity (Y) in OrderDetail

SELECT
(
    COUNT(*) * SUM(unitPrice * quantity)
    - SUM(unitPrice) * SUM(quantity)
)
/
(
    COUNT(*) * SUM(unitPrice * unitPrice)
    - POWER(SUM(unitPrice), 2)
) AS Slope_Beta1
FROM OrderDetail;