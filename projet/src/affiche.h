#ifndef _AFFICHE
#define _AFFICHE

#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "parametres.h"
#include "Case.h"
#include "Plateau.h"

/* renommage des types pour la modularité */
typedef SDL_Rect Rectangle;
typedef SDL_Surface Image;
typedef SDL_Event Evenements;
typedef SDLKey Touche;
typedef Uint8 EvenementsType;



/* renommage des constantes pour la modularité */
#define AFFICHE_FIN SDL_QUIT

#define EVENT_SOURISBOUGE SDL_MOUSEMOTION
#define EVENT_SOURISCLIC SDL_MOUSEBUTTONDOWN
#define EVENT_TOUCHEENFONCEE SDL_KEYDOWN

#define T_ECHAP SDLK_ESCAPE
#define T_ECHAP SDLK_ESCAPE
#define T_ESPACE SDLK_SPACE
#define T_GAUCHE SDLK_LEFT
#define T_DROITE SDLK_RIGHT
#define T_HAUT SDLK_UP
#define T_BAS SDLK_DOWN
#define T_PN_ENTREE SDLK_KP_ENTER
#define T_ENTREE SDLK_RETURN
#define T_PN_PLUS SDLK_KP_PLUS
#define T_PN_MOINS SDLK_KP_MINUS
#define T_h SDLK_h

/**
    @brief <b>Convertir x,y en Rectangle.</b><br />
    Transforme des coordonnées x,y de cases en un Rectangle pour l'afficher éventuellement ensuite.

    @param [in] x : coordonnée x
    @param [in] y : coordonnée y

    @return Rectangle
*/
Rectangle xy2rect(int x, int y);


/**
    @brief <b>Inisialiser l'affichage.</b>

    @return entier
*/
int afficheInit();

/**
    @brief <b>Afficher les scores des joueurs.</b><br />
    Affiche, pendant la partie, les scores respectifs des 2 joueurs.

    @param [in] s1 : score du joueur 1
    @param [in] s2 : score du joueur 2
    @param [in] chiffres : Pointeur sur le tableau d'images de chiffres
    @param [in] haut : Pointeur sur l'image à afficher au dessus des scores
    @param [in] pion_j1 : Pointeur sur l'image du pion du joueur 1
    @param [in] pion_j2 : Pointeur sur l'image du pion du joueur 2
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheScores(int s1, int s2, Image* chiffres[], Image* haut, Image* pion_j1, Image* pion_j2, Image* ecran);


/**
    @brief <b>Afficher le niveau de l'ordinateur sur le menu.</b><br />
    Affiche le niveau de l'ordinateur à l'écran pour permettre à l'utilisateur de choisir.

    @param [in] x : coordonnée x en pixels
    @param [in] y : coordonnée y en pixels
    @param [in] niv : valeur du niveau
    @param [in] chiffre : Image (tableau de chiffres 0-9)
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheNiveauOrdinateur(int x, int y, int niv, Image* chiffre[], Image* ecran);


/**
    @brief <b>Afficher quel joueur à la main.</b><br />
    Afficher une image à l'écran pour savoir qui doit jouer.

    @param [in] j : joueur
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheQuiJoue(int j, Image* ecran);


/**
    @brief <b>Affiche bravo au joueur gagnant.</b><br />
    Fonction qui permet d'afficher à l'écran une image pour indiquer qui gagne.<br />
    Cette fonction est appelée à la fin de la partie.

    @param [in] s1 : score du joueur 1
    @param [in] s2 : score du joueur 2
    @param [in] ordi : 1 si on a joué contre l'ordi
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheFinJeu(int s1, int s2, int ordi, Image* ecran);


/**
    @brief <b>Afficher une image à partir de coordonnées.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir de coordonnées en pixels

    @param [in] x : coordonnée X en pixels
    @param [in] y : coordonnée Y en pixels
    @param [in] image : image à afficher
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheImage(int x, int y, Image* image, Image* ecran);


/**
    @brief <b>Afficher une image avec Rectangle.</b><br />
    Fonction qui permet d'afficher à l'écran une image à partir d'une position Rectangle

    @param [in] rect : coordonnée SDL en pixels
    @param [in] image : image à afficher
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheImageRect(Rectangle rect, Image* image, Image* ecran);


/**
    @brief <b>Afficher le plateau.</b><br />
    Affiche toutes les cases du plateau de jeu.<br />
    Affiche ensuite les pions des joueurs aux endroits où ils se trouvent.

    @param [in] p : Pointeur sur Plateau
    @param [in] image_case : Image image d'une case vide
    @param [in] pion_j1 : Image image du pion du joueur 1
    @param [in] pion_j2 : Image image du pion du joueur 2
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheJeu(const Plateau* p, Image* image_case, Image* pion_j1, Image* pion_j2, Image* ecran);


/**
    @brief <b>Vérifier qu'un image est bien chargée.</b><br />
    Affiche une erreur et arrête l'execution du jeu.

    @param [in] img : pointeur sur une Image

    @return rien
*/
void afficheVerifChargement(Image* img);


/**
    @brief <b>Afficher une case du plateau</b><br />
    Affiche à l'écran une case du plateau

    @param [in] c : Pointeur sur Case
    @param [in] image : Image image de case à afficher
    @param [in,out] ecran : Image de l'écran

    @return rien

*/
void afficheCaseJeu(const Case* c, Image* image, Image* ecran);


/**
    @brief <b>Afficher les cases joueables autour de c</b><br />
    Affiche des cases en couleurs là où le joueur peut poser son pion.

    @param [in] p : Pointeur sur Plateau
    @param [in] c : Pointeur sur Case
    @param [in] img_dupliquer : Image de l'image à afficher juste à côté
    @param [in] img_deplacer : Image de l'image à afficher plus loin
    @param [in,out] ecran : Image de l'écran

    @return rien
*/
void afficheCasesAutour(const Plateau* p, const Case* c, Image* img_dupliquer, Image* img_deplacer, Image* ecran);


/**
    @brief <b>Libérer une image.</b><br />
    Vider la mémoire.

    @param [in,out] img : Image à effacer

    @return rien
*/
void afficheFree(Image* img);


/**
    @brief <b>Fermer l'affichage.</b>
    Arrêter les fonctions d'affichage.

    @return rien
*/
void afficheQuit();


/**
    @brief <b>Lave l'écran</b><br />
    et n'affiche qu'une couleur de fond

    @param [in,out] ecran : Image de l'écran à laver
*/
void afficheVideEcran(Image* ecran);


/**
    @brief <b>Charger une image.</b><br />
    Charger un fichier image en mémoire et retourner un pointeur.

    @param [in] fichier : url du fichier à charger

    @return pointeur sur Image
*/
Image* afficheChargeImage(char fichier[]);


/**
    @brief <b>Détecter les événements.</b><br />

    @param [out] ev : pointeur sur Evenements

    @return 1 si événement(s) et 0 si rien
*/
int afficheEvenements(Evenements* ev);


/**
    @brief <b>Touche enfoncée.</b><br />
    Retourne quelle touche est appuyée.

    @param [in] ev : pointeur sur Evenements

    @return code d'une touche
*/
Touche afficheToucheAppuyee(Evenements* ev);


/**
    @brief <b>Coordonnée de la souris.</b>
    Retourne une des coordonnées de la souris.

    @param [in] ev : pointeur sur Evenements
    @param [in] char : x ou y selon la coordonnée souhaitée

    @return coordonnée positive
*/
int afficheCoordonneeSouris(Evenements* ev, char coord);


/**
    @brief <b>Changer l'écran.</b><br />
    Mettre à jour l'écran avec les images à afficher.

    @param [in] ecran : pointeur sur Image

    @return rien
*/
void afficheMiseAJour(Image* ecran);


/**
    @brief <b>Initialiser l'écran.</b>

    @return pointeur sur Image
*/
Image* afficheSetEcran();


/**
    @brief <b>Affiche l'erreur.</b><br />
    Affiche des détails sur une erreur qui s'est produite.

    @return rien
*/
void afficheErreur();


/**
    @brief <b>Change le titre de la fenêtre.</b>

    @param [in] titre1 : Titre en haut de la fenêtre
    @param [in] titre2 : Titre dans la barre de tâches

    @return rien
*/
void afficheSetTitre(char titre1[], char titre2[]);


/**
    @brief <b>Type d'événement.</b><br />
    Type d'événement pour la boucle.

    @param [in] ev : pointeur sur Evenement

    @return type d'événement
*/
EvenementsType afficheTypeEvenement(Evenements* ev);


/**
    @brief <b>Determine si la position de la souris est dans un rectangle</b>

    @param [in] x : position x de la souris
    @param [in] y : position y de la souris
    @param [in] rectangle : rectangle pour tester

    @return booléen (1 ou 0)
*/
int sourisDansRectangle(int x, int y, Rectangle rectangle);


#endif
