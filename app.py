from flask import Flask, render_template, request, redirect, g, session
from flask_session import Session
import sqlite3
import datetime

from cesar import *

app = Flask(__name__)

#Gestion de sessions

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


#Flask et SQLite
#Les fonctions get_db(), close_connection() et query_db() ont été récuperées sur https://flask.palletsprojects.com/en/2.0.x/patterns/sqlite3/

DATABASE = 'BDD.db'

def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
    return db

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

def query_db(query, args=(), one=False):
    cur = get_db().execute(query, args)
    rv = cur.fetchall()
    cur.close()
    get_db().commit()
    return (rv[0] if rv else None) if one else rv
        

@app.route("/", methods=["GET", "POST"])
def first():
    #Ici on teste si le joueur est identifié ou pas, si il ne l'est pas on renvoie la template first et si il l'est on renvoie la template main
    if request.method == "POST":
        #On récupère le pseudo et le mot de passe qui ont été écrit dans le form
        pseudo = request.form.get("pseudo")
        mdp = request.form.get("mdp")

        #si une des deux cases est vide, on renvoie la template login avec un message
        if not pseudo or not mdp:
            return render_template("login.html", message="Il faut remplir toutes les cases")
        #On verifie que toute les conditions sont remplies pour se connecter
        verif = checkLogin(pseudo, mdp)
        
        #si les conditions sont remplies, on créé une session en associant l'email à une session flask
        if verif[0]:
            session["pseudo"] = pseudo
            return redirect("/config")
        #sinon on renvoie la template login avec un message
        else:
            return render_template("login.html", message=verif[1])
    #on renvoie la template login lorsque l'utilisateur arrive pour la première fois sur la page login (ici on est en methode GET)
    return render_template("login.html")

def checkLogin(pseudo, mdp):
    """
    checkLogin
    @param pseudo, mdp deux strings  
    @return un couple composé d'un booléan et d'un string
    checkLogin verifie si le mot de passe correspond au pseudo dans la base de données 
    et verifie que l'habitant ai moins de 3 problèmes ou suggestions modérés
    """
    for row in query_db("SELECT mdp FROM Joueur WHERE pseudo=:pseudo", {"pseudo": pseudo}):

        if mdp==decrypto(row[0]):
            return (True, "")
    return (False, "Mauvais mot de passe ou pseudo")

@app.route("/register", methods=["GET", "POST"])
def register():
    #la methode est POST lorsque le joueur à appuyer sur le bouton 'S'inscrire'
    if request.method == "POST":
        #On récupère tout ce qui a été rempli dans le form
        email = request.form.get("email")
        mdp = request.form.get("mdp")
        mdpconfirm = request.form.get("confirmationmdp")
        pseudo = request.form.get("pseudo")
        if mdp != mdpconfirm:
            return render_template("inscription.html", message="La confirmation du mot de passe ne correspond pas au mot de passe")
        #On crypte le mot de passe
        mdp = crypto(mdp)
        #On verifie qu'aucune case du form était vide, si c'est le cas, on renvoie l'utilisateur sur le form avec un message d'erreur
        if not email or not mdp or not pseudo:
            return render_template("inscription.html", message="Il faut remplir toutes les cases")
        #On appelle check register pour savoir si le pseudo n'est pas deja dans la base de données
        if checkRegister(pseudo)[0]:
            #Si toute les conditions sont remplies, on inscrit l'utilisateur à l'application et on le connecte
            query ="INSERT INTO Joueur(pseudo, email, mdp, nombre_parties) VALUES (?,?,?,?)"
            query_db(query, (pseudo, email, mdp,0))
            session["pseudo"] = pseudo
            return redirect("/config")
    #on renvoie la template register lorsque l'utilisateur arrive pour la première fois sur la page register (ici on est en methode GET)
    return render_template("inscription.html")

def checkRegister(pseudo):
    """
    checkRegister
    @param pseudo string
    @return un couple composé d'un booléan et d'un string
    checkRegister verifie si le pseudo donné en parametre n'est pas deja dans la base de données
    """
    for row in query_db("SELECT pseudo FROM Joueur"):
        if pseudo==row[0]:
            return (False, "Pseudo deja utilisé")
    return (True, "")

@app.route("/config", methods=["GET", "POST"])
def config():
    if request.method == "POST":
        #On récupère tout ce qui a été rempli dans le form
        nbEssais = request.form.get("nbEssais")
        nbLettres = request.form.get("nbLettres")
    #Ici on teste si le joueur est identifié ou pas
    if not session.get("pseudo"):
        return render_template("login.html")
    return render_template("config.html")

@app.route("/mesinfos")
def mesinfos():
    if not session.get("pseudo"):
       return redirect("/")
    a = query_db("SELECT * FROM Joueur WHERE pseudo=:pseudo", {"pseudo": session.get("pseudo")})
    b=decrypto(a[0][2])
    return render_template("mesinfos.html",infos = a[0], password = b)

@app.route("/historique")
def historique():
    if not session.get("pseudo"):
        return redirect("/")
    a= query_db("SELECT * FROM Partie WHERE pseudo=:pseudo", {"pseudo":session.get("pseudo")})
    niveau=["Facile", "Moyen", "Difficile"]
    niv=[]
    longueur=len(a)
    for k in range (longueur):
        numniv=a[k][4]
        n=niveau[numniv-1]
        niv.append(n)
    return render_template("historique.html", data = a, nivdujeu=niv,longueur=longueur)


@app.route("/disconnect")
def disconnect():
    session["pseudo"] = None
    return redirect("/")

@app.route("/jeu")
def jeu():
    return render_template("jeu.html", nbEssais=6, tailleMot=4)

if __name__=='__main__':
     app.run(debug=1)
