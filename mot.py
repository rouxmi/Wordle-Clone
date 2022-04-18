import random

#selection du dictionnaire en fonction de la lang et du nombre de lettre
def dictionnaire(num,lang):

    #si francais
    if lang=="fr":
        #ouverture du dictionnaire
        fichier= open("Dictionnaires/fr_dictionnaire"+str(num)+".txt",'r')
    #si anglais
    else:
        #ouverture du dictionnaire
        fichier= open("Dictionnaires/en_dictionnaire"+str(num)+".txt",'r')
    #lecture du dictionnaire
    mots=fichier.readlines()
    fichier.close()
    return mots

#choix d'un mot random dans le dictionnaire
def mot_random(num,lang):
    mot=random.choice(dictionnaire(num,lang))
    return mot

#focntion vérifiant si un mot existe
def existe(mot,lang):
    num=len(mot)
    #lis le dictionnaire adaptée à la langue et la longeur du mot
    mots= dictionnaire(num,lang)
    #si le mot est dedans retourne True
    if mot+"\n" in mots:
        return True
    #sinon False
    return False

#fonction de coloration du mot
def compare(essai,mot):
    #on initialise toute nos variables
    n=len(essai) #longueur du mot
    couleur,coul=[0]*n,{0:[],1:[],2:[]} #couleur est le vecteur à renvoyer, coul est la liste des lettres ayant comme coloration 0,1,2
    lettre_essais,lettre_mot={},{} #dictionnaire du nombre d'apparition des lettres dans le mot et l'essais
    comp={} #compteur des lettres déja traités
    
    #comptage des lettres et coloration
    L=[] #liste de coloration des lettres
    for j in range(n):
        L.append(donne_couleur(essai,mot,j)) #première coloration lettre par lettre
        coul[L[j]]+=[(essai[j],j)] #ajout compteur suivant 0,1,2

        #stockage de la lettre dans le dictionnaire de l'essais
        if essai[j] not in lettre_essais: 
            lettre_essais[essai[j]]=1
        #lettre déjà vu
        else:
            lettre_essais[essai[j]]+=1

        #stockage de la lettre dans le dictionnaire du mot
        if mot[j] not in lettre_mot:
            lettre_mot[mot[j]]=1
        #lettre déjà vu
        else:
            lettre_mot[mot[j]]+=1
    
    #gestion des lettres bien placé (déja bon/2)
    for l in coul[2]:
        #inscription dans le vecteur final
        couleur[l[1]]=2
        #rajout des lettres dans le compteur comme étant traité
        if essai[l[1]] not in comp:
            comp[essai[l[1]]]=1
        else:
            comp[essai[l[1]]]+=1

    #gestion des autres lettres mal placés (1)
    #passe par toute les lettres
    for j in range(n):

        if L[j]!=2:#test de si elle n'est pas déja bien placé 

            #si elle est mal placé
            if (essai[j],j) in coul[1]:

                #première occurence de la lettre dans le traitement et elle est bien dans le mot 
                if essai[j] not in comp and essai[j] in lettre_mot:
                    couleur[j]=1
                    #ajout au compteur
                    comp[essai[j]]=1

                #la lettre a déja était traité on vérifie qu'elle apparait plus de fois dans le mot à trouver  
                elif comp[essai[j]]<lettre_mot[essai[j]]:
                    couleur[j]=1
                    #ajout au compteur
                    comp[essai[j]]+=1

                #sinon ca reste à 0
    #retourne le vecteur
    c=""
    for i in couleur:
        c+=str(i)
    return c

#fonction de coloration d'une lettre
def donne_couleur(essai,mot,j):
    #la lettre est bien placé à la jème position
    if essai[j]== mot[j]:
        return 2
    #la lettre existe ailleurs dans le mot
    elif essai[j] in mot[:j]+mot[j+1:]:
        return 1
    #la lettre n'y est pas
    else:
        return 0

