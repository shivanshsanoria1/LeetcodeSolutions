# Write your MySQL query statement below
with 
cte1 as
(
  select count(*) as immediate_count
  from Delivery
  where order_date = customer_pref_delivery_date
),
cte2 as
(
  select count(*) as total_count
  from Delivery
)

select round(cte1.immediate_count / cte2.total_count * 100, 2) as immediate_percentage
from cte1, cte2;
