-- # Write your MySQL query statement below
-- SELECT customer_id, COUNT(visit_id) as count_no_trans 
-- FROM Visits v
-- WHERE NOT EXISTS (
-- 	SELECT visit_id FROM Transactions t 
-- 	WHERE t.visit_id = v.visit_id
-- 	)
-- GROUP BY customer_id


select customer_id, COUNT(visit_id) as count_no_trans
from Visits v
where NOT exists(
    select visit_id from Transactions as t
    where 
    t.visit_id = v.visit_id
)
GROUP BY customer_id