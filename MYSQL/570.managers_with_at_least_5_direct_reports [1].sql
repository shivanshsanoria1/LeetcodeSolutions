# Write your MySQL query statement below
select B.name
from Employee A
inner join Employee B
on A.managerId = B.id
group by B.id
having count(A.id) >= 5;