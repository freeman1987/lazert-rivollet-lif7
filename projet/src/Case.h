#ifndef _CASE
#define _CASE

typedef struct
{
	/* il y a un pion ici */
	int libre;
	/* définit si une case est accessible ou non
	(par exemple pour faire des trous sur le plateau) */
	int accessible;
	/* numéro du joueur qui possède le pion */
	int joueur;
	/* coordonnées du pion sur le support */
	int posX;
	int posY;
} Case;

#endif
