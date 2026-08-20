SELECT 
    t2.contest_id,
    ROUND(COUNT(t2.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Users t1
JOIN Register t2
    ON t1.user_id = t2.user_id
GROUP BY t2.contest_id
order by percentage desc , t2.contest_id asc ;