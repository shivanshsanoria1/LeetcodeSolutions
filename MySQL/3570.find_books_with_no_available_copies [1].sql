# Write your MySQL query statement below
select 
lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, 
br.current_borrowers
from library_books lb inner join 
	(select 
	book_id, count(*) as current_borrowers
	from 
	borrowing_records 
	where return_date is null
	group by book_id) br
on lb.book_id = br.book_id and lb.total_copies = br.current_borrowers
order by br.current_borrowers desc, lb.title asc;