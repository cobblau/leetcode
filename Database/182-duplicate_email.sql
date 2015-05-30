# https://leetcode.com/problems/duplicate-emails/
#
# Author: Cobblau
# Email: cobblau@gmail.com
#
Select Email
From Person
GROUP BY Email
Having count(Email) > 1
