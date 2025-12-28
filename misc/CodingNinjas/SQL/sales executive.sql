select name
from Salesperson
where name not in
    (select S.name
    from Salesperson S
    inner join Orders O
    on S.sales_id = O.sales_id
    inner join Company C
    on O.com_id = C.com_id
    where C.name = 'RED');
