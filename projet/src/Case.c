#include <stdlib.h>
#include <stdio.h>

#include "Case.h"

Case* caseInit()
{
    Case* c;
    c = (Case *) malloc(sizeof(Case));
    if(c==0)
    {
        printf("Erreur d'allocation pour une case.");
        exit(1);
    }
    c->libre = 1;

    return c;
}

void caseSetLibre(Case* c, int val)
{
    c->libre = val;
    c->joueur = 0;
}

void caseSetPos(Case* c, int x, int y)
{
    if(x<0 || y<0)
    {
        printf("Erreur pour fixer les coordonnes de la case :\n\tles valeurs ne sont pas positives.\n");
        exit(1);
    }

    c->posX = x;
    c->posY = y;
}


int caseGetLibre(const Case* c)
{
    return c->libre;
}

int caseGetJoueur(const Case* c)
{
    return c->joueur;
}

void caseSetJoueur(Case* c, int j)
{
    c->joueur = j;
    if(j==0)
        c->libre = 1;
    else
        c->libre = 0;
}

int caseGetX(const Case* c)
{
    return c->posX;
}

int caseGetY(const Case* c)
{
    return c->posY;
}

int caseTestCoordonnees(Case* c,int sx,int sy)
{
    if((c->posX==sx)&&(c->posY==sy))
        return 1;
    else
        return 0;
}

void caseTestament(Case* c)
{
    /* libérer la mémoire */
    if(c!=0)
        free(c);
    printf("case à l'adresse %u libérée\n",(int) c);
}
