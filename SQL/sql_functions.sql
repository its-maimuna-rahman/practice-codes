USE sakila;

-- function practice

-- avegrage

-- 1.
SELECT AVG(rental_duration) AS avg_rental_duration
FROM sakila.film;
-- 2.
SELECT AVG(amount) AS average_amount
FROM sakila.payment;

-- minimum

-- 1.
SELECT MIN(rental_rate) AS min_rent_rate
FROM sakila.film;
-- 2.
SELECT MIN(length) AS min_length
FROM sakila.film;

-- maximum

-- 1.
SELECT MAX(length) AS longest
FROM sakila.film;
-- 2.
SELECT MAX(rental_rate) AS max_rent_rate
FROM sakila.film;

-- sum

-- 1.
SELECT SUM(amount) AS total_rev
FROM sakila.payment;
-- 2.
SELECT SUM(rental_duration) AS total_rental
FROM sakila.film;

-- count

-- 1.
SELECT COUNT(*) AS total_rentals
FROM sakila.rental
WHERE rental_id = 1;
-- 2.
SELECT COUNT(*) AS total_rentals
FROM sakila.rental
WHERE rental_id = 5;

-- group by statement

-- 1.
SELECT rental_id, COUNT(*) AS total_rentals
FROM sakila.rental
GROUP BY rental_id;

-- 2.
SELECT staff_id, SUM(amount) AS total_payment
FROM sakila.payment
GROUP BY staff_id;

-- 3. average rental duration for each rating
SELECT rating, AVG(rental_duration) AS avg_rent_duration
FROM sakila.film
GROUP BY rating;

-- 4. total payment made at each day
SELECT DATE(payment_date) AS payment_day, SUM(amount) AS total_payment
FROM sakila.payment
GROUP BY DATE(payment_date);

-- 5. Count number of rental grouped by year
SELECT YEAR(rental_date), COUNT(*) AS num_of_rental
FROM sakila.rental
GROUP BY YEAR(rental_date);

-- 6. Count the number of rentals processed by each staff
SELECT staff_id, COUNT(*) AS num_of_rental
FROM rental
GROUP BY staff_id;

-- 7. Calculate the total payment made by each customer
SELECT customer_id, SUM(amount) AS total_payment
FROM sakila.payment
GROUP BY customer_id;

-- 8. Calculate total payment amount grouped by year
SELECT YEAR(payment_date), SUM(amount) AS total_payment
FROM sakila.payment
GROUP BY YEAR(payment_date);

-- filtering data (using HAVING function)

 -- 1. Count the total number of films rented by each customer and filter out customers who rented less than 40 films.
 SELECT customer_id, COUNT(*) AS num_of_rentals
 FROM rental
 GROUP BY customer_id
 HAVING num_of_rentals < 40
 ORDER BY num_of_rentals ASC;
 
 -- 2. Find customers with total payment greater than $100
 SELECT customer_id, SUM(amount) AS tot_pay
 FROM payment
 GROUP BY customer_id
 HAVING tot_pay > 100;

-- 3. Find rentals dates with more than 50 rentals ******************
SELECT DATE(rental_date) AS rent_date, COUNT(*) AS rentals
FROM rental
GROUP BY DATE(rental_date)
HAVING rentals > 50;

-- 4. Find payment dates with total payment greater than $500
SELECT DATE(payment_date) AS payment_date, SUM(amount) AS total_payment
FROM payment
GROUP BY DATE(payment_date)
HAVING total_payment > 500;

-- 5. Find film ids with average rental duration greater than 5 days ******************** PROB
SELECT film_id, AVG(rental_duration) AS rent_dur
FROM film
GROUP BY film_id
HAVING rent_dur > 5;

-- 6. Find inventory ids rented less than 2 times ************* PROBBBBBBBB
SELECT inventory_id, COUNT(*) AS num_invt_id
FROM inventory
GROUP BY inventory_id
HAVING num_invt_id < 2;