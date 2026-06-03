-- sakila practice for finals
USE sakila;
-- 1. Write a query to select all columns from the actor table.
SELECT *
FROM actor;

-- 2. List all the distinct rating values available in the film table.
SELECT DISTINCT rating
FROM film; 

-- 3. Display the first name and last name of all customers in the customer table,
-- sorted alphabetically by their last name.
SELECT first_name, last_name
FROM customer
ORDER BY last_name;

-- 4. Find the titles of all films that have a rental_duration of exactly 6 days.
SELECT title, rental_duration
FROM film
WHERE rental_duration = 6;

-- 5. Retrieve the first names of all customers whose name starts with the letter 'B'.
SELECT first_name, last_name
FROM customer
WHERE first_name LIKE 'B%';

-- 6. Count the total number of rentals made by each customer_id and display the results.
SELECT customer_id, COUNT(*) AS rental_count
FROM rental
GROUP BY customer_id;

-- 7. Identify the rating categories where the average length of the films is greater than 120 minutes.
SELECT rating, AVG(length) AS avg_len
FROM film
GROUP BY rating
HAVING avg_len > 120;

-- 8. Retrieve the first name and last name of each customer along with the total amount they have paid
-- by joining the customer and payment tables.
SELECT c.customer_id, c.first_name, c.last_name, SUM(p.amount) AS total_pay
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id;

-- *****************************************************************************************************
-- 9. Find the titles of all films that have the same language_id as the film titled 'ACADEMY DINOSAUR'.
SELECT title 
FROM sakila.film 
WHERE language_id = (
    SELECT language_id 
    FROM sakila.film 
    WHERE title = 'ACADEMY DINOSAUR'
);

-- 10. Write a query to display all payment_id values and their amounts, converting the amount from
-- USD to BDT using a conversion rate of 120 BDT per USD.
SELECT payment_id, SUM(amount) AS amount_usd, SUM(amount * 120) AS amount_bdt
FROM payment
GROUP BY payment_id;

-- 11. Find the names of all actors who have appeared in films categorized as 'Children'.
-- (This requires joining the actor, film_actor, film_category, and category tables).
SELECT actor.first_name, actor.last_name, c.name
FROM actor
INNER JOIN film_actor fa ON actor.actor_id = fa.actor_id
INNER JOIN film_category fc ON fa.film_id = fc.film_id
INNER JOIN category c ON fc.category_id = c.category_id
WHERE c.name = 'Children';

-- **********************************************************************************************
-- 12. List all film titles and their corresponding inventory_id, including those films that
--  are not currently present in the inventory.
SELECT f.title, i.inventory_id
FROM film f
LEFT JOIN inventory i ON f.film_id = i.film_id;

-- 13. Retrieve the names of customers who have made at least one payment that is
--  higher than the average payment amount of all customers
SELECT c.first_name, c.last_name, SUM(p.amount) AS total_pay
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id
HAVING total_pay > (SELECT AVG(amount) FROM sakila.payment);

-- 14. Create a view named staff_performance that shows each staff member's ID, their first name,
--  and the total revenue (sum of amount) they have processed.
CREATE VIEW staff_performance2 AS
SELECT s.staff_id, s.first_name, SUM(p.amount) AS revenue
FROM staff s
INNER JOIN payment p ON s.staff_id = p.staff_id
GROUP BY s.staff_id;

-- ***************************************************************************************
-- 15. Write a query to show the distribution of rentals across different months and years,
-- displaying the year, the month, and the frequency of rentals for that specific period.
SELECT YEAR(rental_date) AS rent_y, MONTH(rental_date) AS rent_mo, COUNT(*) AS frequency
FROM rental
GROUP BY YEAR(rental_date), MONTH(rental_date);