# Write your MySQL query statement below
select machine_id, round(avg(
  case
    when activity_type='start' then -timestamp
    else timestamp
  end
)*2, 3) as processing_time
from Activity
group by machine_id;