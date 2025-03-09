# Write your MySQL query statement below
select P.product_id,
case
  when min(P.change_date) > '2019-08-16' then 10
  else (
    select new_price
    from Products as P1
    where change_date <= '2019-08-16' and P1.product_id = P.product_id
    order by change_date desc
    limit 1
  )
end as price
from Products as P
group by product_id;
