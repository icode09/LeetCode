# Write your MySQL query statement below
select dept.name as Department, e.name as Employee , e.salary as Salary
from Employee e inner join Department dept
on e.departmentId = dept.id
where Salary = (select max(salary) from Employee e2 where e2.departmentId = dept.id)