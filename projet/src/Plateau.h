#ifndef _PLATEAU
#define _PLATEAU

#include "parametres.h"
#include <stdlib.h>
#include <stdio.h>

#include "Case.h"

typedef struct
{
	/* nombre de places libres sur le support */
	int places_libres;
	/* nombre de places sur le plateau */
	int capacite;
	/* tableau de pointeurs de cases pour le jeu */
	Case** support;
} Plateau;


/**
    @brief Initialise le plateau
*/
void plateauInit(Plateau* p, int capacite);


/**
    @brief Retourne le nombre de places libres sur le plateau

    @param [IN] p : pointeur sur plateau

    @return nombre de places
*/
int getPlacesLibres(const Plateau* p);

/** \brief Affiche toutes les pièces du plateau
 *
 * \param [in] p : pointeur sur plateau

 * \return void
 *
 */
void affichePiece(Plateau* p);

/** \brief Dissine le pion du joueur 1 à une position donnée
 *
 * \param [in] posX : position selon l'axe X
 * \param [in] posY : position selon l'axe Y

 * \return void
 *
 */
void dessinepion1(int posX,int posY);

/** \brief Dissine le pion du joueur 2 à une position donnée
 *
 * \param [in] posX : position selon l'axe X
 * \param [in] posY : position selon l'axe Y

 * \return void
 *
 */
void dessinepion2(int posX,int posY);

/** \brief dessine une case du terrain à une position donnée
 *
 * \param [in] posX : position selon l'axe X
 * \param [in] posY : position selon l'axe Y

 * \return void
 *
 */
void dessineTerrain(int posX,int posY);

#endif
