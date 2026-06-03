-- -------------------- EMPLOYEES DB ---------------------------------
USE employees;

-- 1. Write a query to display the first name, last name, and hire date 
-- of all employees in the employees table
SELECT first_name, last_name, hire_date
FROM employees;

-- 2. List all the distinct job titles available from the titles table
SELECT DISTINCT title
FROM titles;

-- 3. Display all data from the salaries table, sorted by salary amount in descending order
SELECT *
FROM salaries
ORDER BY salary DESC;

-- 4. Find the first and last names of all employees who were hired after January 1, 2000
SELECT first_name, last_name, DATE(hire_date) AS hire_day
FROM employees
WHERE DATE(hire_date) > '2000-01-01';

-- 5. Retrieve the details of all employees whose last name starts with the letter 'M'
SELECT *
FROM employees
WHERE last_name LIKE 'M%';

-- 6. Calculate the average salary of employees grouped by their current job title
SELECT t.title, AVG(s.salary) AS avg_salary
FROM salaries s
INNER JOIN titles t ON s.emp_no = t.emp_no
GROUP BY t.title;

-- 7. Identify the department IDs (dept_no) that have more than 10,000 employees assigned to them
SELECT dept_no, COUNT(*) AS dept_emp_count
FROM dept_emp
GROUP BY dept_no
HAVING dept_emp_count > 10000;

-- 8. Retrieve the first name, last name, and current salary of the top 10 highest-paid male employees
SELECT e.first_name, e.last_name, e.gender, s.salary 
FROM employees e 
INNER JOIN salaries s ON e.emp_no = s.emp_no 
WHERE e.gender = 'M' 
ORDER BY s.salary DESC 
LIMIT 10;

-- 9. Find the names of employees who earn a salary higher than the overall average salary of the company
SELECT e.first_name, e.last_name, s.salary
FROM employees e
INNER JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.salary > (SELECT AVG(salary) FROM salaries);

-- 10. Display employee IDs and their annual salaries converted into a
-- monthly amount (Salary / 12), naming the column monthly_pay
SELECT emp_no, (salary / 12) AS monthly_pay
FROM salaries;

-- 11. List the first name and last name of all employees currently working as managers
-- in the 'Marketing' department.
SELECT e.first_name, e.last_name, d.dept_name
FROM employees e
INNER JOIN dept_manager dm ON e.emp_no = dm.emp_no
INNER JOIN departments d ON dm.dept_no = d.dept_no
WHERE d.dept_name = 'Marketing';

-- 12. Perform a LEFT JOIN to list all department names and their associated employees,
--  ensuring that departments with no employees are still included in the result
SELECT d.dept_name, de.emp_no
FROM departments d
LEFT JOIN dept_emp de ON d.dept_no = de.dept_no;

-- 13. Create a view named department_stats that displays the department name,
-- the total number of employees, and the total salary expenditure for each department
CREATE VIEW department_stats AS
SELECT d.dept_name, COUNT(de.emp_no) AS emp_count, SUM(s.salary) AS sal_exp
FROM departments d
INNER JOIN dept_emp de ON d.dept_no = de.dept_no
INNER JOIN salaries s ON de.emp_no = s.emp_no
GROUP BY d.dept_name;
SELECT * FROM department_stats;

-- 14. Write a query to show the distribution of employees by gender across different years
-- of hiring, displaying the hire year, gender, and the frequency (count) for each pair
SELECT YEAR(hire_date) AS hire_year, gender, COUNT(*) AS freq 
FROM employees 
GROUP BY hire_year, gender 
ORDER BY hire_year DESC, gender;

-- 15. Using the mathematical formulas provided in the sources, write a SQL expression
-- to calculate the slope (β1) for the relation ship between employee hire dates
-- (represented as years) and their current salary
SELECT 
(COUNT(*) * SUM((YEAR(hire_date)) * salary) - SUM((YEAR(hire_date))) * SUM(salary)) /
(COUNT(*) * SUM((YEAR(hire_date)) * (YEAR(hire_date))) - POW(SUM((YEAR(hire_date))) , 2))
AS b1
FROM employees e
INNER JOIN salaries s ON e.emp_no = s.emp_no;