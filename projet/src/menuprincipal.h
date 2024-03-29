#ifndef _MENUPRINCIPAL
#define _MENUPRINCIPAL

#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "affiche.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "api/inc/fmod.h"
#include "api/inc/fmod_errors.h"

/**
    @brief <b>Affiche le menu principal.</b><br />
    Les paramètres doivent être initialisés au prealable.

    @param [in,out] contreordinateur : jouer contre l'ordinateur (1) ou un joueur (0)
    @param [in,out] niveauordinateur : niveau de l'ordinateur (0-9)
    @param [in,out] plateau : plateau sur lequel on souhaite jouer (0-x)

    @return int : 0 pour quitter et 1 pour lancer le jeu
*/
int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau);


/**
    @brief <b>Vérifier qu'un son est bien chargé</b><br />
    On doit avoir un pointeur non nul sinon on affiche une erreur et l'on arrête l'execution du jeu

    @param [in] son : pointeur sur FMOD_Sound

    @return rien
*/
void afficheVerifChargementSon(const FMOD_SOUND* son);

#endif
