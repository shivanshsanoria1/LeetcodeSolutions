# Write your MySQL query statement below
select St.student_id, St.student_name, Su.subject_name, count(Ex.subject_name) as attended_exams
from Students as St
cross join Subjects as Su
left join Examinations as Ex
on St.student_id = Ex.student_id and Su.subject_name = Ex.subject_name
group by St.student_name, Su.subject_name
order by St.student_id, Su.subject_name;
