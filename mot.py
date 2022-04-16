import random

def dictionnaire(num,lang):

    if lang=="fr":
        fichier= open("Dictionnaires/fr_dictionnaire"+str(num)+".txt",'r')
    else:
        fichier= open("Dictionnaires/en_dictionnaire"+str(num)+".txt",'r')
    mots=fichier.readlines()
    fichier.close()
    return mots

def mot_random(num,lang):
    mot=random.choice(dictionnaire(num,lang))
    return mot


def existe(mot,lang):
    print(mot)
    num=len(mot)
    mots= dictionnaire(num,lang)
    if mot+"\n" in mots:
        return True
    return False

def compare(essai,mot):
    n=len(essai)
    couleur,coul=[0]*n,{0:[],1:[],2:[]}
    lettre_essais,lettre_mot={},{}
    comp={}
    L=[]
    for j in range(n):
        L.append(donne_couleur(essai,mot,j))
        coul[L[j]]+=[(essai[j],j)]
        if essai[j] not in lettre_essais:
            lettre_essais[essai[j]]=1
        else:
            lettre_essais[essai[j]]+=1
        if mot[j] not in lettre_mot:
            lettre_mot[mot[j]]=1
        else:
            lettre_mot[mot[j]]+=1
    for l in coul[2]:
        couleur[l[1]]=2
        if essai[l[1]] not in comp:
            comp[essai[l[1]]]=1
        else:
            comp[essai[l[1]]]+=1
    for j in range(n):
        if L[j]!=2:
            if (essai[j],j) in coul[1]:
                if essai[j] not in comp and essai[j] in lettre_mot:
                    couleur[j]=1
                elif comp[essai[j]]<lettre_mot[essai[j]]:
                    couleur[j]=1
                    comp[essai[j]]+=1

    return couleur

def donne_couleur(essai,mot,j):
    if essai[j]== mot[j]:
        return 2
    elif essai[j] in mot[:j]+mot[j+1:]:
        return 1
    else:
        return 0

