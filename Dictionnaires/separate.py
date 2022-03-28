D=open('dictionnaire.txt','r') #il y a un mot par lignes dans ce dictionnaire 
L=D.readlines()
D1=open('dictionnaire1.txt','w+')
D2=open('dictionnaire2.txt','w+')
D3=open('dictionnaire3.txt','w+')
D4=open('dictionnaire4.txt','w+')
D5=open('dictionnaire5.txt','w+')
D6=open('dictionnaire6.txt','w+')
D7=open('dictionnaire7.txt','w+')
D8=open('dictionnaire8.txt','w+')
D9=open('dictionnaire9.txt','w+')
D10=open('dictionnaire10.txt','w+')
D11=open('dictionnaire11.txt','w+')
D12=open('dictionnaire12.txt','w+')
D13=open('dictionnaire13.txt','w+')
D14=open('dictionnaire14.txt','w+')
D15=open('dictionnaire15.txt','w+')
D16=open('dictionnaire16.txt','w+')
D17=open('dictionnaire17.txt','w+')
D18=open('dictionnaire18.txt','w+')
D19=open('dictionnaire19.txt','w+')
D20=open('dictionnaire20.txt','w+')
D21=open('dictionnaire21.txt','w+')
D22=open('dictionnaire22.txt','w+')
D23=open('dictionnaire23.txt','w+')
D24=open('dictionnaire24.txt','w+')
D25=open('dictionnaire25.txt','w+')
D26=open('dictionnaire26.txt','w+')
D_FULL = [D1, D2, D3, D4, D5, D6, D7 , D8, D9, D10, D11, D12, D13,D14,D15,D16,D17,D18,D19,D20,D21,D22,D23,D24,D25,D26]
length=len(L)
L_FULL=[0 for k in range (len(D_FULL))]
res=0
for k in range(length):
    for j in range (2,29): 
        if len(L[k])==j:
            D_FULL[j-2].write(L[k])
            L_FULL[j-2]+=1 #je récupère les longueurs de chaque sous-dictionnaire

for k in range (len(L_FULL)):
    res+=L_FULL[k] #je somme la longueur de chaque sous-dictionnaire pour vérifier que j'ai autant de mots que dans le dictionnaire initial 
#print(res,length)

for j in range (26):#si le sous-dictionnaire 26 n'est plus vide, il faut que 26->27 
    D_FULL[j-2].close()
D.close()
