--SELECT person.first_name, pet.name FROM pet, person

--INSERT INTO pet (id, name, breed, age, dead) VALUES
--	(1, "kutta", "canine", 3, 0);
--INSERT INTO pet (id, name, breed, age, dead) VALUES
--	(3, "billi", "pussy", 5, 0);
--INSERT INTO pet (id, name, breed, age, dead) VALUES
--	(2, "chuha", "rat", 6, 0);
--INSERT INTO person (id, first_name, last_name, age) VALUES
--	(5, "kamina", "insaan", 26);

SELECT person.first_name, pet.name FROM pet, person
	WHERE pet.id = person.id;

SELECT * FROM pet INNER JOIN person
	ON pet.id = person.id;

SELECT * FROM pet LEFT JOIN person
	ON pet.id = person.id;

SELECT * FROM person LEFT JOIN pet
	ON pet.id = person.id;