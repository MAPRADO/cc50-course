-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 01 See the column "descripition" in the table "crime_scene_reports"
--SELECT description FROM crime_scene_reports;

-- 02 See the column "year", "month", "day", "street", "descripition", related in the table "crime_scene_reports"
SELECT year, month, day, street, description FROM crime_scene_reports;

--output02.txt

-- 03 Find a relatory the crime scene that match the crime local.
SELECT description FROM crime_scene_reports
WHERE crime_scene_reports.year = 2020 AND crime_scene_reports.month = 7 AND crime_scene_reports.day = 28
AND crime_scene_reports.street = "Chamberlin Street";

--output03.txt

/* Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
Interviews were conducted today with three witnesses who were present at the time —
each of their interview transcripts mentions the courthouse. */
--Time of the crime = 10:15am
--Suspects = 3

-- 04 Finding the names in the "interviews' that was transcript
SELECT name, transcript FROM crime_scene_reports
JOIN interviews ON crime_scene_reports.id = interviews.id
WHERE crime_scene_reports.year = 2020
AND crime_scene_reports.street = "Chamberlin Street";

--output04.txt

--Eugene | Não sei o nome do ladrão, mas foi alguém que eu reconheci. No início desta manhã,
--antes de chegar ao tribunal, estava a passar pelo multibanco da Rua Fifer e vi o ladrão
--a retirar algum dinheiro.
--Miss Irene Adler, Sr. Hosmer Angel, Holmes(ferido num evento à porta da Briony Lodge)

-- 05 Search who withdrew money at the ATM on Fifer Street
/* SELECT name, transaction_type, atm_transactions.account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.person_id = people.id
WHERE atm_transactions.atm_location = "Fifer Street"
AND atm_transactions.year = 2020 AND atm_transactions.month = 7
AND atm_transactions.day = 28 AND atm_transactions.transaction_type = "withdraw"; */

--output05.txt

-- 06 Search who withdrew money at the ATM on Fifer Street
/* SELECT * FROM atm_transactions WHERE atm_location = "Fifer Street"
AND atm_transactions.year = 2020 AND atm_transactions.month = 7
AND atm_transactions.day = 28 AND transaction_type = "withdraw"; */

--output06.txt

-- 07 Search who withdrew money at the ATM on Fifer Street (Based on the second witness)
SELECT people.name, atm_transactions.id, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.atm_location = "Fifer Street"
AND atm_transactions.year = 2020 AND atm_transactions.month = 7
AND atm_transactions.day = 28 AND atm_transactions.transaction_type = "withdraw";

--output07.txt

-- 08 Finding in the interviews the word "courthouse"
SELECT transcript FROM interviews WHERE year = 2020
AND month = 7 AND day = 28 AND transcript LIKE "%courthouse%";

--output08.txt

/* Sometime within ten minutes of the theft, I saw the thief get into a car in the
courthouse parking lot and drive away. If you have security footage from the courthouse parking lot,
you might want to look for cars that left the parking lot in that time frame. */

-- 09 Find the license plate, name and activity (Based on the First Witness)
SELECT courthouse_security_logs.activity, courthouse_security_logs.license_plate, people.name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE courthouse_security_logs.year = 2020 AND courthouse_security_logs.month = 7
AND courthouse_security_logs.day = 28 AND courthouse_security_logs.hour = 10
AND courthouse_security_logs.minute >= 15
AND courthouse_security_logs.minute <= 25;

--output09.txt

-- 10 - Phone call of > 1 minute (Based on the third Witness - 1)

-- Add two columns in the table "phone_calls"
/* ALTER TABLE phone_calls
ADD caller_name text;

ALTER TABLE phone_calls
ADD receiver_name text; */

-- Update the columns in the table "phone_calls" adding the name in the table "people"
UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;

--output10.txt

-- Tomorrow's First Flight 7/29/20, Out of Fiftville(City) - destination (Based on the third Witness - 2)
UPDATE flights
SET origin_airport_id = airports.city
FROM airports
WHERE flights.origin_airport_id = airports.id;

UPDATE flights
SET destination_airport_id = airports.city
FROM airports
WHERE flights.destination_airport_id = airports.id;

SELECT flights.id, hour, minute, origin_airport_id, destination_airport_id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;

--output10.txt

-- Suspected of purchasing the flight ticket to "London"(Based on the third Witness - 3)
SELECT flights.destination_airport_id, people.name, phone_number, license_plate FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id = 36
ORDER BY flights.hour ASC;

/* Thief: 			Ernest(367)555-5533
Accomplice: 		Berthold (375)555-8161
Thief escaped to:	London */