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
    num=len(mot)
    mots= dictionnaire(num,lang)
    if mot+"\n" in mots:
        return True
    return False

def compare(essai,mot):
    n=len(essai)
    m=len(mot)
    L=[]

    for j in range(n):
        if essai[j] in mot:
            a=1
            if essai[j] ==mot[j]:
                a=2
        else:
            a=0
        L.append(a)
                        #for i in range(n):
                            #if essai[i]==mot[i]:
                                #L.append(2)
                        # elif essai[i] in mot:
                        #     L.append(1)
                        # elif essai[i] not in mot:
                        #     L.append(0)
    return L
print(compare('merci','raree'))
