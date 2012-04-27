#ifndef _PLATEAU
#define _PLATEAU

#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

#include "Case.h"

typedef struct
{
    /* nombre de pions déja placés */
    int nb_piece_mise;
	/* nombre de places libres sur le support */
	int places_libres;
	/* nombre de places au total sur le plateau (pour les boucles) */
	int capacite;
	/* tableau de pointeurs de cases pour le jeu */
	Case** support;
	/* scores des 2 joueurs */
	int score_j1;
	int score_j2;
} Plateau;


/**
    @brief Definit quel joueur a une piece sur la case

    @param [IN] p : pointeur sur le plateau
    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] joueur : numero 1 ou 2 du joueur. Mettre 0 rendre la case libre

    @return void
*/
void changeJoueur(Plateau* p, Case* c, int joueur);


/**
    @brief Initialise le plateau

    @param [IN,OUT] p : pointeur sur le plateau
    @param [IN] capacite : nombre max de cases sur le plateau

    @return void
*/
void plateauInit(Plateau* p, int capacite);


/**
    @brief Décrémente le nombre de place libre quand un joueur duplique sa pièce

    @param [IN] p : pointeur sur plateau

    @return void
*/
void decrementePlacesLibres(Plateau* p);


/**
    @brief Retourne le nombre de places libres sur le plateau

    @param [IN] p : pointeur sur plateau

    @return nombre de places
*/
int getPlacesLibres(Plateau* p);


/**
    @brief Affiche toutes les pièces (des joueurs) du plateau

    @param [IN] p : pointeur sur plateau

    @return void
*/
void affichePiece(Plateau* p);


/**
    @brief Afficher tout le plateau

    @param [IN] p : plateau à afficher

    @return void
*/
void affichePlateau(Plateau* p);


/**
    @brief Dessine le pion du joueur 1 à une position donnée

    @param [IN] posX : position selon l'axe X
    @param [IN] posY : position selon l'axe Y

    @return void
*/
void dessinepion1(int posX,int posY);


/**
    @brief Dessine le pion du joueur 2 à une position donnée

    @param [IN] posX : position selon l'axe X
    @param [IN] posY : position selon l'axe Y

    @return void
*/
void dessinepion2(int posX,int posY);


/**
    @brief dessine une case du terrain à une position donnée

    @param [IN] posX : position selon l'axe X
    @param [IN] posY : position selon l'axe Y

    @return void
*/
void dessineCase(float posX,float posY,int C);


/**
    @brief Détermine si la souris est dans "un cercle" d'une case

    @param [IN] sx : position x de la souris
    @param [IN] sy : position y de la souris
    @param [IN] c : Case à tester

    @return int (booléen)
*/
int sourisDansCase(int sx, int sy, const Case* c);


/**
    @brief Détermine quelle case est survollée

    @param [IN] sx : Position x de la souris
    @param [IN] sy : Position y de la souris
    @param [IN] p : Pointeur sur Plateau

    @return pointeur sur la case survollée, ou 0 si aucune survollée
*/
Case* caseSurvollee(int sx, int sy, const Plateau* p);


/**
    @brief Lire un fichier pour charger un plateau

    @param [IN,OUT] p : pointeur sur le plateau a remplir
    @param [IN] filename : nom du fichier texte à charger

    @return void
*/
void lirePlateau(Plateau* p, const char filename[]);


/**
    @brief Afficher les cases autour d'un case donnée

    @param [IN] p : pointeur sur le plateau
    @param [IN] c : case

    @return void
*/
void casesAutour(const Plateau* p,Case* c);


/**
    @brief Nombre de possibilités de déplacement pour un pion

    @param [IN] p : pointeur sur Plateau
    @param [IN] c : pointeur sur case

    @return void
*/
int nbPossibilites(const Plateau* p,Case* c);


/**
    @brief Retourne une valeur selon la distance entre un clic et le clic suivant:
           si le joueur clic à une distance de 1 il duplique sa pièce
           si le joueur clic à une distance de 2 il déplace sa pièce
           sinon c'est un clic normal.

    @param [IN] x : position x de la case
    @param [IN] y : position y de la case

    @return Un entier :1 si elle est à distance = 1, 2 si elle est à distance = 2, 0 sinon
 *
 */
int testCaseProche(int x,int y);


/**
    @brief Transforme les pièces situées autour de la case où le joueur joue

    @param [IN] p : pointeur sur le plateau
    @param [IN] c : pointeur sur une Case
    @param joueur : le joueur en cours

    @return void
*/
void changeCasesAutour(Plateau* p,Case* c,int joueur);


/**
    @brief Changer le score d'un joueur

    @param [IN,OUT] p : pointeur sur un plateau
    @param [IN] joueur : numéro du joueur

    @return void
*/
void changeScoreJoueur(Plateau* p, int joueur, int dec);


/**
    @brief Retourner le score d'un joueur

    @param [IN] p : pointeur sur Plateau
    @param [IN] j : numéro du joueur
*/
int getScore(const Plateau* p, int j);


/**
    @brief Déterminer si un joueur peut déplacer un de ses pions.

    @param [IN] p : Pointeur sur Plateau
    @param [IN] j : numéro du joueur

    @return void
*/
int peutJouer(const Plateau* p, int j);


/**
    @brief Remplir toutes les cases libres avec les pions du joueur

    @param [IN,OUT] p : Pointeur sur Plateau
    @param [IN] j : numéro du joueur

    @return void
*/
void remplirPlateau(Plateau* p, int j);

#endif
