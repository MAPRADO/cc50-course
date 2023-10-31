/* write a SQL query that lists the names of songs that feature "feat." (participation) by other artists.
Songs that feature other artists will include "feat." in the song name.
Your query should generate a table with a single column for each song name. */

SELECT songs.name FROM songs WHERE songs.name LIKE '%feat.%';

