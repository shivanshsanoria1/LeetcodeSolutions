# Write your MySQL query statement below
select B.employee_id, B.name, 
count(A.employee_id) as reports_count, 
round(avg(A.age)) as average_age
from Employees A
inner join Employees B
on A.reports_to = B.employee_id
group by B.employee_id
order by B.employee_id;