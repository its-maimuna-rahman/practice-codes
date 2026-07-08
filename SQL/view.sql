-- view practice using sakila db
USE sakila;

-- 1. Create a view that shows: customer_id, customer full name (first_name last_name),
-- total number of payments, total amount paid (customers who have made more than 5 payments.)

CREATE VIEW view_customer_pay AS
SELECT c.customer_id,
		CONCAT(c.first_name, ' ', c.last_name) AS full_name,
        COUNT(p.payment_id) AS payment_count,
        SUM(p.amount) AS total_paid
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id, full_name
HAVING COUNT(p.payment_id) > 5; 

SELECT * FROM view_customer_pay;  

-- 2. Create a view that displays: film_id, title, total number of times the film was rented,
-- total revenue generated from that film. Include only films that have been rented at least once.

CREATE VIEW view_film_rental_performance AS
SELECT f.film_id,
	   f.title,
       COUNT(r.rental_id) AS rental_count,
       SUM(p.amount) AS total_revenue
FROM film f
INNER JOIN inventory i ON f.film_id = i.film_id
INNER JOIN rental r ON i.inventory_id = r.inventory_id
INNER JOIN payment p ON r.rental_id = p.rental_id
GROUP BY f.film_id, f.title;

SELECT * FROM view_film_rental_performance;

-- 3. Create a view that shows: store_id, rental month (YYYY-MM format),
-- total revenue for that store in that month, Use payment_date for grouping.
-- Result should be sorted by store and month when queried

CREATE VIEW view_store_monthly_revenue AS
SELECT s.store_id,
	   DATE_FORMAT(p.payment_date, '%Y-%m') AS rental_month,
       SUM(p.amount) AS total_revenue
FROM payment p
INNER JOIN staff s ON p.staff_id = s.staff_id
GROUP BY s.store_id, rental_month;

SELECT * FROM view_store_monthly_revenue
ORDER BY store_id, rental_month;

-- 4. *** Create a view that lists customers who are active, have rented films from more than one store
-- View should include: customer_id, customer name, number of distinct stores rented from

CREATE VIEW view_active_multi_store_customers AS
SELECT
    c.customer_id,
    CONCAT(c.first_name, ' ', c.last_name) AS customer_name,
    COUNT(DISTINCT i.store_id) AS store_count
FROM customer c
JOIN rental r
    ON c.customer_id = r.customer_id
JOIN inventory i
    ON r.inventory_id = i.inventory_id
WHERE c.active = 1
GROUP BY c.customer_id, customer_name
HAVING COUNT(DISTINCT i.store_id) > 1;

SELECT * FROM view_active_multi_store_customers;

-- 5. Create a view that shows: actor_id, actor full name, total number of films acted in
-- average rental rate of those films, Include only actors who acted in 10 or more films

CREATE VIEW view_actor_film_workload AS
SELECT a.actor_id,
	   CONCAT(a.first_name, ' ', a.last_name) AS actor_name,
       COUNT(f.film_id) AS film_count,
       AVG(f.rental_rate) AS avg_rental_rate
FROM actor a
INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
INNER JOIN film f ON fa.film_id = f.film_id
GROUP BY a.actor_id, actor_name
HAVING  COUNT(f.film_id) >= 10;

SELECT * FROM view_actor_film_workload;
