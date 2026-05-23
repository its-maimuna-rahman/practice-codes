-- ==============================
-- Transaction practice Set-1
-- ==============================

USE practice;

SELECT * FROM bank_accounts;
SELECT * FROM transaction_log;

-- 1. Alicia (109) transfers 700 to Bobby (110)
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 700
WHERE account_id = 109;

UPDATE bank_accounts
SET balance = balance + 700
WHERE account_id = 110;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES 
(109, 'TRANSFER_OUT', 700, NOW(), 'Sent to Bobby'),
(110, 'TRANSFER_IN', 700, NOW(), 'Received from Alicia');

COMMIT;


-- 2. Charles (111) tries to withdraw 1500
-- If balance is insufficient, UPDATE affects 0 rows → ROLLBACK
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 1500
WHERE account_id = 111
  AND balance >= 1500;

ROLLBACK;


-- 3. Daisy (112) deposits 2000, then cancels the operation
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance + 2000
WHERE account_id = 112;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES 
(112, 'DEPOSIT', 2000, NOW(), 'Cash Deposit');

ROLLBACK;


-- 4. Evelyn (113) transfers 1000 to Henry (116)
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 1000
WHERE account_id = 113;

UPDATE bank_accounts
SET balance = balance + 1000
WHERE account_id = 116;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES 
(113, 'TRANSFER_OUT', 1000, NOW(), 'Sent to Henry'),
(116, 'TRANSFER_IN', 1000, NOW(), 'Received from Evelyn');

COMMIT;


-- 5. Georgia (115) withdraws 300 and commits
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 300
WHERE account_id = 115;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES 
(115, 'WITHDRAW', 300, NOW(), 'ATM Withdrawal');

COMMIT;


-- ==============================
-- Transaction practice Set-2
-- ==============================

-- 1. Transfer 1200 from Alicia (109) to Isabella (117)
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 1200
WHERE account_id = 109;

UPDATE bank_accounts
SET balance = balance + 1200
WHERE account_id = 117;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES 
(109, 'TRANSFER_OUT', 1200, NOW(), 'Sent to Isabella'),
(117, 'TRANSFER_IN', 1200, NOW(), 'Received from Alicia');

COMMIT;


-- 2. Withdraw 500 from Jack (118)
-- Rollback if balance goes below 2000
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 500
WHERE account_id = 118
  AND balance - 500 >= 2000;

-- If update affects 0 rows → rollback manually
-- Otherwise commit and insert log

INSERT INTO transaction_log
(account_id, txn_type, amount, txn_date, remarks)
VALUES (118, 'WITHDRAW', 500, NOW(), 'ATM Withdrawal');

COMMIT;


-- 3. Deposit 4000 into Daisy (112)
-- Use SAVEPOINT and rollback only log entry
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance + 4000
WHERE account_id = 112;

SAVEPOINT after_balance_update;

INSERT INTO transaction_log (account_id, txn_type, amount, txn_date, remarks)
VALUES
(112, 'DEPOSIT', 4000, NOW(), 'Large Deposit');

ROLLBACK TO after_balance_update;

COMMIT;


-- 4. Transfer 600 from Bobby (110) to Charles (111)
-- Rollback if either account is Blocked
START TRANSACTION;

UPDATE bank_accounts
SET balance = balance - 600
WHERE account_id = 110
  AND status = 'Active'
  AND EXISTS (
      SELECT 1
      FROM bank_accounts
      WHERE account_id = 111
        AND status = 'Active'
  );

-- If above UPDATE affects 0 rows → rollback manually

UPDATE bank_accounts
SET balance = balance + 600
WHERE account_id = 111;

INSERT INTO transaction_log VALUES
(NULL, 110, 'TRANSFER_OUT', 600, NOW(), 'Sent to Charles'),
(NULL, 111, 'TRANSFER_IN', 600, NOW(), 'Received from Bobby');

COMMIT;


-- 5. Block Franklin (114) and attempt withdrawal, then rollback
START TRANSACTION;

UPDATE bank_accounts
SET status = 'Blocked'
WHERE account_id = 114;

UPDATE bank_accounts
SET balance = balance - 200
WHERE account_id = 114
  AND status = 'Active';

ROLLBACK;
