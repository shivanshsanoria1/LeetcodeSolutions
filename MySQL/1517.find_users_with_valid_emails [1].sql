# Write your MySQL query statement below
select *
from Users
where mail regexp '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com';
/*
^[a-zA-Z] : string must start with lower or upper case letter.
[a-zA-Z0-9_.-]* : matches zero or more occurrences of any upper or lower case letter, digit, underscore, period, or dash.
@leetcode\\.com : matches the string @leetcode.com exactly, where the backslash is used to escape the period character 
(as . means any single character in REGEX).
*/