# Write your MySQL query statement below
select count(*) as rich_count
from
  (select *
  from 
    (select customer_id
    from Store
    where amount > 500) as T1
  group by customer_id) as T2;
