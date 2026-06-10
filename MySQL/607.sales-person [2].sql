# Write your MySQL query statement below
select SalesPerson.name
from SalesPerson
where SalesPerson.sales_id not in 
(select SalesPerson.sales_id
from SalesPerson
left join Orders 
on SalesPerson.sales_id = Orders.sales_id
left join Company
on Company.com_id = Orders.com_id
where Company.name = 'RED');