# Write your MySQL query statement below
select round(100*avg(is_first_order_immediate), 2) as immediate_percentage
from
  (select 
  if(min(order_date) = min(customer_pref_delivery_date),1,0) as is_first_order_immediate
  from Delivery
  group by customer_id) as T1;
