#ifndef _PARAMETRES
#define _PARAMETRES

#include <SDL/SDL.h>
#include <SDL_image.h>
/**
	Paramètres pour les images à charger.

	@param PION_JOUEUR_1 chemin vers l'image du pion 1
	@param PION_JOUEUR_2 chemin vers l'image du pion 2
	@param CASE_VIDE chemin vers l'image de la case
	@param CASE_JOUABLE chemin vers l'image de la case d'une autre couleur
	@param UNITE_X unités pour les coordonnées horizontales
	@param UNITE_Y unités pour les coordonnées verticales
	@param DECAL_X décalage du plateau par rapport au haut de l'écran
	@param DECAL_Y décalage du plateau par rapport au côté gauche de l'écran
*//*
    Les coordonnées correspondent aux images "case"
    Leur valeur permet d'aligner correctement les hexagones.
*/

	#define PION_JOUEUR_1 "../data/Texture1/Rubis.png"
	#define PION_JOUEUR_2 "../data/Texture1/Perle.png"
	#define CASE_VIDE "../data/Texture1/Case.png"
	#define CASE_JOUABLE "../data/Texture1/Case2.png"
	#define UNITE_X 54.5
	#define UNITE_Y 29.5
	#define DECAL_X 4
	#define DECAL_Y 3

/**
    Variables globales pour contenir les images SDL.
    Ces variables sont globales pour être utilisées dans les modules.
*/

	SDL_Surface* pion1;
    SDL_Surface* pion2;
    SDL_Surface* screen;
    SDL_Surface* case_vide;
    SDL_Surface* case_jouable;


#endif
