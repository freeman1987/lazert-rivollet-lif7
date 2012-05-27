#ifndef _CASE
#define _CASE

#include "parametres.h"

#include <stdlib.h>
#include <stdio.h>

/**
    @struct Case
    @brief <b>Structure pour les cases du plateau de jeu</b>
*/
typedef struct
{

	int libre; /*!< <b>Savoir si la case est libre ou occupée par un joueur</b> */
	int joueur; /*!< <b>Numéro du joueur qui possede le pion</b> */
	int posX; /*!< <b>Coordonnée x du pion sur le support</b> */
	int posY; /*!< <b>Coordonnée y du pion sur le support</b> */
}Case;

/**
    @brief <b>Initialiser une case.</b><br />
    Alloue de la memoire dans le tas et retourne l'adresse

    @return pointeur Case
*/
Case* caseInit(void);


/**
    @brief <b>Déterminer une position x,y a une case.</b><br />
    Fixer les coordonnées d'une case.

    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] x : position horizontale
    @param [IN] y : position verticale

    @return rien
*/
void caseSetPos(Case* c, int x, int y);


/**
    @brief <b>Savoir si une case est libre.</b><br />
    Savoir si une case est libre ou occupée par un joueur.

    @param [IN] case : pointeur sur case

    @return 1 si la case est libre et 0 sinon
*/
int caseGetLibre(const Case* c);


/**
    @brief <b>Rendre libre ou non une case</b><br />
    Si val vaut 0, la case devient libre.<br />
    Dans tous les cas, le pion du joueur est effacé.

    @param [IN,OUT] c : pointeur sur la case a modifier
    @param [IN] val : booléen : libre ou non

    @return rien
*/
void caseSetLibre(Case* c, int val);


/**
    @brief <b>Retourne le joueur qui a un pion sur la case.</b>

    @param [IN] c : pointeur sur case

    @return numero du joueur
*/
int caseGetJoueur(const Case* c);


/**
    @brief <b>Modifier le joueur qui a un pion sur la case</b><br />
    Changer la valeur du joueur qui est sur la case.

    @param [IN,OUT] c : pointeur sur case
    @param [IN] j : numéro du joueur

    @return void
*/
void caseSetJoueur(Case* c, int j);


/**
    @brief <b>Retourne la coordonnée x.</b><br />
    Abscisse la case sur la plateau.

    @param [IN] c : pointeur sur case

    @return coordonnée entiere
*/
int caseGetX(const Case* c);


/**
    @brief <b>Retourne la coordonnée y.</b><br />
    Ordonnée de la case.

    @param [IN] c : pointeur sur case

    @return coordonnee entiere
*/
int caseGetY(const Case* c);


/**
    @brief <b>Tester les coordonnées</b><br />
    Comparer les coordonnées en paramètres avec celles de la case.

    @param [IN] c : Pointeur sur Case
    @param [IN] sx : coordonnée horizontale
    @param [IN] sy : coordonnée verticale

    @return booléen (0 ou 1)
*/
int caseTestCoordonnees(Case* c,int sx,int sy);


/**
    @brief <b>Détruire la case</b><br />
    Libérer la mémoire.

    @param [IN] c : Pointeur sur la case à détruire

    @return rien
*/
void caseTestament(Case* c);


/**
    @brief <b>Test de non-régression de Case</b><br />
    Vérifier le module Case en appelant les différentes fonctions.

    @return rien
*/
void caseTestRegression(void);

#endif
