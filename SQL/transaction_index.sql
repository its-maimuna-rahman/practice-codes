-- practicing transaction

CREATE DATABASE practice;
USE practice;


-- new table
CREATE TABLE bank_accounts008 (
    account_id INT PRIMARY KEY,
    account_name VARCHAR(50),
    balance DECIMAL(10,2)
);

INSERT INTO bank_accounts008 (account_id, account_name, balance) VALUES
(101, 'Alice', 1000),
(102, 'Bob', 1500),
(103, 'Charlie', 2000),
(104, 'David', 2500);

SELECT *
FROM bank_accounts008;

--  Alice (101) wants to transfer $300 to Bob (102).
START TRANSACTION;

-- deduct 300 from alice
UPDATE bank_accounts008
SET balance = balance - 300
WHERE account_id = 101;

-- add 300 to bob
UPDATE bank_accounts008
SET balance = balance + 300
WHERE account_id = 102;

-- if everything's correct, commit
COMMIT;


--  Charlie tries to withdraw $5000, but he doesn’t have enough balance. We can use ROLLBACK to prevent invalid transactions
START TRANSACTION;

-- attempt to withdraw
UPDATE bank_accounts008
SET balance = balance - 5000
WHERE account_id = 103;

-- checking the table
SELECT * FROM bank_accounts008;

-- balance is in minus, incorrect, need to go back by rollback
-- Before commit ofc, and this is individual command
ROLLBACK;


-- David withdraws $100, but later we cancel adding money to Alice.
START TRANSACTION;

-- david withdraws 100
UPDATE bank_accounts008
SET balance = balance - 100
WHERE account_id = 104;

-- this is correct, saving this change temporarily before commit, to prevent rollback
SAVEPOINT before_seconed_change;

-- now adding money to alice
UPDATE bank_accounts008
SET balance = balance + 100
WHERE account_id = 101;

-- for some reason, we need to cancel tranfer to alice
ROLLBACK TO before_seconed_change;

-- Now this is final change, commiting
COMMIT;

--  We decide not to use the savepoint anymore.
START TRANSACTION;

UPDATE bank_accounts008
SET balance = balance - 100
WHERE account_id = 104;
SAVEPOINT before_seconed_change;

UPDATE bank_accounts008
SET balance = balance + 100
WHERE account_id = 101;

-- releasing savepoint
RELEASE SAVEPOINT before_seconed_change;

COMMIT;




-- INDEXING
--  Create an index on account_name to speed up searches by name.
CREATE INDEX bank_name ON bank_accounts008(account_name);

SELECT * FROM bank_accounts008
WHERE account_name = 'Alice';


-- If queries involve both name and balance, a Composite Index can optimize performance
 CREATE INDEX idx_name_balance ON bank_accounts008(account_name, balance);
 
 SELECT *
 FROM bank_accounts008
 WHERE balance > 2000;
 
 DROP INDEX bank_name ON bank_accounts008;
