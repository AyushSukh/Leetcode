# Write your MySQL query statement below
select u.unique_id , e.name
from Employees e
Left Join EmployeeUNI u
ON e.id = u.id;