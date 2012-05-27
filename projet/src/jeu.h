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
    @brief <b>Cette fonction lance le jeu.</b><br />
    Commence une nouvelle partie du jeu et charge toutes les données.<br />
    Les valeurs des paramètres d'appel peuvent êtres changés avant par le menu principal.

    @param [IN] contreordinateur : jouer contre l'ordinateur (1) ou un joueur (0)
    @param [IN] niveauordinateur : niveau de l'ordinateur (0-9)
    @param [IN] plateau : plateau sur lequel on souhaite jouer (0-x)

    @return 0
*/
int Jouer(const int contreordinateur, const int niveauordinateur, const int plateau);

#endif
