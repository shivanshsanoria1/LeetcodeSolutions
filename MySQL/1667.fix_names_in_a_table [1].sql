# Write your MySQL query statement below
# string index starts at 1 instead of 0
select user_id, concat(upper(substr(name, 1, 1)), lower(substr(name, 2))) as name
from Users
order by user_id;