# Write your MySQL query statement below
# use sum() instead of count() here for some reason !!
select P.product_id, P.product_name
from Sales as S
inner join Product as P 
on S.product_id = P.product_id
group by S.product_id
having sum(S.sale_date < '2019-01-01')=0 and sum(S.sale_date > '2019-03-31')=0;
