# Write your MySQL query statement below
select id, sum(friends_count) as num
from
  (select requester_id as id, count(accepter_id) as friends_count
  from RequestAccepted
  group by requester_id
  union all
  select accepter_id as id, count(requester_id) as friends_count
  from RequestAccepted
  group by accepter_id) as T1
group by id
order by num desc
limit 1;
