# Write your MySQL query statement below
select D.name as department, E.name as employee, E.salary
from Employee as E
inner join Department as D
on D.id = E.departmentId
where (E.departmentId, E.salary) in
  (select departmentId, max(salary) as max_dept_salary
  from Employee
  group by departmentId);
