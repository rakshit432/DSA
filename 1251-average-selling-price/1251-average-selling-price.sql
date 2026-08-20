SELECT 
    t1.product_id,
    COALESCE(
        ROUND(SUM(t1.price * t2.units) / SUM(t2.units), 2),
        0
    ) AS average_price
FROM Prices AS t1
LEFT JOIN UnitsSold AS t2
    ON t1.product_id = t2.product_id
    AND t2.purchase_date >= t1.start_date
    AND t2.purchase_date <= t1.end_date
GROUP BY t1.product_id;