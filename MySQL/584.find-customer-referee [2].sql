# Write your MySQL query statement below
-- if referee_id is null, replace it with -1
select name
from Customer
where ifnull(referee_id, -1) != 2;