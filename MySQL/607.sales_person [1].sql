# Write your MySQL query statement below
select SalesPerson.name
from SalesPerson
left join 
(select Orders.sales_id
from Company
inner join Orders
on Company.com_id = Orders.com_id
where Company.name = 'RED') as CompanyOrders
on SalesPerson.sales_id = CompanyOrders.sales_id
where CompanyOrders.sales_id is null;