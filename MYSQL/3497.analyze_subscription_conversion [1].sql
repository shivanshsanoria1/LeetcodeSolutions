# Write your MySQL query statement below
select T1.user_id, T1.trial_avg_duration, T2.paid_avg_duration
from

(select user_id, round(avg(activity_duration), 2) as trial_avg_duration
from useractivity
where activity_type = 'free_trial'
group by user_id) T1

inner join

(select user_id, round(avg(activity_duration), 2) as paid_avg_duration
from useractivity
where activity_type = 'paid'
group by user_id) T2

on T1.user_id = T2.user_id
order by T1.user_id;