# Write your MySQL query statement below
with 
T1 as 
(select customer_id, count(transaction_type) as total_transactions
from customer_transactions
group by customer_id
having 
count(transaction_id) >= 3 
and 
datediff(max(transaction_date), min(transaction_date)) >= 30),

T2 as 
(select customer_id, count(transaction_type) as refund_transactions
from customer_transactions
where transaction_type = 'refund'
group by customer_id)

select T1.customer_id
from
T1 left join T2
on T1.customer_id = T2.customer_id
where 
ifnull(T2.refund_transactions, 0) * 5 < T1.total_transactions
order by
T1.customer_id asc;