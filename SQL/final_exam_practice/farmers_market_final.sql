-- -------------------------------- FARMERS_MARKET ----------------------------------
USE farmers_market;

-- 1. Write a query to select all columns from the vendor table to see a complete list of sellers
SELECT *
FROM vendor;

-- 2. Display the customer_first_name and customer_last_name from the customer table,
-- renaming the columns to Given_Name and Surname respectively
SELECT customer_first_name AS Given_Name,
       customer_last_name AS Surname
FROM customer;

-- 3. List all products from the product table, sorted by their product_category_id in descending order
SELECT *
FROM product
ORDER BY product_category_id DESC;

-- 4. Find all records in the customer_purchases table where the cost_to_customer_per_qty
-- is between 2.00 and 5.00
SELECT *
FROM customer_purchases
WHERE cost_to_customer_per_qty BETWEEN 2.00 AND 5.00;

-- 5. List all the distinct market_date values available in the vendor_inventory table
-- to see which days the market was active
SELECT DISTINCT market_date
FROM vendor_inventory;

-- 6. For each customer_id, calculate the total number of items purchased and the total amount
-- spent, naming the columns item_count and total_spent
SELECT customer_id,
       SUM(quantity) AS item_count,
       SUM(quantity * cost_to_customer_per_qty) AS total_spent
FROM customer_purchases
GROUP BY customer_id;

-- 7. Identify the product_id groups in the customer_purchases table that have
-- a total purchased quantity of more than 100 units
SELECT product_id, SUM(quantity) AS item_count
FROM customer_purchases
GROUP BY product_id
HAVING SUM(quantity) > 100;

-- 8. Show the vendor_name and the product_name for all items listed in vendor_inventory
SELECT v.vendor_name, p.product_name
FROM vendor v
INNER JOIN vendor_inventory vi ON v.vendor_id = vi.vendor_id
INNER JOIN product p ON vi.product_id = p.product_id;

-- 9. Retrieve the details of all customers whose customer_last_name contains the
-- letter 'z' as the third character
SELECT *
FROM customer
WHERE customer_last_name LIKE '__z%';

-- 10. In the customer_purchases table, display the customer_id, the quantity,
-- and a calculated column named Tax_Amount which represents 15% of the total cost
SELECT customer_id, quantity, (quantity * cost_to_customer_per_qty * 0.15) AS Tax_Amount
FROM customer_purchases;

-- *******************************************************************************
-- 11. Find the names of all vendors who have never recorded an entry in the vendor_inventory table
SELECT v.vendor_name
FROM vendor v
LEFT JOIN vendor_inventory vi ON v.vendor_id = vi.vendor_id
WHERE vi.vendor_id IS NULL;


-- 12. Perform a LEFT JOIN between the product_category table and the product table
-- to list every category name and its associated products
SELECT pc.product_category_name, p.product_name
FROM product_category pc
LEFT JOIN product p ON pc.product_category_id = p.product_category_id;

-- 13. Create a view named Daily_Revenue_Summary that displays the market_date
-- and the total revenue generated from all customer_purchases on that specific date
CREATE VIEW Daily_Revenue_Summary AS
SELECT market_date, SUM(quantity * cost_to_customer_per_qty) AS total_revenue
FROM customer_purchases
GROUP BY market_date;

-- View contents
SELECT *
FROM Daily_Revenue_Summary;

-- 14. Show the distribution of purchases by displaying the customer_id,
-- the vendor_id, and the frequency of transactions
SELECT customer_id, vendor_id, COUNT(*) AS transaction_frequency
FROM customer_purchases
GROUP BY customer_id, vendor_id;

-- 15. Calculate the Slope (β1) for the relationship between quantity (X)
-- and cost_to_customer_per_qty (Y)
SELECT
(
    COUNT(*) * SUM(quantity * cost_to_customer_per_qty)
    - SUM(quantity) * SUM(cost_to_customer_per_qty)
)
/
(
    COUNT(*) * SUM(quantity * quantity)
    - POWER(SUM(quantity), 2)
) AS slope_beta1
FROM customer_purchases;