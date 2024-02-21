# Write your MySQL query statement below
select S1.id,
case
  when s1.id % 2 = 1 and S2.id is null then S1.student
  when S1.id % 2 = 1 then S2.student
  when S1.id % 2 = 0 then S3.student 
end as student
from Seat S1
left join Seat S2
on S1.id + 1 = S2.id
left join Seat S3
on S1.id - 1 = S3.id;
