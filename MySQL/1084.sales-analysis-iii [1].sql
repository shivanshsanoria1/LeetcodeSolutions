# Write your MySQL query statement below
select distinct P.product_id, P.product_name
from Sales as S
inner join Product as P 
on S.product_id = P.product_id
where S.product_id not in
  (select distinct product_id
  from Sales
  where sale_date not between '2019-01-01' and '2019-03-31');
