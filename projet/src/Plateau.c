#include <stdlib.h>
#include <stdio.h>

#include "Case.h"
#include "Plateau.h"

void plateauInit(Plateau* p, int capa)
{
    p->capacite = capa;
    p->places_libre = 0;

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
