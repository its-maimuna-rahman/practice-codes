-- 1. *******Retrieve customer first name, last name, and email along with their city name.
SELECT c.first_name, c.last_name, c.email, ci.city
FROM customer c
INNER JOIN address a ON c.address_id = a.address_id
INNER JOIN city ci ON a.city_id = ci.city_id;

-- 2. Show film titles and their language name.
SELECT f.title, l.name AS language
FROM film f
INNER JOIN language l ON f.language_id = l.language_id;

-- 3. Retrieve staff names along with the store ID they work at with address.
SELECT s.first_name, s.last_name, s.store_id, a.address
FROM staff s
INNER JOIN address a ON s.address_id = a.address_id;

-- 4. Find customer names and the total number of rentals made by each customer.
SELECT c.first_name, c.last_name, COUNT(r.rental_id) AS rental_count
FROM customer c
INNER JOIN rental r ON c.customer_id = r.customer_id
GROUP BY customer_id, c.first_name, c.last_name;

-- 5. Display film titles and category names they belong to.
SELECT f.title, c.name AS category_name
FROM film f
INNER JOIN film_category fc ON f.film_id = fc.film_id
INNER JOIN category c ON fc.category_id = c.category_id; 

-- 6. *********** Retrieve customer names who rented a film titled “ACADEMY DINOSAUR”.
SELECT DISTINCT c.first_name, c.last_name
FROM customer c
JOIN rental r     ON c.customer_id = r.customer_id
JOIN inventory i  ON r.inventory_id = i.inventory_id
JOIN film f       ON i.film_id = f.film_id
WHERE f.title = 'ACADEMY DINOSAUR';

-- 7. Show payment ID, amount, payment date, and the customer’s full name.
SELECT CONCAT(c.first_name, ' ' , c.last_name) AS full_name,
	   p.payment_id, p.amount, 
       DATE(payment_date) AS payment_date
FROM payment p
INNER JOIN customer c ON p.customer_id = c.customer_id;

-- 8. Retrieve actor names who acted in the film “FIGHT JAWBREAKER”.
SELECT a.first_name AS actor_first_name, a.last_name actor_last_name
FROM actor a
INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
INNER JOIN film f ON fa.film_id = f.film_id
WHERE f.title = 'FIGHT JAWBREAKER';

-- 9. ********** Find store ID, city, and country for each store.
SELECT s.store_id, ci.city, co.country
FROM store s
INNER JOIN address a ON s.address_id = a.address_id
INNER JOIN city ci ON a.city_id = ci.city_id
INNER JOIN country co ON ci.country_id = co.country_id;

-- 10. Display customer names and total amount paid, but only for customers who made more than 10 payments.
SELECT c.first_name, c.last_name, COUNT(p.payment_id) AS payment_count , SUM(p.amount) AS paid
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING COUNT(p.payment_id) > 10;