# Write your MySQL query statement below
SELECT 
    t.query_name,
    COALESCE(ROUND(SUM(t.rating / t.position) / COUNT(t.query_name), 2), 0) AS quality,
    COALESCE(
        ROUND(
            COUNT(CASE WHEN t.rating < 3 THEN 1 END) * 100 / COUNT(t.query_name),
            2
        ),
        0
    ) AS poor_query_percentage
FROM Queries t
GROUP BY t.query_name;