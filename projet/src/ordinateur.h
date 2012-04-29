#ifndef _ORDINATEUR
#define _ORDINATEUR

#include "parametres.h"
#include "Plateau.h"

#include <stdlib.h>
#include <stdio.h>

/**
    @brief Faire jouer automatiquement un joueur

    @param [IN,OUT] p : Pointeur sur Plateau
    @param [IN] joueur : Numéro du joueur
    @param [IN] niv : >0 et <10, nombre de changements d'avis (plus c'est bas, moins l'analyse est bonne)

    @return void
*/
void ordinateurJouer(Plateau* p, int joueur, int niv);

#endif
