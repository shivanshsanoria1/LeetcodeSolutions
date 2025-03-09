# Write your MySQL query statement below
select Pr.product_id, round(sum(Pr.price*Us.units)/sum(Us.units), 2) as average_price
from Prices as Pr
inner join UnitsSold as Us
on Pr.product_id = Us.product_id
where Us.purchase_date >= Pr.start_date and Us.purchase_date <= Pr.end_date
group by Pr.product_id;
