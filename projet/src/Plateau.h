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

    @param p : pointeur sur le plateau
    @param capacite : nombre max de cases sur le plateau

    @return void
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

/** \brief Afficher tout le plateau
 *
 * \param p plateau à afficher
 * \return void
 *
 */

void affichePlateau(Plateau* p);

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
void dessineCase(float posX,float posY);

/** \brief Détermine si la souris est dans un cercle d'une case
 *
 * \param sx position x de la souris
 * \param sy position y de la souris
 * \param c Case à tester
 * \return booléen
 *
 */
int sourisDansCase(int sx, int sy, const Case* c);

/** \brief Détermine quelle case est survollée
 *
 * \param sx Position x de la souris
 * \param sy Position y de la souris
 * \param p Plateau
 * \return pointeur sur la case survollée, ou 0 si aucune survollée
 *
 */

Case* caseSurvollee(int sx, int sy, const Plateau* p);

/**
    @brief Lire un fichier pour charger un plateau

    @param p : pointeur sur la plateau a remplir
    @param filename : nom du fichier à charger

    @return void
*/
void lirePlateau(Plateau* p, const char filename[]);

/** \brief Modifie l'apparence de la case selectionné et des cases adjacentes
 *
 * \param c : pointeur sur case
 * \param sx : position de la souris selon l'axe x
 * \param sy : position de la souris selon l'axe y
 * \return void
 *
 */

void selectionneCase(case* c,int sx, int sy);
#endif
