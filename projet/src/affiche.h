#ifndef _AFFICHE
#define _AFFICHE

#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL_image.h>

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
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief Afficher quel joueur à la main

    @param [IN] j : joueur
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheQuiJoue(int j, SDL_Surface* ecran);


/**
    @brief Affiche bravo qu gagnant

    @param [IN] s1 : score du joueur 1
    @param [IN] s2 : score du joueur 2
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheFinJeu(int s1, int s2, SDL_Surface* ecran);


/**
    @brief Afficher une image à partir de coordonnées en pixels

    @param [IN] x : coordonnée X en pixels
    @param [IN] y : coordonnée Y en pixels
    @param [IN] image : image à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheImage(int x, int y, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief Afficher une image à partir d'un rectangle SDL

    @param [IN] rect : coordonnée SDL en pixels
    @param [IN] image : image à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheImageRect(SDL_Rect rect, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief Afficher le plateau (les cases)

    @param [IN] p : Pointeur sur Plateau
    @param [IN] image_case : SDL_Surface image d'une case vide
    @param [IN] pion_j1 : SDL_Surface image du pion du joueur 1
    @param [IN] pion_j2 : SDL_Surface image du pion du joueur 2
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheJeu(const Plateau* p, SDL_Surface* image_case, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief Vérifier qu'un image est bien chargée

    @param [IN] img : SDL_Surface*

    @return void
*/
void afficheVerifChargement(SDL_Surface* img);


/**
    @brief Afficher une case du plateau

    @param [IN] c : Pointeur sur Case
    @param [IN] image : SDL_Surface image de case à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void

*/
void afficheCaseJeu(const Case* c, SDL_Surface* image, SDL_Surface* ecran);


/**
    @param Afficher les cases joueables autour de c

    @param [IN] p : Pointeur sur Plateau
    @param [IN] c : Pointeur sur Case
    @param [IN] img_dupliquer : SDL_Surface de l'image à afficher juste à côté
    @param [IN] img_deplacer : SDL_Surface de l'image à afficher plus loin
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return void
*/
void afficheCasesAutour(const Plateau* p, const Case* c, SDL_Surface* img_dupliquer, SDL_Surface* img_deplacer, SDL_Surface* ecran);

#endif
