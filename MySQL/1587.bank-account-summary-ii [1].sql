# Write your MySQL query statement below
select U.name, T1.balance
from Users as U
inner join
  (select account, sum(amount) as balance
  from Transactions
  group by account) as T1
on U.account = T1.account
where T1.balance > 10000;
