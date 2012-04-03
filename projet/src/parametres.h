#ifndef _PARAMETRES
#define _PARAMETRES

#include <SDL/SDL.h>
#include <SDL_image.h>
/**
	Paramètres pour les images à charger.
*/

	#define PION_JOUEUR_1 "../data/Texture1/Rubis.png"
	#define PION_JOUEUR_2 "../data/Texture1/Perle.png"
	#define CASE_VIDE "../data/Texture1/Case.png"
	#define CASE_JOUEABLE "../data/Texture1/Case2.png"
	#define UNITE_X 54.5
	#define UNITE_Y 29.5
	SDL_Surface* pion1;
    SDL_Surface* pion2;
    SDL_Surface* screen;
    SDL_Surface* case_vide;


#endif
