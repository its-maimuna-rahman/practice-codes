-- creating 2 table, for practicing view and indec, later will be used to practice transactions.
-- table 1 : bank_accounts table for customers' info record
-- table 2 : transaction_log for keeping record for transactions.
USE practice;

-- bank_accounts table
CREATE TABLE bank_accounts (
    account_id INT PRIMARY KEY,
    account_name VARCHAR(50),
    email VARCHAR(100),
    account_type VARCHAR(20),
    branch VARCHAR(50),
    balance DECIMAL(10,2),
    status VARCHAR(10),
    created_at DATE
);

INSERT INTO bank_accounts VALUES
(101, 'Alice', 'alice@gmail.com', 'Savings', 'Dhaka', 5000, 'Active', '2023-01-10'),
(102, 'Bob', 'bob@gmail.com', 'Savings', 'Dhaka', 2000, 'Active', '2023-02-15'),
(103, 'Charlie', 'charlie@gmail.com', 'Current', 'Chittagong', 800, 'Active', '2023-03-20'),
(104, 'David', 'david@gmail.com', 'Savings', 'Khulna', 3000, 'Active', '2023-04-05'),
(105, 'Eva', 'eva@gmail.com', 'Current', 'Rajshahi', 12000, 'Active', '2023-05-18'),
(106, 'Frank', 'frank@gmail.com', 'Savings', 'Dhaka', 400, 'Blocked', '2023-06-01'),
(107, 'Grace', 'grace@gmail.com', 'Savings', 'Sylhet', 9000, 'Active', '2023-07-11'),
(108, 'Hannah', 'hannah@gmail.com', 'Current', 'Dhaka', 1500, 'Active', '2023-08-25');

INSERT INTO bank_accounts VALUES
(109, 'Alicia', 'alicia@gmail.com', 'Savings', 'Dhaka', 6500, 'Active', '2023-09-01'),
(110, 'Bobby', 'bobby@gmail.com', 'Current', 'Chittagong', 4200, 'Active', '2023-09-03'),
(111, 'Charles', 'charles@gmail.com', 'Savings', 'Khulna', 900, 'Active', '2023-09-06'),
(112, 'Daisy', 'daisy@gmail.com', 'Savings', 'Sylhet', 15000, 'Active', '2023-09-08'),
(113, 'Evelyn', 'evelyn@gmail.com', 'Current', 'Rajshahi', 7000, 'Active', '2023-09-10'),
(114, 'Franklin', 'franklin@gmail.com', 'Savings', 'Dhaka', 300, 'Blocked', '2023-09-12'),
(115, 'Georgia', 'georgia@gmail.com', 'Savings', 'Barisal', 11000, 'Active', '2023-09-14'),
(116, 'Henry', 'henry@gmail.com', 'Current', 'Dhaka', 2500, 'Active', '2023-09-16'),
(117, 'Isabella', 'isabella@gmail.com', 'Savings', 'Rangpur', 4800, 'Active', '2023-09-18'),
(118, 'Jack', 'jack@gmail.com', 'Savings', 'Sylhet', 5200, 'Active', '2023-09-20');

SELECT * FROM bank_accounts;

-- transaction_log table
CREATE TABLE transaction_log (
    txn_id INT AUTO_INCREMENT PRIMARY KEY,
    account_id INT,
    txn_type VARCHAR(20),
    amount DECIMAL(10,2),
    txn_date DATETIME,
    remarks VARCHAR(100)
);


-- view practice (from bank_accounts table)

-- 1. Create a view showing account_name, branch, balance for Active accounts only.
CREATE VIEW active_accounts AS
SELECT account_name, branch, balance, status
FROM bank_accounts
WHERE status = 'Active';
SELECT * FROM active_accounts;

-- 2. Create a view of accounts with balance > 5000.
CREATE VIEW high_balance AS 
SELECT *
FROM bank_accounts
WHERE balance > 5000;
SELECT * FROM high_balance;

-- 3. Create a view showing branch-wise total balance.
CREATE VIEW branch_balance AS
SELECT branch, SUM(balance) AS total_balance
FROM bank_accounts
GROUP BY branch;
SELECT * FROM branch_balance;

-- 4. **** Create a view combining bank_accounts and transaction_log.
CREATE VIEW transaction_history AS
SELECT b.account_name, t.txn_type, t.amount, t.txn_date
FROM bank_accounts b
JOIN transaction_log t ON b.account_id = t.account_id;
SELECT * FROM transaction_history; 

-- 5. Create a view showing Blocked accounts only and try querying it.
CREATE VIEW blocked_accounts AS
SELECT * FROM bank_accounts
WHERE status = 'Blocked';
SELECT * FROM blocked_accounts;

-- Index practice (from bank_accounts table)

-- 1. Create an index on branch. Test with a WHERE branch = 'Dhaka' query.
CREATE INDEX idx_branch ON bank_accounts(branch);

SELECT * FROM bank_accounts
WHERE branch = 'Dhaka';

-- 2. Create an index on balance. Query accounts with balance > 5000.
CREATE INDEX idx_balance ON bank_accounts(balance);

SELECT * FROM bank_accounts
WHERE balance > 5000;

-- 3. Create a composite index on (account_type, balance).
CREATE INDEX idx_type_balance
ON bank_accounts(account_type, balance);

-- 4. Drop an index (create first).
CREATE INDEX idx_acc_id ON bank_accounts(account_id);
DROP INDEX idx_acc_id ON bank_accounts;

-- index does not exist 
SELECT * FROM idx_acc_id;
