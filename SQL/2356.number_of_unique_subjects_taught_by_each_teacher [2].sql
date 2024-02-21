# Write your MySQL query statement below
select teacher_id, count(subject_id) as cnt
from
  (select teacher_id, subject_id
  from Teacher
  group by teacher_id, subject_id) as T1
group by teacher_id;