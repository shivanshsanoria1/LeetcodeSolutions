# Write your MySQL query statement below
select U.user_id as buyer_id, U.join_date, count(O.order_id) as orders_in_2019
from Users as U
left join 
  (select order_id, buyer_id
  from Orders
  where order_date like '2019%') as O
on U.user_id = O.buyer_id
group by U.user_id;
