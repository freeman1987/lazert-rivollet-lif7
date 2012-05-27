#ifndef _MENUPRINCIPAL
#define _MENUPRINCIPAL

#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "affiche.h"
#include "affiche.h"

#include <SDL.h>
#include <SDL/SDL_image.h>

/**
    @brief Affiche le menu principal. Les paramètres doivent être initialisés
    @param contreordinateur : jouer contre l'ordinateur (1) ou un joueur (0)
    @param niveauordinateur : niveau de l'ordinateur
    @param plateau : plateau sur lequel on souhaite jouer

    @return int : 0 pour quitter et 1 pour lancer le jeu
*/
int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau);

/**
    @brief Determine si la souris est dans un rectangle
    @param x : position x de la souris
    @param y : position y de la souris
    @param rectangle : rectangle pour tester

    @return int (booléen)
*/
int sourisDansRectangle(int x, int y, SDL_Rect rectangle);

#endif
