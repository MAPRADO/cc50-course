/* Write an SQL query to list the names of the 5 longest songs in descending order of length.
Your query should generate a table with a single column for the name of each song. */

SELECT name FROM songs
ORDER BY duration_ms DESC LIMIT 5;