#ifndef _ORDINATEUR
#define _ORDINATEUR

#include "parametres.h"
#include "Plateau.h"

#include <stdlib.h>
#include <stdio.h>

/**
    @brief Faire jouer automatiquement un joueur

    @param [IN] p : Pointeur sur Plateau
    @param [IN] joueur : Numéro du joueur

    @return void
*/
void ordinateurJouer(Plateau* p, int joueur);

#endif
