#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
    @brief Fonction du jeu

    @return int
*/
int main ()
{
    int rejouer;
    int contreordinateur, niveauordinateur, plateau;
    plateau=1;
    rejouer = 1;

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
