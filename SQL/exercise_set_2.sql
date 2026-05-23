-- Exercise set 2 --
USE sakila;

-- 1
-- Find all rentals made in 2005 but exclude those made in May.
SELECT rental_id, rental_date
FROM rental
WHERE YEAR(rental_date) = 2005 AND MONTH(rental_date) != 5;

-- 2
-- Find all movies that are neither rated G nor PG
SELECT film_id, title, description, rating
FROM film
WHERE rating NOT IN ('G', 'PG');

-- 3
-- Find the staff ID and the total number of rentals processed by each staff member.
SELECT staff_id, COUNT(*) AS total_rentals
FROM rental
GROUP BY staff_id;

-- 4
-- Find the store ID and the total number of films available in each store.
SELECT store_id, COUNT(film_id) AS total_films
FROM inventory
GROUP BY store_id;

-- 5 *******************
-- Find rental dates with more than 100 rentals
SELECT DATE(rental_date) AS rental_date, COUNT(*) AS total_rentals
FROM rental
GROUP BY DATE(rental_date)
HAVING COUNT(*) > 100;


-- 6
-- Find actors who have acted in more than 20 films
SELECT actor_id, COUNT(film_id) AS total_films
FROM film_actor
GROUP BY actor_id
HAVING COUNT(film_id) > 20;

-- 7
-- Find customers who spent more than $200 on rentals
SELECT customer_id, SUM(amount) AS total_amount
FROM payment
GROUP BY customer_id
HAVING SUM(amount) > 200;

-- 8
-- Convert the total payment amount for each customer
-- from USD to BDT using a conversion rate of 120 BDT per USD. Display customer ID,
-- total payment in USD, and total payment in BDT.

SELECT customer_id,
	   SUM(amount) AS total_payment_USD,
       SUM(amount) * 120 AS total_payment_BDT
FROM payment
GROUP BY customer_id;  

-- 9
-- Retrieve a list of films that are rated "R" (Restricted) or "NC-17" (Adults Only),
-- as these films cannot be rented by youth customers. Display the results in two columns:
-- title and rating, sorted alphabetically by title.

 SELECT title, rating
 FROM film
 WHERE rating IN ('R', 'NC-17')
 ORDER BY title ASC;

-- 10
-- Retrieve the title, rental_rate, and length of films from the film table.
-- Sort the results in descending order of rental_rate, and if multiple films have the same rental rate,
-- sort them by length in ascending order.

SELECT title, rental_rate, length
FROM film
ORDER BY rental_rate DESC, length ASC;

-- 11
-- Retrieve the title, description, and release_year of films from the film table.
--  Sort the results alphabetically by title, and display only the first 10 films.

SELECT title, description, release_year
FROM film
ORDER BY title ASC
LIMIT 10;

-- 12
-- Find inventory ids rented less than 2 times
SELECT inventory_id, COUNT(rental_id) AS rental_count
FROM rental
GROUP BY inventory_id
HAVING COUNT(rental_id) < 2;
