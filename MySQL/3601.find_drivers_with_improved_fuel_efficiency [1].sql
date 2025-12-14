# Write your MySQL query statement below
with cte as(
    select driver_id,
    avg(
        case 
        when month(trip_date) between 1 and 6
        then distance_km / fuel_consumed
        end
    ) as first_half_avg,
    avg(
        case 
        when month(trip_date) between 7 and 12
        then distance_km / fuel_consumed
        end
    ) as second_half_avg
    from trips
    group by driver_id
)

select 
cte.driver_id, 
drivers.driver_name, 
round(cte.first_half_avg, 2) as first_half_avg, 
round(cte.second_half_avg, 2) as second_half_avg,
round(cte.second_half_avg - cte.first_half_avg, 2) as efficiency_improvement
from cte inner join drivers
on cte.driver_id = drivers.driver_id
where 
cte.first_half_avg is not null and 
cte.second_half_avg is not null and 
cte.second_half_avg - cte.first_half_avg > 0
order by
efficiency_improvement desc, driver_name asc;

-- do rounding only at the end to prevent rounding errors