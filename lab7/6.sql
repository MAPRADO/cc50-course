/* Write an SQL query that lists the names of Post Malone's songs.
Your query should generate a table with a single column for the name of each song.
You should not make assumptions about what Post Malone's artist_id is. */

SELECT songs.name FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = "Post Malone";

/* -- Example of a nested query :
SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Post Malone"); */