SELECT today.id
FROM Weather as yesterday 
JOIN Weather as today

WHERE DATEDIFF(today.recordDate,yesterday.recordDate) = 1
    AND today.temperature > yesterday.temperature
;