#ifndef _CASE
#define _CASE
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

#endif
