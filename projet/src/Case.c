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
        exit(-1);
    }
    c->libre = 1;

    return c;
}

void setLibre(Case* c, int val)
{
    c->libre = val;
}

void setPos(Case* c, int x, int y)
{
    if(x<0 || y<0)
    {
        printf("Erreur pour fixer les coordonnes de la case.");
        exit(-1);
    }

    c->posX = x;
    c->posY = y;
}


int getLibre(const Case* c)
{
    return c->libre;
}

int getJoueur(const Case* c)
{
    return c->joueur;
}

void setJoueur(Case* c, int j)
{
    c->joueur = j;
    if(j==0)
        c->libre = 0;
}

int getX(const Case* c)
{
    return c->posX;
}

int getY(const Case* c)
{
    return c->posY;
}

int coordonneeCorrespondante(Case* c,int sx,int sy)
{
    if((c->posX==sx)&&(c->posY==sy))
        return 1;
    else
        return 0;
}
