# Write your MySQL query statement below
select euni.unique_id,e.name
from employees as e 
left join EmployeeUNI as euni
ON e.id = euni.id ;