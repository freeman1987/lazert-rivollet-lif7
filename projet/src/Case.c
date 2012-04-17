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

    return c;
}

/**
    @brief [PRIVEE] Rendre libre ou non une case
    @param c : pointeur sur la case a modifier
    @param val : booléen : libre ou non
    @return void
*/
void setLibre(Case* c, int val)
{
    c->libre = val;
}

void changeJoueur(Case* c, int joueur)
{
    if(joueur==0) /* liberer la case */
    {
        setLibre(c,1);
        c->joueur = 0;
    }
    else if(joueur==1 || joueur==2) /* mettre le joueur */
    {
        setLibre(c,0);
        c->joueur = joueur;
    }
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

int getX(const Case* c)
{
    return c->posX;
}

int getY(const Case* c)
{
    return c->posY;
}
