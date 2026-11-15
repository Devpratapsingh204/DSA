-- 1. Employees who only belong to one department
SELECT employee_id, department_id 
FROM Employee 
GROUP BY employee_id 
HAVING COUNT(department_id) = 1

UNION

-- 2. Employees who belong to multiple departments, keeping the primary one
SELECT employee_id, department_id 
FROM Employee 
WHERE primary_flag = 'Y';