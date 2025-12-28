/*
Enter your query here.
*/
select max(T.totalsalary), count(*)
from (
    select months*salary as totalsalary
    from employee
) as T
group by T.totalsalary
order by T.totalsalary desc 
limit 1;