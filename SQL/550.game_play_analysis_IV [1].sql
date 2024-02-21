# Write your MySQL query statement below
select round(count(T1.player_id)/count(distinct A.player_id), 2) as fraction
from Activity as A
left join 
  (select player_id, min(event_date) as first_event_date
  from Activity
  group by player_id) as T1
on A.player_id = T1.player_id and datediff(A.event_date, T1.first_event_date) = 1;
