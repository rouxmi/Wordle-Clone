D=open('Dictionnaires/fr_dictionnaire.txt','r') #il y a un mot par lignes dans ce dictionnaire 
L=D.readlines()
D1=open('Dictionnaires/fr_dictionnaire1.txt','w+')
D2=open('Dictionnaires/fr_dictionnaire2.txt','w+')
D3=open('Dictionnaires/fr_dictionnaire3.txt','w+')
D4=open('Dictionnaires/fr_dictionnaire4.txt','w+')
D5=open('Dictionnaires/fr_dictionnaire5.txt','w+')
D6=open('Dictionnaires/fr_dictionnaire6.txt','w+')
D7=open('Dictionnaires/fr_dictionnaire7.txt','w+')
D8=open('Dictionnaires/fr_dictionnaire8.txt','w+')
D9=open('Dictionnaires/fr_dictionnaire9.txt','w+')
D10=open('Dictionnaires/fr_dictionnaire10.txt','w+')
D11=open('Dictionnaires/fr_dictionnaire11.txt','w+')
D12=open('Dictionnaires/fr_dictionnaire12.txt','w+')
D13=open('Dictionnaires/fr_dictionnaire13.txt','w+')
D14=open('Dictionnaires/fr_dictionnaire14.txt','w+')
D15=open('Dictionnaires/fr_dictionnaire15.txt','w+')
D16=open('Dictionnaires/fr_dictionnaire16.txt','w+')
D17=open('Dictionnaires/fr_dictionnaire17.txt','w+')
D18=open('Dictionnaires/fr_dictionnaire18.txt','w+')
D19=open('Dictionnaires/fr_dictionnaire19.txt','w+')
D20=open('Dictionnaires/fr_dictionnaire20.txt','w+')
D_FULL = [D1, D2, D3, D4, D5, D6, D7 , D8, D9, D10, D11, D12, D13,D14,D15,D16,D17,D18,D19,D20]
length=len(L)
L_FULL=[0 for k in range (len(D_FULL))]
res=0
for k in range(length):
    for j in range (2,21): 
        if len(L[k])==j:
            D_FULL[j-2].write(L[k])
            L_FULL[j-2]+=1 #je récupère les longueurs de chaque sous-dictionnaire

for k in range (len(L_FULL)):
    res+=L_FULL[k] #je somme la longueur de chaque sous-dictionnaire pour vérifier que j'ai autant de mots que dans le dictionnaire initial 
print(res,length)

for j in range (21):#si le sous-dictionnaire 26 n'est plus vide, il faut que 26->27 
    D_FULL[j-2].close()
D.close()
