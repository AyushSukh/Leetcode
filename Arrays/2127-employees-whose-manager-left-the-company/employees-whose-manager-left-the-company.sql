# Write your MySQL query statement below
select employee_id
from (
    select employee_id
    from Employees 
    where salary < 30000
    AND manager_id NOT IN (
      SELECT employee_id
      FROM employees
  )
) as sub
order by employee_id ;
