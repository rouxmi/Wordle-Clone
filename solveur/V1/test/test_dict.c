#include "dict.h"
#include <string.h>

void test_taille_file(){
    FILE* pr;
    FILE* pr2;
    pr2=fopen("texte/dico2.txt","r");
    pr=fopen("texte/dictauto.txt","r");
    assert(taillefichiertxt(pr)==5757);
    assert(taillefichiertxt(pr2)==81);
}

void test_contains(){
    assert(contains("lop","polo")==true);
    assert(contains("yzx","polo")==false);
    assert(contains("l","polo")==true);
    assert(contains("lop","cochon")==true);
    assert(contains("lxt","poutre")==true);
    assert(contains("ok","polo")==true);
    assert(contains("za","ananas")==true);
    assert(contains("pui","lol")==false);
}

void test_containsexceptposition(){
    int num1[]={2,1,3,0};
    assert(containsexceptposition("polo","loop",num1,4)==false);
    int num2[]={3};
    assert(containsexceptposition("heli","polo",num2,1)==true);
    int num3[]={3,1};
    assert(containsexceptposition("lopi","polo",num3,2)==false);
    int num4[]={0};
    assert(containsexceptposition("lopi","lolo",num4,1)==false);
    int num5[]={1,2,0};
    assert(containsexceptposition("lopi","polo",num5,3)==false);
    int num6[]={0,1,2,3};
    assert(containsexceptposition("coco","polo",num6,4)==false);
    int num7[]={1,2};
    assert(containsexceptposition("lopi","polo",num7,2)==true);

}

void test_contentofline(){
    FILE* pr;
    FILE* pr2;
    pr2=fopen("texte/dico2.txt","r");
    pr=fopen("texte/dictauto.txt","r");
    assert(strcmp(contentofline(pr,1,5757),"which"));
    assert(!strcmp(contentofline(pr,1,5757),"verge"));
    assert(strcmp(contentofline(pr,1,2204),"verge"));
    assert(strcmp(contentofline(pr2,81,81),"unfix"));
    assert(strcmp(contentofline(pr,5757,5757),"pupal"));
}
