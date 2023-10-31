/* Write an SQL query to list the names of all the songs in ascending order of rhythm.
Your query should generate a table with a single column for the name of each song. */

SELECT name FROM songs
ORDER BY tempo;