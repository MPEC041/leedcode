# Write your MySQL query statement below
select MAX(salary) AS SecondHighestSalary
from Employee 
where salary < (select MAX(salary)FROM Employee  )