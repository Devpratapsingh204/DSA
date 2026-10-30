-- SELECT u.unique_id, e.name
-- FROM Employees e LEFT JOIN EmployeeUNI u
-- ON e.id=u.id;

select unique_id, name
from Employees e left join EmployeeUNI u on e.id= u.id;