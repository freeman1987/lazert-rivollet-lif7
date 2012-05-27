#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"

/**
    @brief <b>Fonction du jeu.</b><br />
    Appel de cette fonction pour lancer le jeu.<br />
    Pour les tests de régression : appel avec le paramètre -r

    @param argc : nombre de paramètres
    @param argv : valeur des paramètres

    @return int
*/
int main(int argc, char *argv[]);

/**
    @brief <b>Fonction d'appel des tests de regression.</b><br />
    Fonction qui teste les fonctions des modules.

    @return 0
*/
int regression(void);
