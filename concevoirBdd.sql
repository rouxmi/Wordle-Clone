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
    nombre_m_tentes INT, 
    m_tentes VARCHAR, 
    PRIMARY KEY (id_partie,pseudo),
    CONSTRAINT "check_type_de_jeu" CHECK("type_de_jeu" IN ('mdj', 'libre')),
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

INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('lucie', 'lucie.boucher@telecomnancy.eu', 'qzhnjqzhnj', 5);

INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('remi', 'remi.bourdais@telecomnancy.eu', 'wjrnwjrn', 0);

INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('lola', 'lola.montignier@telecomnancy.eu', 'qtqfqtqf', 1);

INSERT into Joueur (pseudo, email, mdp, nombre_parties) 
    VALUES ('fromath', 'mathilde.bard@telecomnancy.eu', 'kwtrfymkwtrfym', 0);

INSERT INTO Mot_du_Jour (date_de_la_partie, mot)
    VALUES ('2022-04-16', 'jeter');

INSERT INTO Mot_du_Jour (date_de_la_partie, mot)
    VALUES ('2022-04-15', 'arbre');

INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (1, 'lola', '2022-04-16', 'mdj', 'fr', 3, 6, 3, 'crane raser jeter');
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (1, 'lucie', '2022-04-16', 'mdj', 'fr', 3, 6, 4, 'crane raser raque jeter');
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (2, 'lucie', '2022-04-16', 'libre', 'en', 1, 6, 4, 'coucou bonjou acajou');
INSERT into Partie (id_partie, pseudo, date, type_de_jeu, langue, niveau_difficulte, nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (3, 'lucie', '2022-04-15', 'mdj', 'fr', 3, 8, 2, 'crane arbre');

INSERT INTO Partie(id_partie, pseudo, date, type_de_jeu, langue,niveau_difficulte,nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (4,'lucie','2022-03-23','mdj', 'fr', 3, 6, 2, 'coucou luciee');
INSERT INTO Partie(id_partie, pseudo, date, type_de_jeu, langue,niveau_difficulte,nombre_e_max, nombre_m_tentes, m_tentes) 
    VALUES (5,'lucie',2022-03-23,'libre', 'en', 3, 6, 2, 'coucou luciee');
