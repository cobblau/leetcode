# https://leetcode.com/problems/duplicate-emails/
Select Email
From Person
GROUP BY Email
Having count(Email) > 1
