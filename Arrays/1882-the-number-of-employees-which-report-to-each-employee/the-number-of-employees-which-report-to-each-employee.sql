# Write your MySQL query statement below
select m.employee_id , m.name , COUNT(e.employee_id) AS reports_count , 
ROUND (AVG(e.age),0) as average_age
from Employees m
join
Employees e on m.employee_id = e.reports_to
group by 
m.employee_id , m.name
order by 
m.employee_id;
