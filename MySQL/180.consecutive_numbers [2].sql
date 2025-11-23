# Write your MySQL query statement below
select distinct A.num as ConsecutiveNums
from Logs A, Logs B, Logs C
where A.num = B.num and B.num = C.num and A.id + 1 = B.id and B.id + 1 = C.id;
