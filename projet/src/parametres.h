#ifndef _PARAMETRES
#define _PARAMETRES

/** <b>Style du jeu pour la compilation (dossier)</b> */
    #define TEXTURE "style1"
/** <b>Chemin relatif vers le dossier data</b> */
    #define CHREL "../"

/** <b>Chemin vers l'image du pion du joueur 1</b> */
	#define PION_JOUEUR_1 CHREL"data/"TEXTURE"/pion1.png"
/** <b>Chemin vers l'image du pion du joueur 2</b> */
	#define PION_JOUEUR_2 CHREL"data/"TEXTURE"/pion2.png"

/** <b>Chemin vers l'image d'une case vide</b> */
	#define CASE_VIDE CHREL"data/"TEXTURE"/Case.png"
/** <b>Chemin vers l'image d'une case selectionnee</b> */
	#define CASE_JOUABLE CHREL"data/"TEXTURE"/Case2.png"
/** <b>Chemin vers l'image d'une case accessible (distance = 1)</b> */
	#define CASE_JOUABLE_3 CHREL"data/"TEXTURE"/Case3.png"
/** <b>Chemin vers l'image d'une case accessible (distance = 2)</b> */
	#define CASE_JOUABLE_4 CHREL"data/"TEXTURE"/Case4.png"

/** <b>Chemin vers l'image qui indique que c'est le tour du joueur 1</b> */
	#define LOGO_JOUEUR_1 CHREL"data/"TEXTURE"/joueur1.png"
/** <b>Chemin vers l'image qui indique que c'est le tour du joueur 2</b> */
	#define LOGO_JOUEUR_2 CHREL"data/"TEXTURE"/joueur2.png"

/** <b>Chemin vers l'image qui affiche "Scores"</b> */
	#define TEXTE_SCORES CHREL"data/images/texte_scores.png"
/** <b>Chemin vers l'image d'un sablier (temps de jeu de l'ordinateur)</b> */
	#define SABLIER CHREL"data/images/sablier3.png"

/** <b>Chemin vers l'image a afficher en fin de jeu (pas de gagnant)</b> */
	#define BRAVO_0 CHREL"data/images/bravo0.png"
/** <b>Chemin vers l'image a afficher en fin de jeu (joueur 1 gagnant)</b> */
	#define BRAVO_1 CHREL"data/images/bravo1.png"
/** <b>Chemin vers l'image a afficher en fin de jeu (joueur 2 gagnant)</b> */
	#define BRAVO_2 CHREL"data/images/bravo2.png"
/** <b>Chemin vers l'image a afficher en fin de jeu (ordinateur gagnant)</b> */
	#define BRAVO_3 CHREL"data/images/bravo3.png"

/** <b>Chemin vers l'image du menu : joueur contre joueur</b> */
	#define VSJOUEUR CHREL"data/images/1vs2.png"
/** <b>Chemin vers l'image du menu : joueur contre ordinateur</b> */
	#define VSORDI CHREL"data/images/1vsordi.png"
/** <b>Chemin vers l'image du menu qui montre la selection du mode de jeu</b> */
	#define SELECTIONMODE CHREL"data/images/selectionmode.png"

/** <b>Chemin vers l'image du menu : bouton pour lancer la partie</b> */
	#define BOUTONJOUER CHREL"data/images/boutonjouer.png"
/** <b>Chemin vers l'image du menu : bouton pour lancer la partie au survol</b> */
	#define BOUTONJOUERSURVOL CHREL"data/images/boutonjouersurvol.png"

/** <b>Chemin vers une icone pour le jeu</b> */
	#define ICONE CHREL"data/images/icone.ico"

/** <b>Chemin vers l'image qui affiche "Niveau :"</b> */
	#define TEXTE_NIVEAU CHREL"data/images/niveau.png"

/** <b>Chemin vers l'image du menu : informations de jeu</b> */
	#define MENU CHREL"data/images/menu.png"
/** <b>Chemin vers l'image du menu : apercu du plateau 1</b> */
	#define PLATEAU1_MENU CHREL"data/images/plateau1.png"
/** <b>Chemin vers l'image du menu : apercu du plateau 2</b> */
	#define PLATEAU2_MENU CHREL"data/images/plateau2.png"
/** <b>Chemin vers l'image du menu : apercu du plateau 3</b> */
	#define PLATEAU3_MENU CHREL"data/images/plateau3.png"
/** <b>Chemin vers l'image du menu : apercu du plateau 4</b> */
	#define PLATEAU4_MENU CHREL"data/images/plateau4.png"
/** <b>Chemin vers l'image du menu qui montre quel plateau est selectionne</b> */
	#define PLATEAU_SELECTIONNE_MENU CHREL"data/images/plateauselectionne.png"

/** <b>Chemin vers le fichier source du plateau 1</b> */
	#define PLATEAU1 CHREL"data/Plateau1.txt"
/** <b>Chemin vers le fichier source du plateau 2</b> */
	#define PLATEAU2 CHREL"data/Plateau2.txt"
/** <b>Chemin vers le fichier source du plateau 3</b> */
	#define PLATEAU3 CHREL"data/Plateau3.txt"
/** <b>Chemin vers le fichier source du plateau pour le test de non-regression</b> */
	#define PLATEAUTEST CHREL"data/PlateauTest.txt"

/** <b>Chemin vers l'image du menu : bouton [+] (pour augmenter la difficulte de l'ordinateur)</b> */
	#define BOUTONPLUS CHREL"data/images/plus.png"
/** <b>Chemin vers l'image du menu : bouton [-] (pour diminuer la difficulte de l'ordinateur)</b> */
    #define BOUTONMOINS CHREL"data/images/moins.png"

/** <b>Chemin vers l'image du chiffre 0</b> */
    #define CHIFFRE0 CHREL"data/chiffres/0.png"
/** <b>Chemin vers l'image du chiffre 1</b> */
    #define CHIFFRE1 CHREL"data/chiffres/1.png"
/** <b>Chemin vers l'image du chiffre 2</b> */
    #define CHIFFRE2 CHREL"data/chiffres/2.png"
/** <b>Chemin vers l'image du chiffre 3</b> */
    #define CHIFFRE3 CHREL"data/chiffres/3.png"
/** <b>Chemin vers l'image du chiffre 4</b> */
    #define CHIFFRE4 CHREL"data/chiffres/4.png"
/** <b>Chemin vers l'image du chiffre 5</b> */
    #define CHIFFRE5 CHREL"data/chiffres/5.png"
/** <b>Chemin vers l'image du chiffre 6</b> */
    #define CHIFFRE6 CHREL"data/chiffres/6.png"
/** <b>Chemin vers l'image du chiffre 7</b> */
    #define CHIFFRE7 CHREL"data/chiffres/7.png"
/** <b>Chemin vers l'image du chiffre 8</b> */
    #define CHIFFRE8 CHREL"data/chiffres/8.png"
/** <b>Chemin vers l'image du chiffre 9</b> */
    #define CHIFFRE9 CHREL"data/chiffres/9.png"

/** <b>Chemin vers le son "Oh, no !"</b> */

    #define SON_NO CHREL"data/music/no.wav"
/** <b>Chemin vers le son pour la selection d'une case</b> */
    #define SON_CLIC CHREL"data/music/clic.wav"
/** <b>Chemin vers le son pour le deplacement d'un pion</b> */
    #define SON_BOING CHREL"data/music/boing.wav"
/** <b>Chemin vers une musique de fond</b> */
    #define SON_ENTRAINENT CHREL"data/music/entrainent.wav"
/** <b>Chemin vers une musique de fond</b> */
    #define SON_MENUSUITE CHREL"data/music/menu_suite.wav"
/** <b>Chemin vers le son "Bravo !"</b> */
    #define SON_BRAVO CHREL"data/music/bravo.wav"
/** <b>Chemin vers le son "Hello" pour l'ouverture du menu</b> */
    #define SON_HELLO CHREL"data/music/hello.wav"
/** <b>Chemin vers une musique de fond du menu</b> */
    #define SON_MENU CHREL"data/music/menu.wav"

/** <b>Parametre aligner correctement les cases à l'ecran en largeur</b> */
	#define UNITE_X 54.5
/** <b>Parametre aligner correctement les cases à l'ecran en hauteur</b> */
	#define UNITE_Y 29.5
/** <b>Parametre pour decaler vers la droite le plateau de jeu</b> */
	#define DECAL_X 4
/** <b>Parametre pour decaler vers la gauche le plateau de jeu</b> */
	#define DECAL_Y 1

/** <b>Parametre pour afficher les informations pendant le jeu (commentaires des fonctions)</b> */
	#define COMMENTAIRES 0
/** <b>Parametre pour activer ou non les sons pendant le jeu</b> */
	#define SONS 1

#endif
