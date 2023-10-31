/* Write an SQL query that returns the average energy of Drake songs.
Your query should generate a table with a single column and a single row containing the average energy.
You should not make assumptions about what Drake's artist_id is. */

/* SELECT AVG(energy) FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = "Drake"; */

SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Drake");