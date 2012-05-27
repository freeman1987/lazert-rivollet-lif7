#ifndef _ORDINATEUR
#define _ORDINATEUR

#include "parametres.h"
#include "Plateau.h"

#include <stdlib.h>
#include <stdio.h>

/**
    @brief <b>Fonction de jeu automatique.</b><br />
    Fonction qui tente de déterminer la meilleure action et qui l'execute.<br />
    Cette fonction analyse tout le plateau.<br />
    Le paramètre niveau permet de restreindre les améliorations au fur et à mesure de la boucle.

    @param [IN,OUT] p : Pointeur sur Plateau
    @param [IN] joueur : Numéro du joueur
    @param [IN] niv : (1-9) nombre de changements d'avis (plus c'est bas, moins l'analyse est bonne)

    @return rien
*/
void ordinateurJouer(Plateau* p, int joueur, int niv);

#endif
