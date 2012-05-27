#ifndef _AFFICHE
#define _AFFICHE

#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "parametres.h"
#include "Case.h"
#include "Plateau.h"


/**
    @brief <b>Convertir x,y en SDL_Rect.</b><br />
    Transforme des coordonnées x,y de cases en un SDL_Rect pour l'afficher éventuellement ensuite.

    @param [IN] x : coordonnée x
    @param [IN] y : coordonnée y

    @return SDL_Rect
*/
SDL_Rect xy2rect(int x, int y);


/**
    @brief <b>Afficher les scores des joueurs.</b><br />
    Affiche, pendant la partie, les scores respectifs des 2 joueurs.

    @param [IN] s1 : score du joueur 1
    @param [IN] s2 : score du joueur 2
    @param [IN] chiffres : Pointeur sur le tableau d'images de chiffres
    @param [IN] haut : Pointeur sur l'image à afficher au dessus des scores
    @param [IN] pion_j1 : Pointeur sur l'image du pion du joueur 1
    @param [IN] pion_j2 : Pointeur sur l'image du pion du joueur 2
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief <b>Afficher le niveau de l'ordinateur sur le menu.</b><br />
    Affiche le niveau de l'ordinateur à l'écran pour permettre à l'utilisateur de choisir.

    @param [IN] x : coordonnée x en pixels
    @param [IN] y : coordonnée y en pixels
    @param [IN] niveau : valeur du niveau
    @param [IN] chiffre : SDL_Surface (tableau de chiffres 0-9)
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheNiveauOrdinateur(int x, int y, int niv, SDL_Surface* chiffre[], SDL_Surface* ecran);


/**
    @brief <b>Afficher quel joueur à la main.</b><br />
    Afficher une image à l'écran pour savoir qui doit jouer.

    @param [IN] j : joueur
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheQuiJoue(int j, SDL_Surface* ecran);


/**
    @brief <b>Affiche bravo au joueur gagnant.</b><br />
    Fonction qui permet d'afficher à l'écran une image pour indiquer qui gagne.<br />
    Cette fonction est appelée à la fin de la partie.

    @param [IN] s1 : score du joueur 1
    @param [IN] s2 : score du joueur 2
    @param [IN] ordi : 1 si on a joué contre l'ordi
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheFinJeu(int s1, int s2, int ordi, SDL_Surface* ecran);


/**
    @brief <b>Afficher une image à partir de coordonnées.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir de coordonnées en pixels

    @param [IN] x : coordonnée X en pixels
    @param [IN] y : coordonnée Y en pixels
    @param [IN] image : image à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheImage(int x, int y, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher une image avec SDL_Rect.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir d'une position SDL_Rect

    @param [IN] rect : coordonnée SDL en pixels
    @param [IN] image : image à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheImageRect(SDL_Rect rect, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher le plateau.</b><br />
    Affiche toutes les cases du plateau de jeu.<br />
    Affiche ensuite les pions des joueurs aux endroits où ils se trouvent.

    @param [IN] p : Pointeur sur Plateau
    @param [IN] image_case : SDL_Surface image d'une case vide
    @param [IN] pion_j1 : SDL_Surface image du pion du joueur 1
    @param [IN] pion_j2 : SDL_Surface image du pion du joueur 2
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheJeu(const Plateau* p, SDL_Surface* image_case, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief <b>Vérifier qu'un image est bien chargée.</b><br />
    Affiche une erreur et arrête l'execution du jeu.

    @param [IN] img : pointeur sur une SDL_Surface

    @return rien
*/
void afficheVerifChargement(SDL_Surface* img);


/**
    @brief <b>Afficher une case du plateau</b><br />
    Affiche à l'écran une case du plateau

    @param [IN] c : Pointeur sur Case
    @param [IN] image : SDL_Surface image de case à afficher
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien

*/
void afficheCaseJeu(const Case* c, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher les cases joueables autour de c</b><br />
    Affiche des cases en couleurs là où le joueur peut poser son pion.

    @param [IN] p : Pointeur sur Plateau
    @param [IN] c : Pointeur sur Case
    @param [IN] img_dupliquer : SDL_Surface de l'image à afficher juste à côté
    @param [IN] img_deplacer : SDL_Surface de l'image à afficher plus loin
    @param [IN,OUT] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheCasesAutour(const Plateau* p, const Case* c, SDL_Surface* img_dupliquer, SDL_Surface* img_deplacer, SDL_Surface* ecran);

#endif
