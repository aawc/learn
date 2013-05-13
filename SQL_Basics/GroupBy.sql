--SELECT * FROM person;
--SELECT * FROM pet;
--SELECT * FROM person_pet;

--UPDATE person SET first_name = "Zed"
--	WHERE person.first_name != "Zed";
--SELECT * FROM person;

--DELETE FROM person_pet;
--INSERT INTO person_pet (person_id, pet_id) VALUES (0, 1);
--SELECT * FROM person_pet;

UPDATE pet SET name = "Zed's Pet" WHERE id IN (
	SELECT pet.id
	FROM pet, person_pet, person
	WHERE
		person.id = person_pet.person_id AND
		pet.id = person_pet.pet_id AND
		person.first_name = "Zed"
);

SELECT * FROM pet;