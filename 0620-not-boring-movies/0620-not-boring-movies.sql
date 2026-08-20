SELECT t.id,t.movie,t.description,t.rating
FROM Cinema AS t
WHERE t.id % 2 != 0
  AND t.description != 'boring'
ORDER BY t.rating DESC;