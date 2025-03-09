# Write your MySQL query statement below
select round(T1.immediate_count / T2.total_count * 100, 2) as immediate_percentage
from
(select count(*) as immediate_count
from Delivery
where order_date = customer_pref_delivery_date) as T1
join
(select count(*) as total_count
from Delivery) as T2;
