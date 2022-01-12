# Write your MySQL query statement below
select C.name,C.population,C.area 
from World as C
where C.population >= 25000000 or C.area >= 3000000