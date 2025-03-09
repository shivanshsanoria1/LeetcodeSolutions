# Write your MySQL query statement below
select P.product_id, P.product_name
from Sales as S
inner join Product as P 
on S.product_id = P.product_id
group by product_id
having min(S.sale_date) >= '2019-01-01' and max(S.sale_date) <= '2019-03-31';
