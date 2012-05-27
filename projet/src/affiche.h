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

    @param [in] x : coordonnée x
    @param [in] y : coordonnée y

    @return SDL_Rect
*/
SDL_Rect xy2rect(int x, int y);


/**
    @brief <b>Afficher les scores des joueurs.</b><br />
    Affiche, pendant la partie, les scores respectifs des 2 joueurs.

    @param [in] s1 : score du joueur 1
    @param [in] s2 : score du joueur 2
    @param [in] chiffres : Pointeur sur le tableau d'images de chiffres
    @param [in] haut : Pointeur sur l'image à afficher au dessus des scores
    @param [in] pion_j1 : Pointeur sur l'image du pion du joueur 1
    @param [in] pion_j2 : Pointeur sur l'image du pion du joueur 2
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief <b>Afficher le niveau de l'ordinateur sur le menu.</b><br />
    Affiche le niveau de l'ordinateur à l'écran pour permettre à l'utilisateur de choisir.

    @param [in] x : coordonnée x en pixels
    @param [in] y : coordonnée y en pixels
    @param [in] niv : valeur du niveau
    @param [in] chiffre : SDL_Surface (tableau de chiffres 0-9)
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheNiveauOrdinateur(int x, int y, int niv, SDL_Surface* chiffre[], SDL_Surface* ecran);


/**
    @brief <b>Afficher quel joueur à la main.</b><br />
    Afficher une image à l'écran pour savoir qui doit jouer.

    @param [in] j : joueur
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheQuiJoue(int j, SDL_Surface* ecran);


/**
    @brief <b>Affiche bravo au joueur gagnant.</b><br />
    Fonction qui permet d'afficher à l'écran une image pour indiquer qui gagne.<br />
    Cette fonction est appelée à la fin de la partie.

    @param [in] s1 : score du joueur 1
    @param [in] s2 : score du joueur 2
    @param [in] ordi : 1 si on a joué contre l'ordi
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheFinJeu(int s1, int s2, int ordi, SDL_Surface* ecran);


/**
    @brief <b>Afficher une image à partir de coordonnées.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir de coordonnées en pixels

    @param [in] x : coordonnée X en pixels
    @param [in] y : coordonnée Y en pixels
    @param [in] image : image à afficher
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheImage(int x, int y, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher une image avec SDL_Rect.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir d'une position SDL_Rect

    @param [in] rect : coordonnée SDL en pixels
    @param [in] image : image à afficher
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheImageRect(SDL_Rect rect, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher le plateau.</b><br />
    Affiche toutes les cases du plateau de jeu.<br />
    Affiche ensuite les pions des joueurs aux endroits où ils se trouvent.

    @param [in] p : Pointeur sur Plateau
    @param [in] image_case : SDL_Surface image d'une case vide
    @param [in] pion_j1 : SDL_Surface image du pion du joueur 1
    @param [in] pion_j2 : SDL_Surface image du pion du joueur 2
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheJeu(const Plateau* p, SDL_Surface* image_case, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran);


/**
    @brief <b>Vérifier qu'un image est bien chargée.</b><br />
    Affiche une erreur et arrête l'execution du jeu.

    @param [in] img : pointeur sur une SDL_Surface

    @return rien
*/
void afficheVerifChargement(SDL_Surface* img);


/**
    @brief <b>Afficher une case du plateau</b><br />
    Affiche à l'écran une case du plateau

    @param [in] c : Pointeur sur Case
    @param [in] image : SDL_Surface image de case à afficher
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien

*/
void afficheCaseJeu(const Case* c, SDL_Surface* image, SDL_Surface* ecran);


/**
    @brief <b>Afficher les cases joueables autour de c</b><br />
    Affiche des cases en couleurs là où le joueur peut poser son pion.

    @param [in] p : Pointeur sur Plateau
    @param [in] c : Pointeur sur Case
    @param [in] img_dupliquer : SDL_Surface de l'image à afficher juste à côté
    @param [in] img_deplacer : SDL_Surface de l'image à afficher plus loin
    @param [in,out] ecran : SDL_Surface de l'écran

    @return rien
*/
void afficheCasesAutour(const Plateau* p, const Case* c, SDL_Surface* img_dupliquer, SDL_Surface* img_deplacer, SDL_Surface* ecran);

#endif
