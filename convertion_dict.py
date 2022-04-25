import random
import unidecode 

def dictionnaire():

    fichier= open("Dictionnaires/en_dictionnaire_minuscules.txt",'r')
    dictionnaire=open("Dictionnaires/en_dictionnaire.txt",'w')
    mots=fichier.readlines()
    print('coucou')
    for mot in mots:
        a = mot.split(',')
        b= a[0].split('\n')
        new=unidecode.unidecode(b[0])
        dictionnaire.write(new.upper()+"\n")

    fichier.close()
    dictionnaire.close()

print(dictionnaire())
'''
#mots= dictionnaire()

def existe(mot):
    if mot in mots:
        return True
    return False


mot=random.choice(mots)

def compare(essai,mot):
    n=len(essai)
    m=len(mot)
    L=[]
    if n==m and existe(essai):
        for i in range(n):
            if essai[i]==mot[i]:
                L.append(2)
            elif essai[i] in mot:
                L.append(1)
            elif essai[i] not in mot:
                L.append(0)
        return L
    elif not existe(essai):
        return("ce mot n'est pas dans le dictionnaire")
    else:
        return("Le mot essayé n'est pas de la bonne taille")
        

#print(compare("ABAISSA",mot))

'''