# https://leetcode.com/problems/employees-earning-more-than-their-managers/
#
# Author: Cobblau
# Email: cobblau@gmail.com
#
select e1.Name as Employee
from Employee e1
left join Employee e2
on e1.ManagerId = e2.Id
where e1.Salary > e2.Salary;
