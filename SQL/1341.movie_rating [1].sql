# Write your MySQL query statement below
with 
cte1 as
(
  select U.name as results
  from
    (select user_id, count(*) as moviesRated
    from MovieRating
    group by user_id) as T1
  inner join
  Users U
  on T1.user_id = U.user_id
  order by T1.moviesRated desc, U.name asc
  limit 1
),
cte2 as
(
  select M.title as results
  from
    (select movie_id, avg(rating) as avgRating
    from MovieRating
    where created_at between '2020-02-01' and '2020-02-29'
    group by movie_id) as T1
  inner join 
  Movies M
  on T1.movie_id = M.movie_id
  order by T1.avgRating desc, M.title asc
  limit 1
)

select *
from cte1
union all
select *
from cte2;
