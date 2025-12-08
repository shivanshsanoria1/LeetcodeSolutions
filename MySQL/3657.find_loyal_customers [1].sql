# Write your MySQL query statement below
with 

cte1 as 
(select customer_id, 
count(transaction_type) as total_transactions
from customer_transactions
group by customer_id
having 
count(transaction_id) >= 3 
and 
datediff(max(transaction_date), min(transaction_date)) >= 30),

cte2 as 
(select customer_id, 
count(transaction_type) as refund_transactions
from customer_transactions
where transaction_type = 'refund'
group by customer_id)

select cte1.customer_id
from cte1 left join cte2
on cte1.customer_id = cte2.customer_id
where 
ifnull(cte2.refund_transactions, 0) * 5 < cte1.total_transactions
order by cte1.customer_id asc;