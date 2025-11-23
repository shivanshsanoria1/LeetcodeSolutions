# Write your MySQL query statement below
select max(A.salary) as SecondHighestSalary
from employee A
inner join employee B
on A.salary < B.salary;