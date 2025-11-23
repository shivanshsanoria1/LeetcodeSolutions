# Write your MySQL query statement below
select S.user_id, 
ifnull(round(avg(if(C.action='confirmed',1,0)), 2), 0) as confirmation_rate
from Signups as S
left join Confirmations as C
on S.user_id = C.user_id
group by S.user_id;
