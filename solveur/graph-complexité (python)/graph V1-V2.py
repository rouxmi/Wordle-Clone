import math
import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

Liste_moyenne=[0]*18
Liste_nT=[0]*18
Liste_vict=[[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
Liste_temp=[0]*18
Liste_div=[54, 341, 994, 2034, 3140, 3621, 3558, 2959, 2203, 1460, 890, 508, 289, 130, 36, 20, 11, 2]


data= open("solveur/texte/stats2.txt",'r')

lines= data.readlines()


i=0
j=-1
k=-1

for line in lines:
    print(line)
    if i==0:
        j=(j+1)%18
    if j==0 and i==0:
        k+=1
    if 0<i<16:
        Liste_vict[(i-1)+j*15][2]+=int(line.replace("\n","").split(":")[1])/(Liste_div[j])
        if k==0:
            Liste_vict[(i-1)+j*15][0]=i
            Liste_vict[(i-1)+j*15][1]=j+2

    if i==16:
        Liste_nT[j]=Liste_nT[j]+float(line.replace("\n","").split(":")[1])
    if i==17:
        Liste_moyenne[j]+=float(line.replace("\n","").split(":")[1])
    if i==19:
        Liste_temp[j]+=float(line.replace("\n","").split("en ")[1].split(" ")[0])

    i=(i+1)%20

print(Liste_div)

for i in range(len(Liste_vict)):
    Liste_vict[i][2]=Liste_vict[i][2]*100
    number=Liste_vict[i][2]
    stepper=10**number
    Liste_vict[i][2]=math.trunc(round(stepper * number, 6 * 3)) / stepper
    Liste_vict[i][0]=round(Liste_vict[i][0])
    Liste_vict[i][1]=round(Liste_vict[i][1])


print(Liste_moyenne)
print(Liste_nT)
print(Liste_vict)
print(Liste_temp)

print(Liste_vict)
val_np_array = np.array(Liste_vict)
val_pd_array = pd.DataFrame(val_np_array)
sns.set_theme()
val_pd_array.columns=["nombre d'essai","nombre de lettre","nombre de succés"]
print(val_pd_array)
val_pd_array["Nombre d'essais"] = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]*18
val_pd_array["Nombre de lettres"]=[int((i//15)+2) for i in range(270)]
del val_pd_array["nombre d'essai"]
del val_pd_array["nombre de lettre"]
print(val_pd_array)
data=val_pd_array.pivot("Nombre d'essais","Nombre de lettres","nombre de succés")


f, ax = plt.subplots(figsize=(9, 6))
sns.heatmap(data, annot=True, linewidths=.5, ax=ax, center=3, cmap='coolwarm', cbar_kws={'label':"Pourcentage de mots trouvés",'orientation': 'horizontal'})
ax.set_xticklabels(data.columns.tolist())
plt.show()

Liste=[[] for i in range(18)]
for i in range(18):
    if i<18:
        Liste[i]=[Liste_div[i],"Nombre de Mots",int(i+2)]
    else:
        Liste[i]=[Liste_moyenne[i-18],"Moyenne",int(i-18+2)]

tot=0
for i in range(len(Liste_temp)):
    tot+=Liste_temp[i]
print(tot)


array2=np.array(Liste)
data2=pd.DataFrame(array2)
data2.columns=["données","Type","Nombres de lettres"]
data2["Nombres de lettres"]=pd.to_numeric(data2["Nombres de lettres"])
data2["données"]=pd.to_numeric(data2["données"])
print(data2)

fig,ax = plt.subplots()
ax.plot([i+2 for i in range(18)],Liste_div,label="Nombre de mots",color="red")
ax.set_xlabel("Nombre de Lettres",fontsize=14)
ax.set_ylabel("Nombre de Mots",color="red",fontsize=14)
ax2=ax.twinx()
ax2.plot([i+2 for i in range(18)],Liste_temp,label="Temps moyen (en secondes)",color="blue")
ax2.set_ylabel("Temps moyen",color="blue",fontsize=14)
ax3=ax.twinx()
ax3.plot([i+2 for i in range(18)],Liste_moyenne,label="Moyenne d'essai",color="green")
ax3.set_ylabel("Moyenne d'essais",color="green",fontsize=14)
ax3.spines['right'].set_position(('outward',60))
ax.set(xlim=(2,19))
plt.show()
