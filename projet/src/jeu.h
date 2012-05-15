#ifndef _JEU
#define _JEU

#include <stdio.h>
#include <stdlib.h>

#include "Case.h"
#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"

#include "api/inc/fmod.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/** \brief Cette fonction lance le jeu.
 *
 *  \return void
 *
 */
int Jouer(const int contreordinateur, const int niveauordinateur, const int plateau);

#endif
