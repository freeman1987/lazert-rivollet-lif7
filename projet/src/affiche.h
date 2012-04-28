#ifndef _AFFICHE
#define _AFFICHE

#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

#include "Case.h"
#include "Plateau.h"

/**
    @brief Transforme des coordonnées x,y de cases en un SDL_Rect

    @param [IN] x : coordonnée x
    @param [IN] y : coordonnée y

    @return SDL_Rect
*/
SDL_Rect xy2rect(int x, int y);


/**
    @brief Afficher les scores des joueurs

    @param [IN] s1 : score 1
    @param [IN] s2 : score 2
    @param [IN] chiffres : Pointeur sur le tableau d'images de chiffres
    @param [IN] haut : Pointeur sur l'image à afficher au dessus des scores

    @return void
*/
void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion1, SDL_Surface* pion2);


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


/**
    @brief Afficher une image à partir de coordonnées en pixels

    @param [IN] x : coordonnée X en pixels
    @param [IN] y : coordonnée Y en pixels
    @param [IN] image : image à afficher

    @return void
*/
void afficheImage(int x, int y, SDL_Surface* image);


/**
    @brief Afficher une image à partir d'un rectangle SDL

    @param [IN] rect : coordonnée SDL en pixels
    @param [IN] image : image à afficher

    @return void
*/
void afficheImageRect(SDL_Rect rect, SDL_Surface* image);


/**
    @brief Afficher une case

    @param [IN] x : coordonnée X
    @param [IN] y : coordonnée y
    @param [IN] image : image de la case

    @return void
*/
void afficheCase(int x, int y, SDL_Surface* image);


/**
    @brief Afficher le plateau (les cases)

    @param [IN] p : Pointeur sur Plateau

    @return void
*/
void afficheJeu(const Plateau* p, SDL_Surface* image_case, SDL_Surface* pion1, SDL_Surface* pion2);


#endif
