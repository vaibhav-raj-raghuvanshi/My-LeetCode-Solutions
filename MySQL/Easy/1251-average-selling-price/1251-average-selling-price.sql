# Write your MySQL query statement below
SELECT p.product_id, ROUND(IFNULL(SUM(p.price * u.units) / sum(u.units), 0), 2) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id 
AND u.purchase_date >= p.start_date and
u.purchase_date <= p.end_date
GROUP BY p.product_id