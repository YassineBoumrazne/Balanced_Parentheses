
#include <stdio.h>
#include <stdlib.h>




struct maillon{
    char z;
    struct maillon *pSuivant;
};
typedef struct maillon Tmaillon;

struct pileC{
    Tmaillon *sommet;

};
typedef struct pileC TPileC;


TPileC* CreePile(){
    TPileC *pile=malloc(sizeof(TPileC));
    pile->sommet=NULL;
    return pile;
}

Tmaillon *CreeMaillon(TPileC p,char z){
    Tmaillon *pm=malloc(sizeof(Tmaillon));
    pm->z=z;
    pm->pSuivant=NULL;
    return pm;
}

int PileVide(TPileC pile){
    return (pile.sommet==NULL);
}

int Empiler(TPileC *pile,char z){
    Tmaillon *pm=CreeMaillon(*pile,z);
    if(pm==NULL) return 0;

    pm->pSuivant=pile->sommet;
    pile->sommet=pm;
    return 1;
}


char* Depiler(TPileC *pile){
    if(PileVide(*pile))
        return NULL;
    Tmaillon *pT=pile->sommet;
    char zDep=pT->z;
    char *z=&zDep;
    pile->sommet=pile->sommet->pSuivant;
    free(pT);
    return z;
}

int LongPile(TPileC pile){
    Tmaillon *pT=pile.sommet;
    int l=0;
    while(pT!=NULL){
        l++;
        pT=pT->pSuivant;
    }
    return l;
}

void Afficher(TPileC pile){
    Tmaillon *pT=pile.sommet;
    while(pT!=NULL){
        printf("char: \n",pT->z);
        pT=pT->pSuivant;
    }
}

Tmaillon* rechercher(TPileC *pile,char Z){
    Tmaillon *pT=pile->sommet;
    while(pT!=NULL){
        if(pT->z==Z)
            return pT;
        pT=pT->pSuivant;
    }
    return NULL;
}



int estInversementIdentique(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int ExpressionEstBalance(char exp[])
{
    int i = 0;
    TPileC* pile = CreePile();
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            Empiler(pile,exp[i]);
        if (exp[i] == '}' || exp[i] == ')'
            || exp[i] == ']') {
            if (PileVide(*pile))
                return 0;
            else if (!estInversementIdentique(*Depiler(pile), exp[i]))
                return 0;
        }
        i++;
    }


    if (PileVide(*pile))
        return 1;
    else
        return 0;
}

void Menu(TPileC *pile){
    int choice;
    system("cls");
    printf("\n\n\t\t\t\tMenu");
    printf("\n\t\t\t1- Tester ");
    printf("\n\t\t\t0- Exit");
    printf("\n\n\t\t\t Votre Choix: ");
    scanf("%d",&choice);
    system("cls");
    char c;
    char exp[200];
    switch(choice){
    case 0:
        exit(1);
    case 1:
        printf("Enter l'expression : ");
        scanf("%s",exp);
        if(ExpressionEstBalance(exp))
            printf("Balanced");
        else
            printf("Not Balanced");
        printf("\n\nPress any key");
        getch();
        break;
    default:
        printf("Pls Entre A valid Choice!!");
        printf("\n\nPress any key");
        getch();
        break;
    }
}

