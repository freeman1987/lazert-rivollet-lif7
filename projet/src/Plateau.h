#ifndef _PLATEAU
#define _PLATEAU

#include "parametres.h"
#include "Case.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/**
    @struct Plateau
    @brief <b>Structure du plateau de jeu</b>
*/
typedef struct
{
	int places_libres; /*!< <b>Nombre de places libres sur le support</b> */
	int capacite; /*!< <b>Nombre de places au total sur le plateau</b> (pour les boucles) */
	Case** support; /*!< <b>Tableau de pointeurs de cases pour le jeu</b> */
	int score_j1; /*!< <b>Score du joueur 1</b> */
	int score_j2; /*!< <b>Score du joueur 2</b> */
} Plateau;


/**
    @brief <b>Initialise le plateau.</b><br />
    Initialise les valeurs du plateau à 0 sauf la capacité (en paramètre).<br />
    Alloue dans le tas suffisemment d'espace pour les cases du plateau.

    @param [in,out] p : pointeur sur le plateau
    @param [in] capacite : nombre max de cases sur le plateau

    @return rien
*/
void plateauInit(Plateau* p, int capacite);


/**
    @brief <b>Definit quel joueur a une piece sur la case.</b><br />
    On modifie aussi les scores des joueurs.

    @param [in] p : pointeur sur le plateau
    @param [in,out] c : pointeur sur la case à modifier
    @param [in] joueur : numero 1 ou 2 du joueur. Mettre 0 rendre la case libre

    @return rien
*/
void plateauChangeJoueur(Plateau* p, Case* c, int joueur);


/**
    @brief <b>Décrémente le nombre de place libre</b><br />
    quand un joueur duplique sa pièce.

    @param [in,out] p : pointeur sur plateau

    @return void
*/
void plateauDecrementePlacesLibres(Plateau* p);


/**
    @brief <b>Retourne le nombre de places libres sur le plateau.</b><br />
    Afin de savoir s'il y a encore de la place pour jouer.

    @param [in] p : pointeur sur plateau

    @return nombre de places
*/
int plateauGetPlacesLibres(const Plateau* p);


/**
    @brief <b>Retourner le nombre de cases.</b><br />
    Utile principalement pour les boucles de parcours du plateau.

    @param [in] p : Pointeur sur Plateau

    @return entier
*/
int plateauGetCapacite(const Plateau* p);


/**
    @brief <b>Retourner la case i du plateau.</b><br />
    Utile pour les boucles de parcours du plateau.

    @param [in] p : Pointeur sur Plateau
    @param [in] i : 0 <= entier < capacité

    @return Pointeur sur Case (ou nul si i est incorrect)
*/
Case* plateauGetCaseI(const Plateau* p, int i);


/**
    @brief <b>Détermine si la souris est dans "un cercle" d'une case</b><br />
    Pour savoir si l'utilisateur à cliqué dans une case.<br />
    <em>Méthode assez précise.</em>

    @param [in] sx : position x de la souris
    @param [in] sy : position y de la souris
    @param [in] c : Case à tester
    @param [in] dim : taille d'une case (hauteur ou largeur)

    @return booléen (0 ou 1)
*/
int plateauSourisDansCase(int sx, int sy, const Case* c, int dim);


/**
    @brief <b>Détermine quelle case est survollée.</b><br />
    Pointeur sur la case survollée si une case est survollée.

    @param [in] sx : Position x de la souris
    @param [in] sy : Position y de la souris
    @param [in] p : Pointeur sur Plateau
    @param [in] dim : taille d'une case (hauteur ou largeur)

    @return pointeur sur Case, ou 0 si aucune survollée
*/
Case* plateauCaseSurvollee(int sx, int sy, const Plateau* p, int dim);


/**
    @brief <b>Lire un fichier pour charger un plateau.</b><br />
    Lire le contenu d'un fichier normalisé pour charger un plateau en mémoire.<br />
    Contenu du fichier :<br />
    première ligne : nombre de lignes à lire<br />
    lignes suivantes : 3 valeurs séparées par des virgules : x,y,j<br />
    - x : coordonnée x de la case<br />
    - y : coordonnée y de la case<br />
    - j : joueur sur la case (0 pour aucun, 1 ou 2 sinon)

    @param [in,out] p : pointeur sur le plateau à remplir
    @param [in] filename : nom du fichier texte à charger

    @return rien
*/
void plateauLireFichier(Plateau* p, const char filename[]);


/** \brief Sauvegarde la partie en cour dans un fichier texte
 *
 * \param [in,out] p : pointeur sur le plateau à remplir

 * \return rien
 *
 */
void plateauEcrireFichier(Plateau* p);

/**
    @brief <b>Nombre de possibilités de déplacement pour un pion.</b><br />
    Possibilités de déplacement ou de duplication dans les cases aux alentours.

    @param [in] p : pointeur sur Plateau
    @param [in] c : pointeur sur case

    @return rien
*/
int plateauNbPossibilites(const Plateau* p,Case* c);


/**
    @brief <b>Retourne une valeur selon la distance entre 2 Cases.</b><br />
    Détails sur la valeur de retour :<br />
    - 1 : les cases se touchent (le joueur peut dupliquer)<br />
    - 2 : les cases sont séparées par une autre (le joueur peut déplacer sa pièce)<br />
    - 0 : les cases sont séparées par plus d'une case (le joueur ne peut pas jouer)<br />
    <br />
    Les valeurs x et y correspondent aux différences<br />
    entre les coordonnées des cases x = x1 - x0 et y = y1 - y0

    @param [in] x : position x de la case
    @param [in] y : position y de la case

    @return entier : 1 si elle est à distance = 1, 2 si elle est à distance = 2, 0 sinon
 */
int plateauTestCaseProche(int x,int y);


/**
    @brief <b>Transforme les pièces situées autour de la case où le joueur joue.</b><br />
    Change les pions du joueur adverse en ceux de celui qui vient de jouer

    @param [in] p : pointeur sur Plateau
    @param [in] c : pointeur sur une Case
    @param joueur : le joueur en cours

    @return rien
*/
void plateauVolerPions(Plateau* p, Case* c, int joueur);


/**
    @brief <b>Compte le nombre de pions adverses à voler autour d'une case.</b><br />
    Pour savoir combien de pions adverses on peut voler en joueant dans la Case.

    @param [in] p : Pointeur sur Plateau
    @param [in] c : Pointeur sur une Case
    @param joueur : le joueur en cours

    @return entier
*/
int plateauNbPionsAVoler(Plateau* p, Case* c, int joueur);

/**
    @brief <b>Compte le nombre de pions adverses adjacents à deux cases.</b><br />
    Cela permet de savoir combien de pion on peut se faire voler en supposant l'action effectuée.


    @param [in] p : Pointeur sur Plateau
    @param [in] c1 : Pointeur sur une Case
    @param [in] c2 : Pointeur sur une Case
    @param joueur : le joueur en cours

    @return entier
*/
int plateauNbPionsAVolerAdjacent(Plateau* p, Case* c1, Case* c2, int joueur);


/**
    @brief <b>Compte le nombre de pions que l'on peut perdre en partant.</b><br />
    Détermine le nombre de pions à perdre s'il on enlèce son pion de la Case.

    @param [in] p : Pointeur sur Plateau
    @param [in] c : Pointeur sur une Case
    @param joueur : le joueur en cours

    @return entier

 */
int plateauNbPionsPerdu(Plateau* p, Case* c, int joueur);

/**
    @brief <b>Changer le score d'un joueur.</b>

    @param [in,out] p : pointeur sur un plateau
    @param [in] joueur : numéro du joueur
    @param [in] dec : valeur à ajouter au score (négative pour diminuer le score)

    @return rien
*/
void changeScoreJoueur(Plateau* p, int joueur, int dec);


/**
    @brief <b>Retourner le score d'un joueur.</b><br />
    Pour connaitre le score de l'un des joueurs

    @param [in] p : pointeur sur Plateau
    @param [in] j : numéro du joueur

    @return entier positif
*/
int plateauGetScore(const Plateau* p, int j);


/**
    @brief <b>Déterminer si un joueur peut déplacer un de ses pions.</b><br />
    Permet de savoir si un joueur est bloqué, auquel cas la partie doit s'arrêter.

    @param [in] p : Pointeur sur Plateau
    @param [in] j : numéro du joueur

    @return booléen (0 ou 1)
*/
int plateauPeutJouer(const Plateau* p, int j);


/**
    @brief <b>Remplir toutes les cases libres avec un pion.</b><br />
    Si un joueur est bloqué, on remplit les cases libres du plateau avec les pions adverses.

    @param [in,out] p : Pointeur sur Plateau
    @param [in] j : numéro du joueur

    @return rien
*/
void plateauRemplirPions(Plateau* p, int j);


/**
    @brief <b>Détruire le plateau.</b><br />
    Libérer la mémoire proprement, détruitre toutes les cases.<br />
    Fixer la capacité à 0.

    @param [in,out] p : Pointeur sur Plateau

    @return rien
*/
void plateauTestament(Plateau* p);


/**
    @brief <b>Compter le nombre de pions ennemis autour d'une case</b><br />
    Compter combien d'ennemis se trouvent autour de la Case.

    @param [in] p : Pointeur sur Plateau
    @param [in] c : Pointeur sur Case
    @param [in] joueur : numéro du joueur à ne pas prendre en compte

    @return entier
*/
int plateauNbPionEnnemi(const Plateau* p, const Case* c, int joueur);


/**
    @brief <b>Tests de non-régression de Plateau.</b><br />
    Vérifier le module Plateau en appelant les différentes fonctions.

    @return rien
*/
void plateauTestRegression(void);

#endif
