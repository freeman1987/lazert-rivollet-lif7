#ifndef _MENUPRINCIPAL
#define _MENUPRINCIPAL

#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "affiche.h"
#include "affiche.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "api/inc/fmod.h"
#include "api/inc/fmod_errors.h"

/**
    @brief Affiche le menu principal. Les paramètres doivent être initialisés
    @param [IN,OUT] contreordinateur : jouer contre l'ordinateur (1) ou un joueur (0)
    @param [IN,OUT] niveauordinateur : niveau de l'ordinateur
    @param [IN,OUT] plateau : plateau sur lequel on souhaite jouer

    @return int : 0 pour quitter et 1 pour lancer le jeu
*/
int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau);

/**
    @brief Determine si la souris est dans un rectangle
    @param [IN] x : position x de la souris
    @param [IN] y : position y de la souris
    @param [IN] rectangle : rectangle pour tester

    @return int (booléen)
*/
int sourisDansRectangle(int x, int y, SDL_Rect rectangle);


void afficheVerifChargementSon(FMOD_SOUND* son);

#endif
