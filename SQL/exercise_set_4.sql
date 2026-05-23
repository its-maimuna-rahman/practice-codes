-- Exercise set 4 --

-- 1 
-- Retrieve customer IDs who made more than 5 payments.
SELECT customer_id, COUNT(payment_id) AS payment_count
FROM payment
GROUP BY customer_id
HAVING COUNT(payment_id) > 5;

-- 2
-- Show rental dates where more than 100 rentals occurred.
SELECT DATE(rental_date) AS rental_date, COUNT(*) AS rental_count
FROM rental
GROUP BY DATE(rental_date)
HAVING COUNT(*) > 100;

-- 3
-- Retrieve each staff ID and the total number of payments processed by them.
SELECT staff_id, COUNT(payment_id) AS payment_count
FROM payment
GROUP BY staff_id

-- 4
-- Show the top 5 rental days by number of rentals.
SELECT DATE(rental_date) AS rental_date, COUNT(*) AS rental_count
FROM rental
GROUP BY DATE(rental_date)
ORDER BY COUNT(*) DESC
LIMIT 5;

-- 5
-- Find the maximum replacement cost for each rating category.
SELECT rating, MAX(replacement_cost) AS max_replacement_cost
FROM film
GROUP BY rating;

-- 6
-- Retrieve the title and rental_rate of all films that cost more than $3 to rent.
SELECT title, rental_rate
FROM film
WHERE rental_rate > 3;

-- 7 *******************************
-- Find how many rentals were made each month.
SELECT 
  YEAR(rental_date) AS year,
  MONTH(rental_date) AS month,
  COUNT(*) AS total_rentals
FROM rental
GROUP BY YEAR(rental_date), MONTH(rental_date)
ORDER BY year, month;

-- 8 ******************************
-- Retrieve the customer names who have made at least one payment on '2005-07-30'.
SELECT DISTINCT c.first_name, c.last_name
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
WHERE DATE(p.payment_date) = '2005-07-30';

-- 9
-- Retrieve the postal code of customer ID 2
SELECT c.first_name, c.last_name, a.postal_code
FROM address a
INNER JOIN customer c ON a.address_id = c.address_id
WHERE c.customer_id = 2;

-- 10
-- Find customer names and total amount paid by customers who spent more than 50.
SELECT c.first_name, c.last_name, SUM(p.amount) AS total_paid
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id
HAVING SUM(p.amount) > 50;
