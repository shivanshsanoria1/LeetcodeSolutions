# Write your MySQL query statement below
with cte as
(select *
from Employee
where (departmentId, salary) in
  (select departmentId, max(salary) as max_dept_salary
  from Employee
  group by departmentId)
)

select D.name as department, E.name as employee, E.salary
from Department as D
inner join cte as E
on D.id = E.departmentId;
