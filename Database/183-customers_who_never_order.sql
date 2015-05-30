#https://leetcode.com/problems/customers-who-never-order/
#
# Author: Cobblau
# Email: cobblau@gmail.com
#
# Solution
select c.Name as Customers
from Customers c left join Orders orderon c.Id = o.CustomerId
where o.CustomerId is NULL
