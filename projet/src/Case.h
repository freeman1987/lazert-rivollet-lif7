#ifndef _CASE
#define _CASE
#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    /* savoir si la case est libre ou occupée par un joueur */
	int libre;
	/* définit si une case est accessible ou non
	(par exemple pour faire des trous sur le plateau) */
	int accessible;
	/* numéro du joueur qui possède le pion */
	int joueur;
	/* coordonnées du pion sur le support */
	int posX;
	int posY;
}Case;

/**
    @brief alloue de la memoire dans le tas et retourne l'adresse

    @return pointeur sur case
*/
Case* caseInit();

/**
    @brief Definit quel joueur a une piece sur la case

    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] joueur : numero 1 ou 2 du joueur. Mettre 0 rendre la case libre

    @return void
*/
void changeJoueur(Case* c, int joueur);


/**
    @brief Donner une position x,y a une case

    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] x : position horizontale
    @param [IN] y : position verticale

    @return void
*/
void setPos(Case* c, int x, int y);


/**
    @brief Savoir si une case est libre

    @param [IN] case : pointeur sur case

    @return 1 si la case et libre et 0 sinon
*/
int getLibre(const Case* c);

/**
    @brief Savoir si une case est accessible

    @param [IN] case : pointeur sur case

    @return 1 si la case et accessible et 0 sinon
*/
int getAccessible(const Case* c);


/**
    @brief Retourne le joueur qui a un pion sur la case

    @param c : pointeur sur case

    @return numero du joueur
*/
int getJoueur(const Case* c);


/**
    @brief Retourne la coordonnee X

    @param c : pointeur sur case

    @return coordonnee entiere
*/
int getX(const Case* c);


/**
    @brief Retourne la coordonnee Y

    @param c : pointeur sur case

    @return coordonnee entiere
*/
int getY(const Case* c);


#endif
