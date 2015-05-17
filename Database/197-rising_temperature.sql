# solution 1
SELECT a.Id
FROM Weather a, Weather b
WHERE TO_DAYS(a.Date) - TO_DAYS(b.Date) = 1
AND a.Temperature > b.Temperature;

# solution 2
SELECT w.Id
FROM Weather w
where w.Temperature >
    (select Temperature b from Weather b where TO_DAYS(w.Date) - TO_DAYS(b.Date) = 1);
