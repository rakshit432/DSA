# Write your MySQL query statement below
select t2.unique_id , t1.name 
from EmployeeUNI  t2 
right join Employees t1 
on t1.id = t2.id
