# Write your MySQL query statement below
select max(A.salary) as SecondHighestSalary
from Employee A
inner join Employee B
on A.salary < B.salary;