select round(sum(tiv_2016) , 2) AS tiv_2016
from Insurance
where tiv_2015 IN (
    select tiv_2015
    from Insurance
    group by tiv_2015
    having count(*) > 1
) and (lat,lon) IN
(
    select lat,lon
    from Insurance
    group by lat,lon
    having count(*) = 1
)