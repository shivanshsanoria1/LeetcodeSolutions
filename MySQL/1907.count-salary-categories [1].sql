with 
cte1 as
  (select 'Low Salary' as category, 0 as accounts_count
  from Accounts
  union
  select 'Average Salary' as category, 0 as accounts_count
  from Accounts
  union
  select 'High Salary' as category, 0 as accounts_count
  from Accounts),
cte2 as 
  (select
  case
    when income < 20000 then 'Low Salary'
    when income <= 50000 then 'Average Salary'
    else 'High Salary'
  end as category,
  count(account_id) as accounts_count
  from Accounts
  group by category)

select T1.category, ifnull(T2.accounts_count, 0) as accounts_count
from (select * from cte1) as T1
left join
(select * from cte2) as T2
on T1.category = T2.category;
