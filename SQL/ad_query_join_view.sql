-- ADVANCE QUERY
USE sakila;

--  Find customer’s name who made payments greater than 11
SELECT first_name, last_name
FROM customer
WHERE customer_id IN (
	SELECT customer_id
	FROM payment
	WHERE amount > 11
);

--  Find store_id that have inventory of the film BUCKET BROTHERHOOD:
-- code 1
SELECT store_id
FROM store
WHERE store_id IN (
	SELECT store_id
	FROM inventory
	WHERE film_id IN (
		SELECT film_id
		FROM film
		WHERE title = 'BUCKET BROTHERHOOD'
	)
);

-- code 2
SELECT DISTINCT store_id
FROM inventory
WHERE film_id IN (
		SELECT film_id
		FROM film
		WHERE title = 'BUCKET BROTHERHOOD'
);

--  Retrieve address of customer id 1
SELECT address
FROM address
WHERE address_id IN (
	SELECT address_id
	FROM customer
	WHERE customer_id = 1
);

--  Find all film’s title rented by customer ID 1: *********** IMP ************
SELECT title
FROM film
WHERE film_id IN (
	SELECT film_id
	FROM inventory
	WHERE inventory_id IN (
		SELECT inventory_id
		FROM rental
		WHERE customer_id = 1
	)
); 

 -- Find all films that were never rented ****** imp ********
SELECT title
FROM film
WHERE film_id IN (
	SELECT film_id
	FROM inventory
	WHERE inventory_id NOT IN (
		SELECT inventory_id
		FROM rental
	)
 );
 
 --   Retrieve all customers who have made payments greater than $7
 SELECT first_name, last_name
 FROM customer
 WHERE customer_id IN (
	 SELECT customer_id
	 FROM payment
	 WHERE amount > 7
 );
 
 --  Get the titles of films rented by a specific customer (customer_id = 5)
SELECT title
FROM film
WHERE film_id IN (
	SELECT film_id
	FROM inventory
	WHERE inventory_id IN (
		SELECT inventory_id
		FROM rental
		WHERE customer_id = 5
	)
);
 
 --  Get customers who have never rented a film
SELECT customer_id
FROM rental
WHERE customer_id NOT IN (
	SELECT customer_id
	FROM inventory
	WHERE film_id IN (
		SELECT film_id
		FROM film
	)
);

-- chatgpt for above code
SELECT customer_id, first_name, last_name
FROM customer
WHERE customer_id NOT IN (
	SELECT DISTINCT customer_id
	FROM rental
);

-- INNER JOIN

--  Find customer’s name who made payments greater than 11:
SELECT customer.first_name, customer.last_name, payment.amount
FROM customer
INNER JOIN payment ON  customer.customer_id = payment.customer_id
WHERE payment.amount > 11;

--  Find store_id that have inventory of the film BUCKET BROTHERHOOD:
SELECT inventory.store_id, film.title
FROM inventory
INNER JOIN film ON inventory.film_id = film.film_id
WHERE title = 'BUCKET BROTHERHOOD';

--  Retrieve address of customer id 1
SELECT customer.first_name, customer.last_name, address.address
FROM address
INNER JOIN customer ON address.address_id = customer.address_id
WHERE customer.customer_id = 1;

--  Find all film’s title rented by customer ID 1: ************ imp *************
SELECT rental.customer_id, film.title
FROM film
INNER JOIN inventory ON film.film_id = inventory.film_id
INNER JOIN rental ON inventory.inventory_id = rental.inventory_id
WHERE rental.customer_id = 1;

-- LEFT JOIN

--  Retrieve the film IDs, titles, and inventory IDs for films with IDs between 13 and 15, including 
-- films that do not have associated inventory records.
SELECT film.film_id, film.title, inventory.inventory_id
FROM film
LEFT JOIN inventory ON film.film_id = inventory.film_id
WHERE film.film_id BETWEEN 13 AND 15;

-- RIGHT JOIN

-- no record for film id 14
SELECT film.film_id, film.title, inventory.inventory_id
FROM film
RIGHT JOIN inventory ON film.film_id = inventory.film_id
WHERE film.film_id BETWEEN 13 AND 15;

-- VIEW (basically creating subtable from existing table)

CREATE VIEW earn AS
SELECT payment_id, payment_date, amount
FROM payment; 

SELECT *
FROM earn;

-- A view for frequently accessed customer payment data in the Sakila dataset
CREATE VIEW customer_payment AS
SELECT customer_id, SUM(amount) AS total_amount
FROM payment
GROUP BY customer_id;

SELECT *
FROM customer_payment;

SELECT *
FROM customer_payment
WHERE customer_id > 100
ORDER BY customer_id DESC
LIMIT 10;




 
 
 
 
 
 
 
 
 