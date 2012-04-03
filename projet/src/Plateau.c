#include <stdlib.h>
#include <stdio.h>

#include "Case.h"
#include "Plateau.h"

void plateauInit(Plateau* p, int capa)
{
    p->capacite = capa;
    p->places_libres = 0;

    p->support = (Case **) malloc(sizeof(Case)*capa);
    if(p->support==0)
    {
        printf("Erreur d'allocation pour le tableau de Cases.");
        exit(-1);
    }
}


int getPlacesLibres(const Plateau* p)
{
    return p->places_libres;
}

void affichePiece(Plateau* p)
{
    int i;
    Case* ca;
    for(i=0;i<p->capacite;i++)
    {
        ca = p->support[i];
                if(==1)
        dessinepion1(ca[i].X,ca[i].Y)
        else
        dessinepion2(ca[i].X,ca[i].Y)
    }
}
