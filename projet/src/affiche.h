#ifndef _AFFICHE
#define _AFFICHE

#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

#include "Case.h"
#include "Plateau.h"


/**
    @brief Afficher les scores des joueurs

    @param [IN] s1 : score 1
    @param [IN] s2 : score 2
    @param [IN] chiffres : Pointeur sur le tableau d'images de chiffres
    @param [IN] haut : Pointeur sur l'image à afficher au dessus des scores

    @return void
*/
void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut);


/**
    @brief Afficher quel joueur à la main

    @param [in] j : joueur

    @return void
*/
void afficheQuiJoue(int j);


/**
    @brief Affiche bravo qu gagnant

    @param [in] joueur : joueur gagnant

    @return void
*/
void afficheFinJeu(int s1, int s2);


#endif
