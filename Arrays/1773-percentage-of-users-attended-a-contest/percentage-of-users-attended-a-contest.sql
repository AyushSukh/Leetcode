# Write your MySQL query statement below
select r.contest_id , ROUND(COUNT(distinct r.user_id)*100.0 / (select count(*) from Users),2) as percentage
from Register r
group by r.contest_id
order by 
percentage DESC,
contest_id ASC
