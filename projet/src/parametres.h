#ifndef _PARAMETRES
#define _PARAMETRES

/**
	Paramètres pour les images à charger.

	@param PION_JOUEUR_1 : chemin vers l'image du pion 1
	@param PION_JOUEUR_2 : chemin vers l'image du pion 2

	@param CASE_VIDE  : chemin vers l'image de la case
	@param CASE_JOUABLE : chemin vers l'image de la case d'une autre couleur
	@param CASE_JOUABLE_3 : chemin vers l'image de la case d'une autre couleur
	@param CASE_JOUABLE_4 : chemin vers l'image de la case d'une autre couleur

	@param LOGO_JOUEUR_1 : chemin vers l'image pour indiquer que J1 a la main
	@param LOGO_JOUEUR_2 : chemin vers l'image pour indiquer que J2 a la main

	@param TEXTE_SCORES : chemin vers l'image affichée juste au dessus des scores

	@param BRAVO_0 : chemin vers l'image affichée en fin de jeu (pas de gagnant)
	@param BRAVO_1 : chemin vers l'image affichée en fin de jeu (joueur 1 gagnant)
	@param BRAVO_2 : chemin vers l'image affichée en fin de jeu (joueur 2 gagnant)
	@param BRAVO_3 : chemin vers l'image affichée en fin de jeu (ordinateur gagnant)

	@param VSJOUEUR : chemin vers l'image pour 2 joueurs
	@param VSORDI : chemin vers l'image pour 1 joueur contre ordinateur

	@param TEXTE_NIVEAU : chemin vers l'image du mot niveau

	@param MENU : chemin vers l'image du menu principal

	@param PLATEAU1 : chemin vers le fichier du plateau 1
	@param PLATEAU2 : chemin vers le fichier du plateau 2
	@param PLATEAU3 : chemin vers le fichier du plateau 3

	@param UNITE_X : unités pour les coordonnées horizontales
	@param UNITE_Y : unités pour les coordonnées verticales
	@param DECAL_X : décalage du plateau par rapport au haut de l'écran
	@param DECAL_Y : décalage du plateau par rapport au côté gauche de l'écran

	@param COMMENATIRES : si 0 pas de commentaires des actions, sinon 1
*//*
    Les coordonnées correspondent aux images "case"
    Leur valeur permet d'aligner correctement les hexagones.
*/

    #define TEXTURE "style1"

	#define PION_JOUEUR_1 "../data/"TEXTURE"/pion1.png"
	#define PION_JOUEUR_2 "../data/"TEXTURE"/pion2.png"

	#define CASE_VIDE "../data/"TEXTURE"/Case.png"
	#define CASE_JOUABLE "../data/"TEXTURE"/Case2.png"
	#define CASE_JOUABLE_3 "../data/"TEXTURE"/Case3.png"
	#define CASE_JOUABLE_4 "../data/"TEXTURE"/Case4.png"

	#define LOGO_JOUEUR_1 "../data/"TEXTURE"/joueur1.png"
	#define LOGO_JOUEUR_2 "../data/"TEXTURE"/joueur2.png"

	#define TEXTE_SCORES "../data/images/texte_scores.png"

	#define BRAVO_0 "../data/images/bravo0.png"
	#define BRAVO_1 "../data/images/bravo1.png"
	#define BRAVO_2 "../data/images/bravo2.png"
	#define BRAVO_3 "../data/images/bravo3.png"

	#define VSJOUEUR "../data/images/1vs2.png"
	#define VSORDI "../data/images/1vsordi.png"
	#define SELECTIONMODE "../data/images/selectionmode.png"

	#define BOUTONJOUER "../data/images/boutonjouer.png"
	#define BOUTONJOUERSURVOL "../data/images/boutonjouersurvol.png"

	#define ICONE "../data/images/icone.ico"

	#define TEXTE_NIVEAU "../data/images/niveau.png"

	#define MENU "../data/images/menu.png"
	#define PLATEAU1_MENU "../data/images/plateau1.png"
	#define PLATEAU2_MENU "../data/images/plateau2.png"
	#define PLATEAU3_MENU "../data/images/plateau3.png"
	#define PLATEAU_SELECTIONNE_MENU "../data/images/plateauselectionne.png"


	#define PLATEAU1 "../data/Plateau1.txt"
	#define PLATEAU2 "../data/Plateau2.txt"
	#define PLATEAU3 "../data/Plateau3.txt"

	#define UNITE_X 54.5
	#define UNITE_Y 29.5
	#define DECAL_X 4
	#define DECAL_Y 3

	#define COMMENTAIRES 1

#endif
