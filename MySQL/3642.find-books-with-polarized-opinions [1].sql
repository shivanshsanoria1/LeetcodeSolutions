# Write your MySQL query statement below
with 

cte1 as
    (select book_id, count(*) as polarized_score_count 
    from reading_sessions
    where session_rating <= 2 or session_rating >= 4
    group by book_id),

cte2 as
    (select 
    book_id, 
    max(session_rating) - min(session_rating) as rating_spread,
    count(*) as score_count
    from reading_sessions
    group by book_id
    having count(*) >= 5 and max(session_rating) >= 4 and min(session_rating) <= 2)

select 
cte1.book_id,
books.title, 
books.author, 
books.genre, 
books.pages,
cte2.rating_spread,
round(cte1.polarized_score_count / cte2.score_count, 2) as polarization_score
from cte1 inner join cte2 inner join books
on cte1.book_id = cte2.book_id and cte2.book_id = books.book_id
where cte1.polarized_score_count >= 0.6 * cte2.score_count
order by polarization_score desc, title desc;