#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"


/**
    @brief Fonction d'appel des tests de regression

    @param void

    @return int 0
*/
int regression(void)
{
    printf("\n\n-----------------------\n| TESTS DE REGRESSION |\n-----------------------\n| \n");

    caseTestRegression();

    printf("| \n| ---------------------\n| \n");

    plateauTestRegression();

    printf("| \n-----------------------\n\n");
    return 0;
}

/**
    @brief Fonction du jeu

    @param appel avec "r" pour les tests de regression

    @return int
*/
int main(int argc, char *argv[])
{
    if(argc>1 && argv[1][0]=='r') /* appel du test de régression */
    {
        regression();
        return 0;
    }

    int contreordinateur, niveauordinateur, plateau;

    /* paramètres de jeu par défaut */
    contreordinateur = 1;
    niveauordinateur = 5;
    plateau = 1;

    while(menuPrincipal(&contreordinateur, &niveauordinateur, &plateau)==1)
    {
        Jouer( contreordinateur, niveauordinateur, plateau);
    }
    return 0;
}
