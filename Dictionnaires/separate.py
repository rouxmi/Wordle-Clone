D=open('Dictionnaires/en_dictionnaire.txt','r') #il y a un mot par lignes dans ce dictionnaire 
L=D.readlines()
D1=open('Dictionnaires/en_dictionnaire1.txt','w+')
D2=open('Dictionnaires/en_dictionnaire2.txt','w+')
D3=open('Dictionnaires/en_dictionnaire3.txt','w+')
D4=open('Dictionnaires/en_dictionnaire4.txt','w+')
D5=open('Dictionnaires/en_dictionnaire5.txt','w+')
D6=open('Dictionnaires/en_dictionnaire6.txt','w+')
D7=open('Dictionnaires/en_dictionnaire7.txt','w+')
D8=open('Dictionnaires/en_dictionnaire8.txt','w+')
D9=open('Dictionnaires/en_dictionnaire9.txt','w+')
D10=open('Dictionnaires/en_dictionnaire10.txt','w+')
D11=open('Dictionnaires/en_dictionnaire11.txt','w+')
D12=open('Dictionnaires/en_dictionnaire12.txt','w+')
D13=open('Dictionnaires/en_dictionnaire13.txt','w+')
D14=open('Dictionnaires/en_dictionnaire14.txt','w+')
D15=open('Dictionnaires/en_dictionnaire15.txt','w+')
D16=open('Dictionnaires/en_dictionnaire16.txt','w+')
D17=open('Dictionnaires/en_dictionnaire17.txt','w+')
D18=open('Dictionnaires/en_dictionnaire18.txt','w+')
D19=open('Dictionnaires/en_dictionnaire19.txt','w+')
D20=open('Dictionnaires/en_dictionnaire20.txt','w+')
D21=open('Dictionnaires/fr_dictionnaire21.txt','w+')
D22=open('Dictionnaires/en_dictionnaire22.txt','w+')
D23=open('Dictionnaires/en_dictionnaire23.txt','w+')
D24=open('Dictionnaires/en_dictionnaire24.txt','w+')
D25=open('Dictionnaires/en_dictionnaire25.txt','w+')
D26=open('Dictionnaires/en_dictionnaire26.txt','w+')
D27=open('Dictionnaires/en_dictionnaire27.txt','w+')
D28=open('Dictionnaires/en_dictionnaire28.txt','w+')
D29=open('Dictionnaires/en_dictionnaire29.txt','w+')
D30=open('Dictionnaires/en_dictionnaire30.txt','w+')
D31=open('Dictionnaires/en_dictionnaire31.txt','w+') #dernier dictionnaire anglais rempli
'''D32=open('Dictionnaires/fr_dictionnaire32.txt','w+')
D33=open('Dictionnaires/en_dictionnaire33.txt','w+')
D34=open('Dictionnaires/en_dictionnaire34.txt','w+')
D35=open('Dictionnaires/en_dictionnaire35.txt','w+')
D36=open('Dictionnaires/en_dictionnaire36.txt','w+')
D37=open('Dictionnaires/en_dictionnaire37.txt','w+')'''
D_FULL = [D1, D2, D3, D4, D5, D6, D7 , D8, D9, D10, D11, D12, D13,D14,D15,D16,D17,D18,D19,D20,D21,D22,D23,D24,D25,D26,D27,D28,D29,D30,D31]
length=len(L)
L_FULL=[0 for k in range (len(D_FULL))]
res=0
for k in range(length):
    for j in range (2,40): 
        if len(L[k])==j:
            D_FULL[j-2].write(L[k])
            L_FULL[j-2]+=1 #je récupère les longueurs de chaque sous-dictionnaire

for k in range (len(L_FULL)):
    res+=L_FULL[k] #je somme la longueur de chaque sous-dictionnaire pour vérifier que j'ai autant de mots que dans le dictionnaire initial 
print(res,length)

for j in range (32):#si le sous-dictionnaire 26 n'est plus vide, il faut que 26->27 
    D_FULL[j-2].close()
D.close()
