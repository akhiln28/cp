# Find the second highest salary sql query

Created Time: Dec 25, 2020 3:50 PM
Last edited time: Feb 18, 2021 7:45 AM
Points: 800
Status: waiting
Tags: de shaw

I can easily solve that using a subquery. like below

```sql
SELECT TOP 1 entries.title
FROM entries
WHERE (((entries.[amount])<(select max(amount) from entries)))
ORDER BY entries.amount DESC;
```