# Write your MySQL query statement below
SELECT p.product_id , IFNULL(ROUND(SUM(units * price) / sum(units),2),0) AS average_price
from Prices p
LEFT JOIN UnitsSold u
on p.product_id = u.product_id
and u.purchase_date between start_date and end_date
group by product_id
