#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"

#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>


/**
    @brief Fonction du jeu

    @return int
*/
int main ()
{
    Plateau jeu;

    /* on charge les images pour les pions des 2 joueurs */
    pion1 = IMG_Load(PION_JOUEUR_1);
    pion2 = IMG_Load(PION_JOUEUR_2);

    SDL_Surface* menu;
    menu = IMG_Load(MENU);

    /* erreurs de chargement ? */
    if (!pion1)
    {
        printf("Erreur de chargement du pion du joueur 1 : %s\n", SDL_GetError());
        return 1;
    }
    if (!pion2)
    {
        printf("Erreur de chargement du pion du joueur 2 : %s\n", SDL_GetError());
        return 1;
    }
    if (!menu)
    {
        printf("Erreur de chargement du menu : %s\n", SDL_GetError());
        return 1;
    }

    /* on charge l'image d'un case (normale et jouable) */
    case_vide = IMG_Load(CASE_VIDE);
    case_jouable = IMG_Load(CASE_JOUABLE);
    case_jouable_3 = IMG_Load(CASE_JOUABLE_3);
    case_jouable_4 = IMG_Load(CASE_JOUABLE_4);

    /* IMAGES POUR LES SCORES */

        /* la tableau pour les images des chiffres */
        SDL_Surface* chiffres[10];
        chiffres[0] = IMG_Load("../data/Texture1/0.png");
        chiffres[1] = IMG_Load("../data/Texture1/1.png");
        chiffres[2] = IMG_Load("../data/Texture1/2.png");
        chiffres[3] = IMG_Load("../data/Texture1/3.png");
        chiffres[4] = IMG_Load("../data/Texture1/4.png");
        chiffres[5] = IMG_Load("../data/Texture1/5.png");
        chiffres[6] = IMG_Load("../data/Texture1/6.png");
        chiffres[7] = IMG_Load("../data/Texture1/7.png");
        chiffres[8] = IMG_Load("../data/Texture1/8.png");
        chiffres[9] = IMG_Load("../data/Texture1/9.png");

        SDL_Surface* texte_scores;
        texte_scores = IMG_Load(TEXTE_SCORES);

    /* erreurs de chargement ? */
    if (!case_vide)
    {
        printf("Erreur de chargement de la case vide: %s\n", SDL_GetError());
        return 1;
    }
    if (!case_jouable)
    {
        printf("Erreur de chargement de la case jouable: %s\n", SDL_GetError());
        return 1;
    }

    /* on charge l'écran d'affichage */
    screen = SDL_SetVideoMode(1100, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (!screen)
    {
        printf("Erreur de définition de l'écran video : %s\n", SDL_GetError());
        return 1;
    }


    /* on vide l'écran */
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    /* on initialise SDL video */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Erreur d'initialisation SDL: %s\n", SDL_GetError() );
        return 1;
    }

    /* make sure SDL cleans up before exit */
    atexit(SDL_Quit);


    /* variables pour contenir les coordonnées de la souris */
    int sourisx;
    int sourisy;

    /* variable pourr savoir quel joueur doit jouer */
    int qui_joue = 1; /* le joueur 1 commence */

    Case* caseCliquee = 0; /* case sélectionnée */

    Case* caseTemp; /* pointeur pour une case temporaire (dans les boucles) */
    int xtemp, ytemp; /* coordonnées temporaires (pour ctemp) */
    int test; /* bouléen pour stocker le résultats d'un test */


    /* qu'afficher ?
        0 -> quitter
        1 -> menu d'accueil
        2 -> plateau de jeu
        3 -> fin du jeu
    */
    int afficher = 1;

    /* boucle principale du programme */
    int done = 0;
    while (done==0 && afficher!=0)
    {
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 2, 15, 30));

        /* détection des événements */
        SDL_Event event;

        /* récupérer la position de la souris sur l'écran */
        sourisx = event.motion.x;
        sourisy = event.motion.y;

        while (SDL_PollEvent(&event))
        {
            /* test des événements */
            switch (event.type)
            {
                /* fermer */
                case SDL_QUIT:
                    done = 1;
                break;

                /* touche enfoncée */
                case SDL_KEYDOWN:
                {
    /* touche ECHAP => quitter ou retour menu */
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        if(afficher==1 || afficher==3)
                        {
                            afficher = 0; // fin du jeu
                        }
                        else if(afficher==2)
                        {
                            plateauTestament(&jeu);
                            afficher = 1;
                        }
                    }

    /* EVENEMENTS (CLAVIER) POUR LE MENU */
                    if(afficher==1)
                    {
                        if(event.key.keysym.sym == SDLK_F1)
                        {
                            lirePlateau(&jeu,PLATEAU1);
                            afficher = 2;
                        }
                        else if(event.key.keysym.sym == SDLK_F2)
                        {
                            lirePlateau(&jeu,PLATEAU2);
                            afficher = 2;
                        }
                    }

                    break;
                }

                /* clic de souris */
                case SDL_MOUSEBUTTONDOWN:
                {

    /* EVENEMENTS (CLICS) POUR LE MENU */
                    if(afficher==1)
                    {
                        /* on charge le plateau de jeu */
                        lirePlateau(&jeu,PLATEAU2);
                        afficher = 2;
                    }

    /* EVENEMENTS (CLICS) POUR LE JEU */
                    else if(afficher==2) /* détecter le clic pour le jeu */
                    {
                        /* on récupère la case cliquée si l'on clique dans une case */
                        caseTemp = caseSurvollee(sourisx,sourisy,&jeu);

                        if(caseTemp!=0) /* on a cliqué à l'intéreur d'une case */
                        {
                            /* si on clique sur un pion du joueur qui doit jouer */
                            if((caseGetJoueur(caseTemp))==qui_joue)
                            {
                                /* on sélectionne un pion pour proposer ensuite les possibilités */
                                caseCliquee = caseTemp;
                            }

                            /* le joueur a déjà selectionné un case et clique sur un autre : il passe à l'action */
                            else if(caseCliquee!=0)
                            {
                                if(caseGetLibre(caseTemp)==1) /* la case est libre */
                                {
                                    /* on vérifie qu'elle soit dans une zone où il peut jouer */
                                    xtemp = caseGetX(caseTemp) - caseGetX(caseCliquee);
                                    ytemp = caseGetY(caseTemp) - caseGetY(caseCliquee);
                                    test = testCaseProche(xtemp,ytemp);
                                    if(test==1) /* il duplique son pion */
                                    {
                                        plateauDecrementePlacesLibres(&jeu);
                                        plateauChangeJoueur(&jeu,caseTemp,qui_joue);
                                        caseCliquee = 0;
                                    }
                                    else if(test==2) /* il déplace son pion */
                                    {
                                        plateauChangeJoueur(&jeu, caseTemp,qui_joue);
                                        plateauChangeJoueur(&jeu, caseCliquee,0);
                                        caseCliquee = 0;
                                    }

                                    if(test!=0) /* si il a pu jouer */
                                    {
                                        /* il récupère les pions qu'il touche */
                                        changeCasesAutour(&jeu,caseTemp,qui_joue);

                                        /* ce sera à l'autre joueur de jouer */
                                        qui_joue = (qui_joue%2)+1;

                                        /* on vérifie qu'il puisse jouer */
                                        if(peutJouer(&jeu,qui_joue)==0)
                                        {
                                            /* s'il ne peut pas jouer : on remplit le plateau avec les pions de l'autre, qui gagne ! */
                                            remplirPlateau(&jeu,(qui_joue%2)+1);
                                            afficher = 3; /* afficher le message de fin */
                                        }
                                    }
                                }
                            }
                        } /* fin de cliqué dans une case */

                        /* si la partie est finie : afficher le message de fin */
                        if((plateauGetPlacesLibres(&jeu)==0)||(jeu.score_j1==0)||(jeu.score_j2==0))
                            afficher = 3;

                    } /* fin de détection du clic pour le jeu */

    /* EVENEMENTS (CLICS) POUR LA FIN DU JEU */
                    else if(afficher==3) /* détection du clic à la fin */
                    {
                        afficher = 1; /* on retourne au menu */
                        plateauTestament(&jeu);
                    }

                    break;

                } /* fin de détection clic */

            } /* fin du test des événements */

        } /* fin de détection des événements */

    /* AFFICHAGE DU MENU DU JEU */
        if(afficher==1)
        {
           afficheImage((screen->w - menu->w)/2,(screen->h - menu->h)/2,menu);
        }

    /* AFFICHAGE DU JEU OU DE LA FIN DU JEU */
        else if(afficher==2 || afficher==3)
        {
            /* afficher le terrain de jeu */
            afficheJeu(&jeu,case_vide, pion1, pion2);

            /* afficher quel joueur doit jouer */
            afficheQuiJoue(qui_joue);

            /* si on a un pointeur de case cliquée non nul */
            if(caseCliquee!=0)
            {
                /* on affiche la case en surbrillance */
                dessineCase(
                            UNITE_X*(caseGetX(caseCliquee)+DECAL_X),
                            UNITE_Y*(caseGetY(caseCliquee)+DECAL_Y),
                            1);

                /* on affiche les possibilités de jeu autour de la case sélectionnée */
                casesAutour(&jeu,caseCliquee);
            }

            /* on affiche le score de chaque joueur */
            afficheScores(getScore(&jeu,1),getScore(&jeu,2),chiffres,texte_scores,pion1,pion2);

            /* si la fin du jeu est détectée, on affiche le message */
            if(afficher==3)
            {
                afficheFinJeu(getScore(&jeu,1),getScore(&jeu,2));
            }
        }

        /* mettre à jour l'écran */
        SDL_Flip(screen);

    } /* fin de la boucle principale */

    plateauTestament(&jeu);
    printf("Sortie du programme --- \n");
    return 0;
}
