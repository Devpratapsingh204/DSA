-- -- 1. Employees who only belong to one department
-- SELECT employee_id, department_id 
-- FROM Employee 
-- GROUP BY employee_id 
-- HAVING COUNT(department_id) = 1

-- UNION

-- -- 2. Employees who belong to multiple departments, keeping the primary one
-- SELECT employee_id, department_id 
-- FROM Employee 
-- WHERE primary_flag = 'Y';


SELECT employee_id, department_id
FROM (
    SELECT 
        employee_id, 
        department_id, 
        primary_flag,
        COUNT(employee_id) OVER (PARTITION BY employee_id) as dept_count
    FROM Employee
) t
WHERE primary_flag = 'Y' OR dept_count = 1;