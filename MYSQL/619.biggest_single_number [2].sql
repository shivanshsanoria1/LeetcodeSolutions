# Write your MySQL query statement below
select max(num) as num
from
  (select num, count(num) as freq
  from MyNumbers
  group by (num)) as T1
where T1.freq = 1;