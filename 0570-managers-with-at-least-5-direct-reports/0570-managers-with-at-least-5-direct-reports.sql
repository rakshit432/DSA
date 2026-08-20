SELECT t1.name
FROM Employee t1
JOIN Employee t2
    ON t1.id = t2.managerId
GROUP BY t1.id, t1.name
HAVING COUNT(t2.id) >= 5;