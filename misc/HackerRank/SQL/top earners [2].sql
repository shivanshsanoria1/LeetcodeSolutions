/*
Enter your query here.
*/
select max(months*salary), count(*)
from employee
group by months*salary
order by months*salary desc 
limit 1;