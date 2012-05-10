#ifndef _MENUPRINCIPAL
#define _MENUPRINCIPAL

#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
    @brief Affiche le menu principal

    @return int : 0 pour quitter et 1 pour lancer le jeu
*/
int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau);

/**
    @brief Determine si la souris est dans un rectangle

    @return int (booléen)
*/
int sourisDansRectangle(int x, int y, SDL_Rect rectangle);

#endif
