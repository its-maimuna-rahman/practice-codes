-- ----------------------- Table MAKING -------------------------
USE practice_db;
-- b
CREATE TABLE Customer(
	
    customer_id SMALLINT UNSIGNED,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20) NOT NULL,
    phone_number VARCHAR(14) NOT NULL UNIQUE,
    city VARCHAR(30),
    join_date DATE,
    CONSTRAINT pk_customer PRIMARY KEY(customer_id)
);

-- c
CREATE TABLE Plan(

	customer_id  SMALLINT UNSIGNED,
    plan_id  SMALLINT UNSIGNED,
    plan_type ENUM('Prepaid', 'Postpaid', 'Hybrid'),
    CONSTRAINT pk_plan PRIMARY KEY(plan_id),
    CONSTRAINT fk_plan_customer FOREIGN KEY(customer_id) REFERENCES Customer(customer_id)
);

-- d
SET foreign_key_checks = 0;
ALTER TABLE Customer
MODIFY customer_id SMALLINT UNSIGNED AUTO_INCREMENT;
SET foreign_key_checks = 1;

-- e
INSERT INTO Customer(customer_id, first_name, last_name, phone_number, city, join_date)
VALUES
(null, 'Ayesha', 'Rahman', '01711112233', 'Dhaka', '2023-11-21'),
(null, 'Rifat', 'Hossain', '01888887777', 'Chittagong', '2023-11-15');

-- f
START TRANSACTION;
UPDATE Customer
SET city = 'Sylhet'
WHERE customer_id = 1;
SELECT * FROM Customer;

-- g
ROLLBACK;

-- h
COMMIT;

-- i
CREATE INDEX idx_cus_name ON Customer(first_name, last_name);

-- j
DELETE FROM Customer
WHERE customer_id = 2;

-- k
DROP TABLE Plan;
DROP TABLE Customer;
