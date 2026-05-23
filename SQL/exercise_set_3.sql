-- Exercise set 3: (Using employees database)
USE employees;

-- 1. Display the first name, last name, and hire date of all employees.
SELECT first_name, last_name, hire_date
FROM employees;

-- 2. List all distinct job titles available.
SELECT DISTINCT title
FROM titles;

-- 3. Find the first and last names of employees who were hired after January 1, 2000.
SELECT DATE(hire_date) AS hire_date, first_name, last_name
FROM employees
WHERE DATE(hire_date) > '2000-01-01';

-- 4. Display the first and last names of employees whose last name starts with 'M'.
SELECT first_name, last_name
FROM employees
WHERE last_name LIKE 'M%';

-- 5. Retrieve the employee IDs of the top 10 highest-paid employees. Sort the results in descending order of salary.
SELECT emp_no, salary
FROM salaries
WHERE to_date = '9999-01-01'
ORDER BY salary DESC
LIMIT 10;

-- 6. Find the total number of employees grouped by gender.
SELECT gender, COUNT(*) AS emp_count
FROM employees
GROUP BY gender;

-- 7. Count how many employees were hired in each year.
SELECT YEAR(hire_date), COUNT(*) AS emp_count
FROM employees
GROUP BY YEAR(hire_date);

-- 8. Write a query to display the employee ID, first name, and last name for all employees.
SELECT emp_no, first_name, last_name
FROM employees;

-- 9. Write a query to display the employee ID, job title, and salary of all employees.
SELECT t.emp_no, t.title, s.salary
FROM titles t
INNER JOIN salaries s ON t.emp_no = s.emp_no
WHERE t.to_date = '9999-01-01'
  AND s.to_date = '9999-01-01';


-- 10. Find the average salary of employees grouped by their current job title.
SELECT t.title, AVG(s.salary) AS avg_salary
FROM titles t
INNER JOIN salaries s ON t.emp_no = s.emp_no
WHERE t.to_date = '9999-01-01'
  AND s.to_date = '9999-01-01'
GROUP BY t.title;
