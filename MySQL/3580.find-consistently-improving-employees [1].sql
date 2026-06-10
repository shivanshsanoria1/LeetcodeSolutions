# Write your MySQL query statement below
with
cte1 as (
    select *
    row_number() over 
    (partition by employee_id order by review_date desc) as row_num
    from performance_reviews
),

cte2 as (
    select employee_id, rating, row_num
    from cte1
    where row_num <= 3
),

cte3 as (
    select employee_id,
    max(case when row_num = 1 then rating end) as rating1,
    max(case when row_num = 2 then rating end) as rating2,
    max(case when row_num = 3 then rating end) as rating3
    from cte2
    group by employee_id
)

select T2.employee_id, T2.name,
T1.rating1 - T1.rating3 as improvement_score
from cte3 T1 inner join employees T2
on T1.employee_id = T2.employee_id
where 
T1.rating1 > T1.rating2 and T1.rating2 > T1.rating3
order by improvement_score desc, name asc;