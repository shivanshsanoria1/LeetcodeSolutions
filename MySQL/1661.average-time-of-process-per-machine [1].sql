# Write your MySQL query statement below
select machine_id, round(sum(time_diff)/count(process_id), 3) as processing_time
from
  (select A.machine_id, A.process_id, (B.timestamp - A.timestamp) as time_diff
  from Activity A
  inner join Activity B
  on A.machine_id = B.machine_id and A.process_id = B.process_id 
  and A.activity_type='start' and B.activity_type = 'end') as T1
group by machine_id;