from cesar import *
import sqlite3
import datetime
from mot import mot_random

#onnection à la base de donnée
bd=sqlite3.connect("BDD.db")
curseur=bd.cursor()
#date du jour
tod = datetime.date.today()

#supprime les données actuelles
curseur.execute("DELETE FROM Mot_du_Jour")
bd.commit()

#boucle de 300
for i in range(300):
    #calcul la date dans i jours
    d = datetime.timedelta(days = -i)
    a = tod - d
    #prend un mot random
    mot=mot_random(5,"fr").replace("\n","")
    mot_crypt=crypto(str(mot))
    #ajoute le mot dans la BD
    curseur.execute("INSERT INTO Mot_du_Jour (date_de_la_partie,mot) VALUES (?,?)",(str(a),mot_crypt))
    bd.commit()
#fermeture de la BD
bd.close()
    