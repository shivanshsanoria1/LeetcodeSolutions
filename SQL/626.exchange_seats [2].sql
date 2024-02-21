# Write your MySQL query statement below
select 
case
  when id % 2 = 1 and id = total_count then id
  when id % 2 = 1 then id + 1
  else id - 1
end as id, 
student
from Seat,
  (select count(*) as total_count
  from Seat) as T1
order by id asc;
