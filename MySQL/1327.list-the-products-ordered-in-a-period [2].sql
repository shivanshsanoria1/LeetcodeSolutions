# Write your MySQL query statement below
select P.product_name, sum(O.unit) as unit
from Products as P
inner join Orders as O
on P.product_id = O.product_id
where year(O.order_date) = '2020' and month(O.order_date) = '2'
group by P.product_id
having sum(O.unit) >= 100;
