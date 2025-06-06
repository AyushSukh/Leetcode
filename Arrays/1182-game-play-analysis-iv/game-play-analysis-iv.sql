# Write your MySQL query statement below
select
 ROUND(
    COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity),
    2
  ) AS fraction
from Activity a
join (
    select player_id , min(event_date) as first_login
    from Activity
    Group BY player_id
) first_login
ON a.player_id = first_login.player_id
and a.event_date = DATE_ADD(first_login.first_login, INTERVAL 1 day)