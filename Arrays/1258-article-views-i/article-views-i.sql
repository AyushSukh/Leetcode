# Write your MySQL query statement below
select distinct author_id AS id
from Views
where author_id = viewer_id
order by author_id ASC;