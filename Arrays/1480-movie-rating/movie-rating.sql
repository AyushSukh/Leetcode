(select name as results
from MovieRating
join Users
using ( user_id )
group by user_id
order by COUNT(rating) DESC , name
LIMIT 1)

union all

( select title as results
from MovieRating
join Movies
using(movie_id)
where month(created_at) = '02' and year(created_at) = '2020'
group by movie_id
order by avg(rating) DESC , title
limit 1 )

