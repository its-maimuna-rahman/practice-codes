-- EXERCISE (FUNCTIONS + JOIN)
USE sakila;

-- 1. Show customer name and total number of rentals made by each customer. Sort by total rentals descending.
SELECT c.first_name, c.last_name, COUNT(r.rental_id) AS rental_count
FROM customer c
INNER JOIN rental r ON c.customer_id = r.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name
ORDER BY COUNT(r.rental_id) DESC; 

-- 2. Retrieve film title, rental rate, and category name for films with a rental rate greater than 2.99.
SELECT f.title, f.rental_rate, c.name AS category_name
FROM film f
INNER JOIN film_category fc ON f.film_id = fc.film_id
INNER JOIN category c ON fc.category_id = c.category_id
WHERE f.rental_rate > 2.99;

-- 3. ***** Display staff name and total payment amount they processed. Only include staff who processed more than 500 payments.
SELECT s.first_name, s.last_name, COUNT(p.payment_id) AS payment_count, SUM(p.amount) AS total_payment
FROM staff s
INNER JOIN payment p ON s.staff_id = p.staff_id
GROUP BY s.staff_id, s.first_name, s.last_name
HAVING COUNT(p.payment_id) > 500;

-- 4. Find the total number of rentals per day. Only show days where rentals are greater than 50.
SELECT DATE(rental_date) AS rental_day, COUNT(rental_id) AS rental_count
FROM rental
GROUP BY DATE(rental_date)
HAVING COUNT(rental_id) > 50;

-- 5. Retrieve customer name and city name for customers who live in Canada.
SELECT c.first_name, c.last_name, ci.city
FROM customer c
INNER JOIN address a ON c.address_id = a.address_id
INNER JOIN city ci ON a.city_id = ci.city_id
INNER JOIN country co ON ci.country_id = co.country_id
WHERE co.country = "Canada";

-- 6. Show category name and the average film length for each category. Order by average length ascending.
SELECT c.name AS category_name, AVG(f.length) AS avg_length
FROM film f
INNER JOIN film_category fc ON f.film_id = fc.film_id
INNER JOIN category c ON fc.category_id = c.category_id
GROUP BY c.name
ORDER BY AVG(f.length) ASC;

-- 7. Retrieve film title and number of times rented. Only include films rented more than 20 times.
SELECT f.title, COUNT(r.rental_id) AS rental_count
FROM film f
INNER JOIN inventory i ON f.film_id = i.film_id
INNER JOIN rental r ON i.inventory_id = r.inventory_id
GROUP BY f.title
HAVING COUNT(r.rental_id) > 20;

-- 8. ********** Show monthly total payment amount (year + month). Order by total amount descending.
SELECT 
    YEAR(payment_date) AS year,
    MONTH(payment_date) AS month,
    SUM(amount) AS total_payment
FROM payment
GROUP BY YEAR(payment_date), MONTH(payment_date)
ORDER BY total_payment DESC;

-- 9. Find customers who have made more than 10 payments and show their total amount paid.
SELECT c.first_name, c.last_name, COUNT(p.payment_id) AS payment_count, SUM(p.amount) AS total_pay
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING COUNT(p.payment_id) > 10;

-- 10. Display the top 5 customers who spent the most money.
SELECT c.first_name, c.last_name, SUM(p.amount) AS total_pay
FROM customer c
INNER JOIN payment p ON c.customer_id = p.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name
ORDER BY SUM(p.amount) DESC
LIMIT 5;
