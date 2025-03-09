# Write your MySQL query statement below
# UNION ALL is preferred over UNION because with UNION, 
# the database engine will attempt to remove duplicates which is an unnecessary and expensive step
with cte as
(select product_id, 'store1' as store, store1 as price
from Products
union all
select product_id, 'store2' as store, store2 as price
from Products
union all
select product_id, 'store3' as store, store3 as price
from Products)

select *
from cte
where price is not null;
