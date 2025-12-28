/*
Enter your query here.
*/
select distinct city
from station
where substring(city, 1, 1) 
not in ('a', 'e', 'i', 'o', 'u');