#ifndef _JEU
#define _JEU

#include <stdio.h>
#include <stdlib.h>

#include "Case.h"
#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "api/inc/fmod.h"
#include "api/inc/fmod_errors.h"

/**
    @brief Cette fonction lance le jeu

    @param [IN] contreordinateur : jouer contre l'ordinateur (1) ou un joueur (0)
    @param [IN] niveauordinateur : niveau de l'ordinateur
    @param [IN] plateau : plateau sur lequel on souhaite jouer

    @return int
*/
int Jouer(const int contreordinateur, const int niveauordinateur, const int plateau);

#endif
