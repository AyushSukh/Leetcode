select product_name , sum(unit) as unit 
from Products inner join Orders using(product_id)
where month(order_date) = 02 and year(order_date) = 2020
group by product_name
having unit >= 100