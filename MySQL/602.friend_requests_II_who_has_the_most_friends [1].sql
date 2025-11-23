# Write your MySQL query statement below
with cte as
(select id, sum(friends_count) as friends_count
from 
  (select requester_id as id, count(accepter_id) as friends_count
  from RequestAccepted
  group by requester_id
  union all
  select accepter_id as id, count(requester_id) as friends_count
  from RequestAccepted
  group by accepter_id) as T1
group by id)

select id, friends_count as num
from cte
where friends_count = 
  (select max(friends_count) from cte);
