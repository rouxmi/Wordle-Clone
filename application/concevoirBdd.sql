--comment concevoir votre BDD ? c'est tout simple

--Installez sqlite3 avant toute chose

--0uvrez un terminal et Allez à l'emplacement où vous voulez votre BDD
--Tapez sqlite3 nomdelaBDD.db
--copiez-collez ces lignes pour créer votre BDD

CREATE TABLE Partie (
    id_partie INT NOT NULL,
    pseudo VARCHAR NOT NULL, 
    date DATE NOT NULL, 
    type_de_jeu VARCHAR, 
    langue VARCHAR, 
    niveau_difficulte INT NOT NULL, 
    nombre_e_max INT NOT NULL,
    mot_a_deviner VARCHAR, 
    nombre_m_tentes INT, 
    m_tentes VARCHAR, 
    victoire INT,
    PRIMARY KEY (id_partie,pseudo),
    CONSTRAINT "check_type_de_jeu" CHECK("type_de_jeu" IN ('jour', 'libre')),
    CONSTRAINT "check_victoire" CHECK("victoire" IN (0,1)),
    CONSTRAINT "check_langue" CHECK("langue" IN ('en', 'fr')),
    CONSTRAINT "check_niveau_difficulte" CHECK("niveau_difficulte" IN (1, 2, 3))
);
CREATE TABLE Joueur (
    pseudo VARCHAR PRIMARY KEY NOT NULL, 
    email VARCHAR NOT NULL, 
    mdp VARCHAR NOT NULL, 
    nombre_parties INT DEFAULT 0
);
CREATE TABLE Mot_du_Jour (
    date_de_la_partie DATE PRIMARY KEY NOT NULL, 
    mot VARCHAR NOT NULL
);

--Votre BDD est vide c'est trop triste
--copiez-collez ces lignes pour remplir votre BDD
--n'hesitez pas à rajouter des lignes pour que la BDD soit remplie au max !
--Table Partie--
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, mot_a_deviner, nombre_m_tentes, m_tentes, victoire) 
    VALUES (1, 'lola', '2022-04-16', 'jour', 'fr', 3,6,'FAIRE', 3, 'CRANE RASER JETER',0);
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, mot_a_deviner, nombre_m_tentes, m_tentes,victoire) 
    VALUES (2, 'lola', '2022-04-16', 'libre', 'fr', 3,6,'arbre', 3, 'CRANE RASER JETER',0);
SELECT id_partie, type_de_jeu,niveau_difficulte, mot_a_deviner, m_tentes FROM Partie WHERE pseudo='lola' and DATE='2022-04-16';--a tester--
UPDATE Partie SET m_tentes='BOIRE POIRE FAIRE' where id_partie=1 AND pseudo='lola';
DELETE FROM Partie WHERE id_partie=1 and pseudo='lola';
--Table Joueur--
INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('lucie', 'lucie.boucher@telecomnancy.eu', 'qzhnjqzhnj', 1;
UPDATE Joueur SET nombre_parties =10 WHERE pseudo='lucie';
DELETE FROM Joueur WHERE pseudo='lucie';
SELECT pseudo FROM Joueur WHERE nombre_parties=3;

--Table Mot_du_Jour
INSERT INTO Mot_du_Jour (date_de_la_partie, mot)
    VALUES ('2022-04-16', 'JETER');
INSERT INTO Mot_du_Jour (date_de_la_partie, mot)
    VALUES ('2022-04-15', 'ARBRE');
UPDATE Mot_du_Jour SET mot='SACHE' WHERE date_de_la_partie='2022-04-16';
DELETE FROM Mot_du_Jour WHERE date_de_la_partie='2022-04-15';


--Remplissage Bdd--
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, mot_a_deviner, nombre_m_tentes, m_tentes, victoire) 
    VALUES (1, 'lucie', '2022-04-29', 'jour', 'fr', 3,6, 'MERCI', 3, ' CRANE PRISE MERCI', 1);

INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, mot_a_deviner, nombre_m_tentes, m_tentes, victoire) 
    VALUES (1, 'boby', '2022-04-29', 'jour', 'fr', 3,6, 'MERCI', 4, 'CRANE PRISE LIVRE MERCI', 1);

INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('boby', 'boby.boucher@telecomnancy.eu', 'qzhnjqzhnj', 1)