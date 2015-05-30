#Question:https://leetcode.com/problems/combine-two-tables/
#
# Author: Cobblau
# Email: cobblau@gmail.com
#
#Solution:
SELECT p.FirstName, p.LastName, a.City, a.State
FROM Person p
LEFT JOIN Address a
ON p.PersonId = a.PersonId
