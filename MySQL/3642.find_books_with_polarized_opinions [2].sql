# Write your MySQL query statement below
with 
cte as
(select 
book_id, 
max(session_rating) - min(session_rating) as rating_spread,
round(
    (sum(if(session_rating <= 2, 1, 0)) + sum(if(session_rating >= 4, 1, 0))) 
    / count(*), 2) as polarization_score
from reading_sessions
group by book_id
having 
count(*) >= 5 and 
max(session_rating) >= 4 and min(session_rating) <= 2)

select 
books.book_id,
books.title, 
books.author, 
books.genre, 
books.pages,
cte.rating_spread,
cte.polarization_score
from cte inner join books
on cte.book_id = books.book_id
order by polarization_score desc, title desc;