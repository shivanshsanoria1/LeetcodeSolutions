# Write your MySQL query statement below
with 
cte1 as
(
  select U.name as results
  from Users U
  inner join MovieRating MR
  on U.user_id = MR.user_id
  group by U.user_id
  order by count(MR.movie_id) desc, U.name asc
  limit 1
),
cte2 as
(
  select M.title as results
  from Movies M 
  inner join MovieRating MR
  on M.movie_id = MR.movie_id
  where MR.created_at between '2020-02-01' and '2020-02-29'
  group by M.movie_id
  order by avg(MR.rating) desc, M.title asc
  limit 1
)

select *
from cte1
union all
select *
from cte2;
