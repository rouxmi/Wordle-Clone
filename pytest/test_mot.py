from mot import *
import pytest

#test de l'existence du mot
@pytest.mark.parametrize("existant,lang,resultats",[
    ("OUI","fr",True),
    ("NON","fr",True),
    ("JOUER","fr",True),
    ("TAPER","fr",True),
    ("ABC","fr",False),
    ("oui","fr",False),
    ("non","fr",False),
    ("OUI","en",True),
    ("PROUT","fr",False),
    ("TABLE","fr",True),
    ("CORPS","fr",True),
    ("CRANE","fr",True),
    ("CRANE","en",True),
    ("DRAME","fr",True),
    ("NOT","en",True),
    ("POUTRE","fr",True),
    ("MAISON","fr",True),
    ("PORT","fr",True),
    ("CANAPE","fr",True),
    ("KING","en",True),
    ("QUEEN","en",True),
    ("NOT","fr",False),
    ("QUEEN","fr",False),
    ("JOUER","en",False),
    ("PLAYER","fr",False),
    ("GAME","fr",False),
    ("ABRABRA","fr",False),
    ("ABRABRA","en",False),
    ("SOLIDE","en",False),
    ("CARAMEL","en",True),
    ("LOLOLO","fr",False),
    ("LOLOLO","en",False),
    ("FALSE","en",True),
    ("BAIGNER","en",False),
    ("BAIGNER","fr",True),
])

def test_existant(existant,lang,resultats):
    assert existe(existant,lang)==resultats

#test de la coloration des mots
@pytest.mark.parametrize("essais,mots,resultats",[
    ("poudrer","pigment",[2,0,0,0,0,1,0]),
    ("parfait","pigment",[2,0,0,0,0,1,2]),
    ("piefort","pigment",[2,2,1,0,0,0,2]),
    ("pigment","pigment",[2,2,2,2,2,2,2]),
    ("montes","montes",[2,2,2,2,2,2]),
    ("moites","montes",[2,2,0,2,2,2]),
    ("mottes","montes",[2,2,0,2,2,2]),
    ("moches","montes",[2,2,0,0,2,2]),
    ("mordre","montes",[2,2,0,0,0,1]),
    ("motttes","monetts",[2,2,1,0,2,1,2]),
    ("casser","casser",[2,2,2,2,2,2]),
    ("calmer","casser",[2,2,0,0,2,2]),
    ("cramer","casser",[2,0,1,0,2,2]),
    ("couler","casser",[2,0,0,0,2,2]),
    ("cordes","casser",[2,0,1,0,2,1]),
    ("emmenagee","emmenagee",[2,2,2,2,2,2,2,2,2]),
    ("embecquee","emmenagee",[2,2,0,2,0,0,0,2,2]),
    ("effectuee","emmenagee",[2,0,0,2,0,0,0,2,2]),
    ("ecrevisse","emmenagee",[2,0,0,2,0,0,0,0,2]),
    ("ephemeres","emmenagee",[2,0,0,2,1,1,0,2,0]),
    ("finalisee","finalisee",[2,2,2,2,2,2,2,2,2]),
    ("finaliste","finalisee",[2,2,2,2,2,2,2,0,2]),
    ("finalisme","finalisee",[2,2,2,2,2,2,2,0,2]),
    ("farandole","finalisee",[2,0,0,2,1,0,0,1,2]),
    ("reunion","reposee",[2,2,0,0,0,1,0]),
    ("reporte","reposee",[2,2,2,2,0,0,2]),
    ("reposee","reposee",[2,2,2,2,2,2,2]),
    ("encages","encages",[2,2,2,2,2,2,2]),
    ("encaves","encages",[2,2,2,2,0,2,2]),
    ("enroule","encages",[2,2,0,0,0,0,1]),
    ("escales","encages",[2,0,2,2,0,2,2]),
    ("eclairs","encages",[2,1,0,2,0,0,2]),
    ("firmes","filtre",[2,2,1,0,1,0]),
    ("filtre","filtre",[2,2,2,2,2,2]),
    ("foires","filtre",[2,0,1,1,1,0]),
    ("test","poet",[0,1,0,2])

])

def test_couleur(essais,mots,resultats):
    assert compare(essais,mots)==resultats

#test de la coloration d'une lettre 
@pytest.mark.parametrize("essais,mots,js,resultats",[
    ("poutre","parents",3,1),
    ("donne","pomme",0,0),
    ("coule","saoule",1,1),
    ("poutre","parents",5,1),
    ("oui","non",2,0),
    ("couche","mouche",4,2),
    ("soupe","poule",2,2),
    ("soupe","poule",1,2),
    ("soupe","poule",0,0)

])

def test_donne_couleur(essais,mots,js,resultats):
    assert donne_couleur(essais,mots,js)==resultats