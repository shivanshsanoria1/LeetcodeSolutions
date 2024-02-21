# Write your MySQL query statement below
-- A -> prev day and B -> curr day
select B.id 
from Weather A
inner join Weather B
where A.temperature < B.temperature and datediff(B.recordDate, A.recordDate) = 1;