# Write your MySQL query statement below
with
cte1 as (
    select *
    from performance_reviews
    where employee_id in (
        select employee_id
        from performance_reviews
        group by employee_id
        having count(*) >= 3
    )
),

cte2 as (
    select *,
    row_number() over 
    (partition by employee_id order by review_date desc) as row_num
    from cte1
),

cte3 as (
    select employee_id, rating, row_num
    from cte2
    where row_num <= 3
),

cte4 as (
    select employee_id,
    sum(if(row_num = 1, rating, 0)) as rating1,
    sum(if(row_num = 2, rating, 0)) as rating2,
    sum(if(row_num = 3, rating, 0)) as rating3
    from cte3
    group by employee_id
)

select T2.employee_id, T2.name,
T1.rating1 - T1.rating3 as improvement_score
from cte4 T1 inner join employees T2
on T1.employee_id = T2.employee_id
where 
T1.rating1 > T1.rating2 and T1.rating2 > T1.rating3
order by improvement_score desc, name asc;