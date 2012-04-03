#ifndef _PLATEAU
#define _PLATEAU

#include <stdlib.h>
#include <stdio.h>

#include "Case.h"

typedef struct
{
	/* nombre de places libres sur le support */
	int places_libres;
	/* nombre de places sur le plateau */
	int capacite;
	/* tableau de pointeurs de cases pour le jeu */
	Case** support;
} Plateau;


/**
    @brief Initialise le plateau
*/
void plateauInit(Plateau* p, int capacite);


/**
    @brief Retourne le nombre de places libres sur le plateau

    @param [IN] p : pointeur sur plateau

    @return nombre de places
*/
int getPlacesLibres(const Plateau* p);

#endif
