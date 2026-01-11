# Write your MySQL query statement below
with 
cte1 as
    (select user_id, 
    max(event_id) as max_event_id,
    max(monthly_amount) as max_amount,
    datediff(max(event_date), min(event_date)) as days_as_subscriber
    from subscription_events 
    group by user_id
    having datediff(max(event_date), min(event_date)) >= 60),
cte2 as
    (select user_id
    from subscription_events 
    where event_type = 'downgrade'
    group by user_id)

select 
cte1.user_id,
T1.plan_name as current_plan,
T1.monthly_amount as current_monthly_amount,
cte1.max_amount as max_historical_amount,
cte1.days_as_subscriber
from cte1
inner join cte2
on cte1.user_id = cte2.user_id
inner join subscription_events T1
on cte1.user_id = T1.user_id and cte1.max_event_id = T1.event_id
where 
T1.event_type != 'cancel' and T1.monthly_amount * 2 < cte1.max_amount
order by
cte1.days_as_subscriber desc, cte1.user_id asc;

/*
event_id is used instead of the event_date to find the latest row, 
since each user can have multiple rows for the same event_date
*/