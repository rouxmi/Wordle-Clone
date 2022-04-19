from flask import Flask, render_template, request, redirect, g, session, jsonify
from flask_session import Session
import sqlite3
import datetime
from mot import * #gestion des dictionnaires

from cesar import * #chifrement mot de passe et mot du jour

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
        

#App route

@app.route("/", methods=["GET", "POST"])
def first():
   #on renvoie la template login lorsque l'utilisateur arrive pour la première fois sur la page login (ici on est en methode GET)
   return render_template("login.html")

#vérification du mots de passe
@app.route('/checkmdp')  
def checkmdp():
    #récupère le mot de passe et le pseudo dans la requête
    pseudo = request.args.get('pseudo') 
    mdp = request.args.get('mdp')
    #vérifie si le mot de passe est le bon renvoie un booléen
    response=checkLogin(pseudo,mdp)[0] 
    #connecte la personne si oui
    if response:
        session['pseudo']=pseudo
    # renvoie la réponse au JS
    message = {'validation':str(response)}
    return jsonify(message)


#vérification de l'inscription
@app.route('/checkinscription')
def checkinscription():
    #récupère les données de l'inscrition dans la requête
    pseudo = request.args.get('pseudo')
    mail = request.args.get('mail')
    mdp = request.args.get('mdp')
    #vérifie si le pseudo ou le mail n'est pas déjâ utilisé et renvoie un booléen
    response=checkRegister(pseudo)[0]
    #inscrit le joueur dans la BD si oui
    if response:
        query ="INSERT INTO Joueur(pseudo, email, mdp, nombre_parties) VALUES (?,?,?,?)"
        query_db(query, (pseudo, mail, crypto(mdp),0))
        session["pseudo"] = pseudo
    #renvoie la réponse au JS
    message = {'validation':str(response)}
    return jsonify(message)

#vérification du mot de passe dans la BD
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

#vérification du mail et du pseudo dans la BD
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
    l1 = []
    l2 = []
    for i in a:
        if i[3]=="mdj":
            l1.append(i)
        else:
            l2.append(i)
    return render_template("historique.html", dataMdj = l1, dataLibre = l2,longueurMdj=len(l1), longueurLibre=len(l2))

#déconnecte le joueur
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
        if libre:
            mode_libre=1
        else:
            mode_libre=0
        nbEssais = int(request.form.get("nbEssais"))
        nbLettres = int(request.form.get("tailleMot"))
<<<<<<< HEAD
        langue=request.form.get("lang")
        print(langue)
    return render_template("jeu.html", nbEssais=nbEssais, tailleMot=nbLettres, libre=mode_libre)
||||||| 5dba4ce
    return render_template("jeu.html", nbEssais=nbEssais, tailleMot=nbLettres, libre=mode_libre)
=======
        niveau=int(request.form.get("niveau"))
    return render_template("jeu.html", nbEssais=nbEssais, tailleMot=nbLettres, libre=mode_libre, niveau=niveau)
>>>>>>> 83e4427feb1292714b180e55970fb26321887afe


@app.route('/regles')
def regles():
    return render_template("regles.html")

#vérification du mot et renvoie de la coloration
@app.route('/checkmot')  
def checkmotp():
    #récuperation des arguements néccesaires
    motadev = session.get("mot")
    lang = request.args.get('lang')
    essais = request.args.get('essais')
    #vérification si le mot existe
    if existe(essais,lang):
        #renvoie la couleur si oui
        couleur=compare(essais,motadev)
        message = {'couleur':str(couleur),'existe':str(True)}
    else:
        #renvoie False sinon 
        message = {'existe':str(False),'couleur':str([])}
    #envoie en json de la réponse au JS
    return jsonify(message)

#renvoie un mot en fonction des paramètres de la partie
@app.route('/getmot')
def getmot():
    #récupère les paramètres de la partie
    mode = request.args.get('mode')
    lang= request.args.get('lang')
    longeur= request.args.get('size')
    #si mot du jour va chercher le mot dans la BD
    if mode=="jour":
        mot_crypt=query_db("SELECT * FROM Mot_du_Jour WHERE date_de_la_partie=?", [datetime.date.today()])[0][1]
        mot_lower=decrypto(mot_crypt)
        mot=mot_lower.upper()
    #si mode libre choix aléatoire dans le dictionnaire 
    elif mode=='libre':
        mot=mot_random(longeur,lang).replace("\n","")
    message = {'mot':str(mot)}
    #inscription du mot dans la session
    session["mot"] = mot
    #renvoie du mot en json au JS
    return jsonify(message)



if __name__=='__main__':
     app.run(debug=1)
