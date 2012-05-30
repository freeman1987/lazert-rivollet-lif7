#include "main.h"
/*#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"*/

int regression(void)
{
    printf("\n\n-----------------------\n| TESTS DE REGRESSION |\n-----------------------\n| \n");

    caseTestRegression(); /* tests de non-régression du module case */

    printf("| \n| ---------------------\n| \n");

    plateauTestRegression(); /* tests de non-régression du module plateau */

    printf("| \n-----------------------\n\n");
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc>1 && argv[1][0]=='-' && argv[1][1]=='r') /* appel du test de régression */
    {
        regression();
        return 0;
    }

    int contreordinateur, niveauordinateur, plateau;

    /* paramètres de jeu par défaut */
    contreordinateur = 1;
    niveauordinateur = 3;
    plateau = 1;

    while(menuPrincipal(&contreordinateur, &niveauordinateur, &plateau)==1)
    {
        Jouer( contreordinateur, niveauordinateur, plateau);
    }
    return 0;
}
