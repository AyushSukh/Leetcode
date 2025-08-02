select visited_on,
(
    select sum(amount)
    from Customer
    where visited_on between date_sub(c.visited_on ,INTERVAL 6 DAY )
    and c.visited_on
) as amount ,

round 
((
    select sum(amount)/7
    from Customer
    where visited_on between date_sub(c.visited_on ,INTERVAL 6 DAY )
    and c.visited_on
),2) as average_amount

from Customer c
where visited_on >= (
    select date_Add(min(visited_on) , Interval 6 day)
    from customer
)
group by visited_on
order by visited_on