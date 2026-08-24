# Write your MySQL query statement below
select t.name 
from Customer t 
where referee_id != 2 OR referee_id IS null ;