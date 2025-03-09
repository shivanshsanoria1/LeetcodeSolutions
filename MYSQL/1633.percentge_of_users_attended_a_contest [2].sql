# Write your MySQL query statement below
with TotalUsers as
(select count(user_id) as user_count 
from Users)

select contest_id, round(100*count(contest_id)/user_count, 2) as percentage
from Register, TotalUsers
group by contest_id
order by percentage desc, contest_id asc;