from flask import Flask, render_template, request, redirect, g, session, jsonify
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
   #on renvoie la template login lorsque l'utilisateur arrive pour la première fois sur la page login (ici on est en methode GET)
   return render_template("login.html")

@app.route('/checkmdp')  
def checkmdp():
    pseudo = request.args.get('pseudo')
    mdp = request.args.get('mdp')
    response=checkLogin(pseudo,mdp)[0]
    if response:
        session['pseudo']=pseudo
    message = {'validation':str(response)}
    return jsonify(message)

@app.route('/checkinscription')
def checkinscription():
    pseudo = request.args.get('pseudo')
    mail = request.args.get('mail')
    mdp = request.args.get('mdp')
    response=checkRegister(pseudo)[0]
    if response:
        query ="INSERT INTO Joueur(pseudo, email, mdp, nombre_parties) VALUES (?,?,?,?)"
        query_db(query, (pseudo, mail, crypto(mdp),0))
        session["pseudo"] = pseudo
    message = {'validation':str(response)}
    return jsonify(message)


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

@app.route("/register", methods=["GET"])
def register():
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

@app.route("/config")
def config():
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
        numniv=a[k][5]
        n=niveau[numniv-1]
        niv.append(n)
    return render_template("historique.html", data = a, nivdujeu=niv,longueur=longueur)


@app.route("/disconnect")
def disconnect():
    session["pseudo"] = None
    return redirect("/")

@app.route("/jeu", methods=["GET", "POST"])
def jeu():
    #Ici on teste si le joueur est identifié ou pas
    if not session.get("pseudo"):
        return render_template("login.html")
    if request.method == "POST":
        #On récupère tout ce qui a été rempli dans le form
        libre = bool(request.form.get("libre"))
        nbEssais = int(request.form.get("nbEssais"))
        nbLettres = int(request.form.get("tailleMot"))
        print(libre,nbEssais,nbLettres)
    return render_template("jeu.html", nbEssais=nbEssais, tailleMot=nbLettres)


if __name__=='__main__':
     app.run(debug=1)
