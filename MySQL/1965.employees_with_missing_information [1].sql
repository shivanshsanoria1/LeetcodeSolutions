# Write your MySQL query statement below
with cte as
(select E.employee_id, E.name, S.salary
from Employees as E
left join Salaries as S
on E.employee_id = S.employee_id
union
select S.employee_id, E.name, S.salary
from Employees as E
right join Salaries as S
on E.employee_id = S.employee_id)

select employee_id
from cte
where name is null or salary is null
order by employee_id;
