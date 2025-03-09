# Write your MySQL query statement below
select U.name, sum(T.amount) as balance
from Transactions as T
inner join Users as U
on T.account = U.account
group by T.account
having sum(T.amount) > 10000;
