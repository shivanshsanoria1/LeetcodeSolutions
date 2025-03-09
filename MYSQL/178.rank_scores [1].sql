# Write your MySQL query statement below
select S1.score, 
  (select count(distinct S2.score)
  from Scores S2
  where S2.score >= S1.score) as 'rank'
from Scores S1
order by S1.score desc;
