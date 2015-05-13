#https://leetcode.com/problems/customers-who-never-order/

# Cobbliu's solution
select c.Name as Customers
from Customers c left join Orders orderon c.Id = o.CustomerId
where o.CustomerId is NUL
