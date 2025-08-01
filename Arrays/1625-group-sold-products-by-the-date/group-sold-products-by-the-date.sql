select sell_date , 
    count(distinct product) as num_sold ,
    group_concat( 
            DISTINCT product 
            order by product
            separator ',' 
        )as products
from Activities
    group by sell_date
    order by sell_date , product