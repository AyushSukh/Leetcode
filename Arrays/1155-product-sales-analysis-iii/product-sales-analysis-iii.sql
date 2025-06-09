select product_id , 
year as first_year , quantity , price
from Sales
where (product_id, year) IN (
    SELECT product_id , MIN(year) as year
    From Sales
    group by product_id
);