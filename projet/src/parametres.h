#ifndef _PARAMETRES
#define _PARAMETRES

/**
	Paramètres pour les images à charger.

	@param TEXTURE : nom du dossier pour le style des images
	@param CHREL : chemin relatif

	@param PION_JOUEUR_1 : chemin vers l'image du pion 1
	@param PION_JOUEUR_2 : chemin vers l'image du pion 2

	@param CASE_VIDE  : chemin vers l'image de la case
	@param CASE_JOUABLE : chemin vers l'image de la case d'une autre couleur
	@param CASE_JOUABLE_3 : chemin vers l'image de la case d'une autre couleur
	@param CASE_JOUABLE_4 : chemin vers l'image de la case d'une autre couleur

	@param LOGO_JOUEUR_1 : chemin vers l'image pour indiquer que J1 a la main
	@param LOGO_JOUEUR_2 : chemin vers l'image pour indiquer que J2 a la main

	@param TEXTE_SCORES : chemin vers l'image affichée juste au dessus des scores
	@param SABLIER : chemin vers l'image du sablier affichee quand l'ordi reflechit

	@param BRAVO_0 : chemin vers l'image affichée en fin de jeu (pas de gagnant)
	@param BRAVO_1 : chemin vers l'image affichée en fin de jeu (joueur 1 gagnant)
	@param BRAVO_2 : chemin vers l'image affichée en fin de jeu (joueur 2 gagnant)
	@param BRAVO_3 : chemin vers l'image affichée en fin de jeu (ordinateur gagnant)

	@param VSJOUEUR : chemin vers l'image pour 2 joueurs
	@param VSORDI : chemin vers l'image pour 1 joueur contre ordinateur
	@param SELECTIONMODE : rectangle pour la selection du mode de jeu dans le menu

	@param BOUTONJOUER : chemin vers l'image du bouton pour "Jouer"
	@param BOUTONJOUERSURVOL : image quand le bouton est survolle

	@param ICONE : chamin vers une icone

	@param TEXTE_NIVEAU : chemin vers l'image du mot niveau

	@param MENU : chemin vers l'image du menu principal
	@param PLATEAU1_MENU : chemin vers l'apercu du plateau 1
	@param PLATEAU2_MENU : chemin vers l'apercu du plateau 2
	@param PLATEAU3_MENU : chemin vers l'apercu du plateau 3
	@param PLATEAU_SELECTIONNE_MENU : rectangle de selection du plateau

	@param PLATEAU1 : chemin vers le fichier du plateau 1
	@param PLATEAU2 : chemin vers le fichier du plateau 2
	@param PLATEAU3 : chemin vers le fichier du plateau 3
	@param PLATEAUTEST : chemin vers le fichier pour les test de regression

	@param BOUTONPLUS : chemin vers le fichier du bouton "+"
	@param BOUTONMOINS : chemin vers le fichier du bouton "-"

	@param CHIFFREx : chemin vers le fichier du chiffre x

    @param  SON_NO Son : Son "Oh no !" si perdu
    @param  SON_CLIC : Son pour le clic
    @param  SON_BOING : Son pour un déplacement
    @param  SON_ENTRAINENT : Musique de fond
    @param  SON_MENUSUITE : Musique de fond
    @param  SON_BRAVO : Son "Bravo" pour la fin du jeu
    @param  SON_HELLO : Son "Hello" au lancement du menu
    @param  SON_MENU : Musique de fond du menu

	@param UNITE_X : unités pour les coordonnées horizontales
	@param UNITE_Y : unités pour les coordonnées verticales
	@param DECAL_X : décalage du plateau par rapport au haut de l'écran
	@param DECAL_Y : décalage du plateau par rapport au côté gauche de l'écran

	@param COMMENTAIRES : si 0 pas de commentaires des actions, sinon 1
	@param SONS : si 0 pas de sons pour le jeu, sinon 1
*//*
    Les coordonnées correspondent aux images "case"
    Leur valeur permet d'aligner correctement les hexagones.
*/
    #define TEXTURE "style1"
    #define CHREL "../"

	#define PION_JOUEUR_1 CHREL"data/"TEXTURE"/pion1.png"
	#define PION_JOUEUR_2 CHREL"data/"TEXTURE"/pion2.png"

	#define CASE_VIDE CHREL"data/"TEXTURE"/Case.png"
	#define CASE_JOUABLE CHREL"data/"TEXTURE"/Case2.png"
	#define CASE_JOUABLE_3 CHREL"data/"TEXTURE"/Case3.png"
	#define CASE_JOUABLE_4 CHREL"data/"TEXTURE"/Case4.png"

	#define LOGO_JOUEUR_1 CHREL"data/"TEXTURE"/joueur1.png"
	#define LOGO_JOUEUR_2 CHREL"data/"TEXTURE"/joueur2.png"

	#define TEXTE_SCORES CHREL"data/images/texte_scores.png"
	#define SABLIER CHREL"data/images/sablier3.png"

	#define BRAVO_0 CHREL"data/images/bravo0.png"
	#define BRAVO_1 CHREL"data/images/bravo1.png"
	#define BRAVO_2 CHREL"data/images/bravo2.png"
	#define BRAVO_3 CHREL"data/images/bravo3.png"

	#define VSJOUEUR CHREL"data/images/1vs2.png"
	#define VSORDI CHREL"data/images/1vsordi.png"
	#define SELECTIONMODE CHREL"data/images/selectionmode.png"

	#define BOUTONJOUER CHREL"data/images/boutonjouer.png"
	#define BOUTONJOUERSURVOL CHREL"data/images/boutonjouersurvol.png"

	#define ICONE CHREL"data/images/icone.ico"

	#define TEXTE_NIVEAU CHREL"data/images/niveau.png"

	#define MENU CHREL"data/images/menu.png"
	#define PLATEAU1_MENU CHREL"data/images/plateau1.png"
	#define PLATEAU2_MENU CHREL"data/images/plateau2.png"
	#define PLATEAU3_MENU CHREL"data/images/plateau3.png"
	#define PLATEAU_SELECTIONNE_MENU CHREL"data/images/plateauselectionne.png"

	#define PLATEAU1 CHREL"data/Plateau1.txt"
	#define PLATEAU2 CHREL"data/Plateau2.txt"
	#define PLATEAU3 CHREL"data/Plateau3.txt"
	#define PLATEAUTEST CHREL"data/PlateauTest.txt"

	#define BOUTONPLUS CHREL"data/images/plus.png"
    #define BOUTONMOINS CHREL"data/images/moins.png"

    #define CHIFFRE0 CHREL"data/chiffres/0.png"
    #define CHIFFRE1 CHREL"data/chiffres/1.png"
    #define CHIFFRE2 CHREL"data/chiffres/2.png"
    #define CHIFFRE3 CHREL"data/chiffres/3.png"
    #define CHIFFRE4 CHREL"data/chiffres/4.png"
    #define CHIFFRE5 CHREL"data/chiffres/5.png"
    #define CHIFFRE6 CHREL"data/chiffres/6.png"
    #define CHIFFRE7 CHREL"data/chiffres/7.png"
    #define CHIFFRE8 CHREL"data/chiffres/8.png"
    #define CHIFFRE9 CHREL"data/chiffres/9.png"

    #define SON_NO CHREL"data/music/no.wav"
    #define SON_CLIC CHREL"data/music/clic.wav"
    #define SON_BOING CHREL"data/music/boing.wav"
    #define SON_ENTRAINENT CHREL"data/music/entrainent.wav"
    #define SON_MENUSUITE CHREL"data/music/menu_suite.wav"
    #define SON_BRAVO CHREL"data/music/bravo.wav"
    #define SON_HELLO CHREL"data/music/hello.wav"
    #define SON_MENU CHREL"data/music/menu.wav"

	#define UNITE_X 54.5
	#define UNITE_Y 29.5
	#define DECAL_X 4
	#define DECAL_Y 1

	#define COMMENTAIRES 0
	#define SONS 1

#endif
