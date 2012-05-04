#ifndef _PLATEAU
#define _PLATEAU

#include "parametres.h"
#include "Case.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct
{
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
    @brief Initialise le plateau

    @param [IN,OUT] p : pointeur sur le plateau
    @param [IN] capacite : nombre max de cases sur le plateau

    @return void
*/
void plateauInit(Plateau* p, int capacite);


/**
    @brief Definit quel joueur a une piece sur la case
    On modifie aussi les scores des joueurs.

    @param [IN] p : pointeur sur le plateau
    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] joueur : numero 1 ou 2 du joueur. Mettre 0 rendre la case libre

    @return void
*/
void plateauChangeJoueur(Plateau* p, Case* c, int joueur);


/**
    @brief Décrémente le nombre de place libre quand un joueur duplique sa pièce

    @param [IN] p : pointeur sur plateau

    @return void
*/
void plateauDecrementePlacesLibres(Plateau* p);


/**
    @brief Retourne le nombre de places libres sur le plateau

    @param [IN] p : pointeur sur plateau

    @return nombre de places
*/
int plateauGetPlacesLibres(Plateau* p);


/**
    @brief Retourner le nombre de cases

    @param [IN] p : Pointeur sur Plateau

    @return int
*/
int plateauGetCapacite(const Plateau* p);


/**
    @brief Retourner la case i du plateau (utile pour les boucles)

    @param [IN] p : Pointeur sur Plateau
    @param [IN] i : 0 <= entier < capacité

    @return Pointeur sur Case (ou nul si i est incorrect)
*/
Case* plateauGetCaseI(const Plateau* p, int i);


/**
    @brief Détermine si la souris est dans "un cercle" d'une case

    @param [IN] sx : position x de la souris
    @param [IN] sy : position y de la souris
    @param [IN] c : Case à tester
    @param [IN] dim : taille d'une case (hauteur ou largeur)

    @return int (booléen)
*/
int plateauSourisDansCase(int sx, int sy, const Case* c, int dim);


/**
    @brief Détermine quelle case est survollée

    @param [IN] sx : Position x de la souris
    @param [IN] sy : Position y de la souris
    @param [IN] p : Pointeur sur Plateau
    @param [IN] dim : taille d'une case (hauteur ou largeur)

    @return pointeur sur la case survollée, ou 0 si aucune survollée
*/
Case* plateauCaseSurvollee(int sx, int sy, const Plateau* p, int dim);


/**
    @brief Lire un fichier pour charger un plateau

    @param [IN,OUT] p : pointeur sur le plateau a remplir
    @param [IN] filename : nom du fichier texte à charger

    @return void
*/
void plateauLireFichier(Plateau* p, const char filename[]);


/**
    @brief Nombre de possibilités de déplacement pour un pion

    @param [IN] p : pointeur sur Plateau
    @param [IN] c : pointeur sur case

    @return void
*/
int plateauNbPossibilites(const Plateau* p,Case* c);


/**
    @brief Retourne une valeur selon la distance entre un clic et le clic suivant:
           si le joueur clic à une distance de 1 il duplique sa pièce
           si le joueur clic à une distance de 2 il déplace sa pièce
           sinon c'est un clic normal.

    @param [IN] x : position x de la case
    @param [IN] y : position y de la case

    @return int : 1 si elle est à distance = 1, 2 si elle est à distance = 2, 0 sinon
 *
 */
int plateauTestCaseProche(int x,int y);


/**
    @brief Transforme les pièces situées autour de la case où le joueur joue

    @param [IN] p : pointeur sur Plateau
    @param [IN] c : pointeur sur une Case
    @param joueur : le joueur en cours

    @return void
*/
void plateauVolerPions(Plateau* p, Case* c, int joueur);


/**
    @brief Compte le nombre de pions adverses à voler autour d'une case

    @param [IN] p : Pointeur sur Plateau
    @param [IN] c : Pointeur sur une Case
    @param joueur : le joueur en cours

    @return int
*/
int plateauNbPionsAVoler(Plateau* p, Case* c, int joueur);

/** \brief Compte le nombre de pions que l'ordinateur perdra s'il bouge son pion

    @param [IN] p : Pointeur sur Plateau
    @param [IN] c : Pointeur sur une Case
    @param joueur : le joueur en cours

    @return int

 */
int plateauNbPionsPerdu(Plateau* p, Case* c, int joueur);

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

    @return int (score > 0)
*/
int plateauGetScore(const Plateau* p, int j);


/**
    @brief Déterminer si un joueur peut déplacer un de ses pions.

    @param [IN] p : Pointeur sur Plateau
    @param [IN] j : numéro du joueur

    @return int (boléen)
*/
int plateauPeutJouer(const Plateau* p, int j);


/**
    @brief Remplir toutes les cases libres avec les pions du joueur

    @param [IN,OUT] p : Pointeur sur Plateau
    @param [IN] j : numéro du joueur

    @return void
*/
void plateauRemplirPions(Plateau* p, int j);


/**
    @brief Libérer la mémoire proprement

    @param [IN] p : Pointeur sur Plateau

    @return void
*/
void plateauTestament(Plateau* p);

#endif
