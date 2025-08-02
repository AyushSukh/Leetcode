select d.name as Department ,
     e.name as Employee ,
     salary as Salary
from Employee e
inner join Department d
on e.departmentId = d.id
where 3 > (
    select count(distinct(e2.salary))
    from Employee e2
    where e2.salary > e.salary
    and
    e2.departmentId = e.departmentId
)