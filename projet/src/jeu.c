#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
    @brief Fonction du jeu

    @return int
*/
void Jouer()
{
    Plateau jeu;
    SDL_Surface* pion1;
    SDL_Surface* pion2;
    SDL_Surface* case_vide;
    SDL_Surface* case_jouable;
    SDL_Surface* case_jouable_3;
    SDL_Surface* case_jouable_4;
    SDL_Surface* chiffres[10]; int i; /* pour la boucle de free */
    SDL_Surface* texte_scores;
    SDL_Surface* vsjoueur;
    SDL_Surface* vsordi;
    SDL_Surface* texte_niveau;
    SDL_Surface* screen;
    SDL_Event event;


    /* VARIABLES POUR LE JEU */

        /* variables pour contenir les coordonnées de la souris */
        int sourisx;
        int sourisy;

        /* variable pourr savoir quel joueur doit jouer */
        int qui_joue = 1; /* le joueur 1 commence */

        Case* caseCliquee = 0; /* case sélectionnée */

        Case* caseTemp; /* pointeur pour une case temporaire (dans les boucles) */
        int xtemp, ytemp; /* coordonnées temporaires (pour ctemp) */
        int test; /* bouléen pour stocker le résultats d'un test */

        int animation = 0; /* savoir si une animation de pion est en cours */
        SDL_Rect xyPionAnim;
        SDL_Rect deplacement;
        SDL_Rect xyArrivee;

        int tourautomatique = 0; /* si la fonction est activée, l'utilisateur
                                    peut appuyer O pour faire jouer l'ordi */
        int attente; /* temp d'attente de l'ordinateur */
        attente=10; /* initialiser */

        /* qu'afficher ?
            0 -> quitter
            1 -> menu d'accueil
            2 -> plateau de jeu
            3 -> fin du jeu
        */
        int afficher = 1;

        /* jouer seul ou contre ordinateur */
        int contreordinateur = 0;
        int niveauordinateur = 1;

    /* boucle principale du programme */
    int done = 0;

    /* INITIALISATION DU JEU */
        plateauInit(&jeu,0);

    /* IMAGES POUR LE PLATEAU DE JEU */

        /* on charge les images pour les pions des 2 joueurs */

        pion1 = IMG_Load(PION_JOUEUR_1); afficheVerifChargement(pion1);
        pion2 = IMG_Load(PION_JOUEUR_2); afficheVerifChargement(pion2);

        /* on charge l'image d'un case (normale et jouable) */
        case_vide = IMG_Load(CASE_VIDE); afficheVerifChargement(case_vide);
        case_jouable = IMG_Load(CASE_JOUABLE); afficheVerifChargement(case_jouable);
        case_jouable_3 = IMG_Load(CASE_JOUABLE_3); afficheVerifChargement(case_jouable_3);
        case_jouable_4 = IMG_Load(CASE_JOUABLE_4); afficheVerifChargement(case_jouable_4);

    /* IMAGES POUR LES SCORES */

        /* la tableau pour les images des chiffres */
        chiffres[0] = IMG_Load("../data/chiffres/0.png"); afficheVerifChargement(chiffres[0]);
        chiffres[1] = IMG_Load("../data/chiffres/1.png"); afficheVerifChargement(chiffres[1]);
        chiffres[2] = IMG_Load("../data/chiffres/2.png"); afficheVerifChargement(chiffres[2]);
        chiffres[3] = IMG_Load("../data/chiffres/3.png"); afficheVerifChargement(chiffres[3]);
        chiffres[4] = IMG_Load("../data/chiffres/4.png"); afficheVerifChargement(chiffres[4]);
        chiffres[5] = IMG_Load("../data/chiffres/5.png"); afficheVerifChargement(chiffres[5]);
        chiffres[6] = IMG_Load("../data/chiffres/6.png"); afficheVerifChargement(chiffres[6]);
        chiffres[7] = IMG_Load("../data/chiffres/7.png"); afficheVerifChargement(chiffres[7]);
        chiffres[8] = IMG_Load("../data/chiffres/8.png"); afficheVerifChargement(chiffres[8]);
        chiffres[9] = IMG_Load("../data/chiffres/9.png"); afficheVerifChargement(chiffres[9]);

        texte_scores = IMG_Load(TEXTE_SCORES);
        texte_niveau = IMG_Load(TEXTE_NIVEAU);

        vsjoueur = IMG_Load(VSJOUEUR);
        vsordi = IMG_Load(VSORDI);

    /* INITIALISATIONS POUR L'AFFICHAGE SDL */

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



    while (done==0 && afficher!=0)
    {
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 2, 15, 30));

        /* récupérer la position de la souris sur l'écran */
        sourisx = event.motion.x;
        sourisy = event.motion.y;

        while (SDL_PollEvent(&event))
        {

/*
 ************************
 * EVENEMENTS
 ************************
 */
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
                            afficher = 0; /* fin du jeu */

                            #if COMMENTAIRES==1
                                printf("Echap => on quitte le jeu.\n");
                            #endif
                        }
                        else if(afficher==2)
                        {
                            plateauTestament(&jeu);
                            caseCliquee = 0;
                            afficher = 1;

                            #if COMMENTAIRES==1
                                printf("Echap => fin de la partie, retour au menu.\n");
                            #endif
                        }
                    }

    /* EVENEMENTS (CLAVIER) POUR LE MENU */

                    if(afficher==1)
                    {
                        /* choix du mode de jeu (contre ordi ou joueur) */
                        if(event.key.keysym.sym == SDLK_o)
                        {
                           contreordinateur = (contreordinateur + 1) % 2;

                           #if COMMENTAIRES==1
                                printf("On change le mode de jeu.\n");
                            #endif
                        }

                        /* choix du niveau ordi */
                        else if(contreordinateur==1 && event.key.keysym.sym == SDLK_UP)
                        {
                            if(niveauordinateur<9)
                                niveauordinateur++;

                            #if COMMENTAIRES==1
                                printf("On augmente le niveau de l'ordinateur.\n");
                            #endif
                        }
                        else if(contreordinateur==1 && event.key.keysym.sym == SDLK_DOWN)
                        {
                            if(niveauordinateur>1)
                                niveauordinateur--;

                            #if COMMENTAIRES==1
                                printf("On baisse le niveau de l'ordinateur.\n");
                            #endif
                        }

                        /* choix du plateau de jeu */
                        else if(event.key.keysym.sym == SDLK_F1)
                        {
                            plateauLireFichier(&jeu,PLATEAU1);
                            afficher = 2;
                            qui_joue = 1;
                        }
                        else if(event.key.keysym.sym == SDLK_F2)
                        {
                            plateauLireFichier(&jeu,PLATEAU2);
                            afficher = 2;
                            qui_joue = 1;
                        }
                        else if(event.key.keysym.sym == SDLK_F3)
                        {
                            plateauLireFichier(&jeu,PLATEAU3);
                            afficher = 2;
                            qui_joue = 1;
                        }
                    }

    /* EVENEMENTS (CLAVIER) POUR LE JEU */

                    else if(afficher==2)
                    {
                        /* option pour faire jouer l'ordinateur en appuyant sur la touche o */
                        if(event.key.keysym.sym == SDLK_o)
                            tourautomatique = 1;
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
                        plateauLireFichier(&jeu,PLATEAU1);
                        afficher = 2;
                        qui_joue = 1;

                        #if COMMENTAIRES==1
                            printf("Chargement du plateau par défaut...\nAffichage du jeu.\n");
                        #endif

                    }

    /* EVENEMENTS (CLICS) POUR LE JEU */

                    else if(afficher==2) /* détecter le clic pour le jeu */
                    {
                        if(animation==0 && !(contreordinateur==1 && qui_joue==2)) /* on ne peut cliquer sur une case que si il n'y a pas d'anim et que ce n'est pas l'ordi */
                        {
                            /* on récupère la case cliquée si l'on clique dans une case */
                            caseTemp = plateauCaseSurvollee(sourisx,sourisy,&jeu,case_vide->w);
                        }

                        if(caseTemp!=0) /* on a cliqué à l'intéreur d'une case */
                        {
                            #if COMMENTAIRES==1
                                printf("Case à l'adresse %d cliquée par le joueur %d.\n",(int) caseTemp, qui_joue);
                            #endif

                            /* si on clique sur un pion du joueur qui doit jouer */
                            if((caseGetJoueur(caseTemp))==qui_joue)
                            {
                                /* on sélectionne un pion pour proposer ensuite les possibilités */
                                caseCliquee = caseTemp;

                                #if COMMENTAIRES==1
                                    printf("La case a été sélectionnée.\n");
                                #endif

                                /* on stocke les coordonnée de la case cliquée si elle est amenée à bouger */
                                xyPionAnim = xy2rect(caseGetX(caseCliquee),caseGetY(caseCliquee));

                                #if COMMENTAIRES==1
                                    printf("Ses coordonnées : %d,%d\n",xyPionAnim.x,xyPionAnim.y);
                                #endif
                            }

                            /* le joueur a déjà selectionné un case et clique sur un autre : il passe à l'action */
                            else if(caseCliquee!=0)
                            {
                                if(caseGetLibre(caseTemp)==1) /* la case est libre */
                                {

                                        /* on vérifie qu'elle soit dans une zone où il peut jouer */
                                        xtemp = caseGetX(caseTemp) - caseGetX(caseCliquee);
                                        ytemp = caseGetY(caseTemp) - caseGetY(caseCliquee);
                                        test = plateauTestCaseProche(xtemp,ytemp);
                                    if(test!=0 && animation==0)
                                    {
                                        /* pour l'animation */
                                        xyArrivee = xy2rect(caseGetX(caseTemp),caseGetY((caseTemp)));
                                        deplacement.x = xyArrivee.x - xyPionAnim.x;
                                        deplacement.y = xyArrivee.y - xyPionAnim.y;
                                        xyArrivee.x -= (int) deplacement.x / 10;
                                        xyArrivee.y -= (int) deplacement.y / 10;
                                        animation = 1;
                                    }
                                }
                            }
                        } /* fin de cliqué dans une case */

                        /* si la partie est finie ... */
                        if(plateauGetPlacesLibres(&jeu)==0 || plateauGetScore(&jeu,1)==0 || plateauGetScore(&jeu,2)==0)
                        {
                            afficher = 3;
                            caseCliquee = 0;

                             #if COMMENTAIRES==1
                                printf("Il n'y a plus de place, ou un joueur a perdu => fin de la partie.\n");
                            #endif
                        }

                    } /* fin de détection du clic pour le jeu */

    /* EVENEMENTS (CLICS) POUR LA FIN DU JEU */

                    else if(afficher==3) /* détection du clic à la fin */
                    {
                        afficher = 1; /* on retourne au menu */
                        plateauTestament(&jeu);

                        #if COMMENTAIRES==1
                            printf("Clic sur le message de fin => retour au menu.\n");
                        #endif
                    }

                    break;

                } /* fin de détection clic */

            } /* fin du test des événements */

        } /* fin de détection des événements */

/*
 ************************
 * AFFICHAGE
 ************************

    /* AFFICHAGE DU JEU OU DE LA FIN DU JEU */

        if(afficher==2 || afficher==3)
        {
            /* c'est à l'ordinateur de jouer */
            if((contreordinateur==1 && qui_joue==2) || tourautomatique==1)
            {

                if(attente>=0)
                {
                    attente-=1;
                }else{

                ordinateurJouer(&jeu,qui_joue,niveauordinateur);

                /* ce sera à l'autre joueur de jouer */
                qui_joue = (qui_joue%2)+1;

                /* on vérifie qu'il puisse jouer */
                if(plateauPeutJouer(&jeu,qui_joue)==0)
                {
                    /* s'il ne peut pas jouer : on remplit le plateau avec les pions de l'autre, qui gagne ! */
                    plateauRemplirPions(&jeu,(qui_joue%2)+1);
                    afficher = 3; /* afficher le message de fin */
                }

                /* fin du jeu */
                if(plateauGetPlacesLibres(&jeu)==0 || plateauGetScore(&jeu,1)==0 || plateauGetScore(&jeu,2)==0)
                    afficher = 3;

                tourautomatique = 0;

                caseCliquee = 0;
                attente=10;
                }
            }

            /* afficher le terrain de jeu */
            afficheJeu(&jeu,case_vide, pion1, pion2, screen);

            if(animation==1)
            {
                if(
                   ((deplacement.x>0 && xyPionAnim.x<xyArrivee.x) /* on peut deplacer vers la droite */
                    ||
                    (deplacement.x<0 && xyPionAnim.x>xyArrivee.x)) /* ... ou on peut se déplacer vers la gauche */
                   ||
                   ((deplacement.y>0 && xyPionAnim.y<xyArrivee.y) /* ... et se déplacer en bas */
                    ||
                    (deplacement.y<0 && xyPionAnim.y>xyArrivee.y)))
                {
                    xyPionAnim.x += (int) deplacement.x / 10;
                    xyPionAnim.y += (int) deplacement.y / 10;
                    if(qui_joue==2) /* c'est encore le J2 qui bouge */
                        afficheImageRect(xyPionAnim,pion2,screen);
                    else
                        afficheImageRect(xyPionAnim,pion1,screen);
                    printf("--- On bouge !\n");
                }
                else
                {
                    animation = 2;
                    printf("--- Fini de bouger !\n");
                }
            }

            if(animation==2)
            {
                if(test==1) /* il duplique son pion */
                {
                    plateauDecrementePlacesLibres(&jeu);
                    plateauChangeJoueur(&jeu,caseTemp,qui_joue);
                    caseCliquee = 0;

                    #if COMMENTAIRES==1
                        printf("Le joueur y duplique son pion.\n");
                    #endif
                }
                else if(test==2) /* il déplace son pion */
                {
                    plateauChangeJoueur(&jeu, caseTemp,qui_joue);
                    plateauChangeJoueur(&jeu, caseCliquee,0);
                    caseCliquee = 0;

                    #if COMMENTAIRES==1
                        printf("Le joueur y déplace son pion.\n");
                    #endif
                }

                if(test!=0) /* si il a pu jouer */
                {
                    /* il récupère les pions qu'il touche */
                    plateauVolerPions(&jeu,caseTemp,qui_joue);

                    #if COMMENTAIRES==1
                        printf("Il vole les pions adverses à voler.\n");
                    #endif

                    /* ce sera à l'autre joueur de jouer */
                    qui_joue = (qui_joue%2)+1;

                     #if COMMENTAIRES==1
                        printf("Coordonnées d'arrivée %d,%d.\n",xyArrivee.x,xyArrivee.y);
                    #endif

                    #if COMMENTAIRES==1
                        printf("La main passe au joueur %d.\n",qui_joue);
                    #endif

                    /* on vérifie qu'il puisse jouer */
                    if(plateauPeutJouer(&jeu,qui_joue)==0)
                    {
                        /* s'il ne peut pas jouer : on remplit le plateau avec les pions de l'autre, qui gagne ! */
                        plateauRemplirPions(&jeu,(qui_joue%2)+1);
                        caseCliquee = 0;
                        afficher = 3; /* afficher le message de fin */

                        #if COMMENTAIRES==1
                            printf("Le joueur %d ne peut pas jouer => fin de la partie.\n",qui_joue);
                        #endif
                    }
                }
                animation = 0;
            }

            /* afficher quel joueur doit jouer */
            afficheQuiJoue(qui_joue,screen);

            /* si on a un pointeur de case cliquée non nul */
            if(caseCliquee!=0 && animation!=1)
            {
                /* on affiche la case en surbrillance */
                afficheCaseJeu(caseCliquee, case_jouable, screen);

                /* on affiche les possibilités de jeu autour de la case sélectionnée */
                afficheCasesAutour(&jeu, caseCliquee,case_jouable_3, case_jouable_4, screen);
            }

            /* on affiche le score de chaque joueur */
            afficheScores(plateauGetScore(&jeu,1),plateauGetScore(&jeu,2),chiffres,texte_scores,pion1,pion2,screen);

            /* si la fin du jeu est détectée, on affiche le message */
            if(afficher==3)
            {
                afficheFinJeu(plateauGetScore(&jeu,1),plateauGetScore(&jeu,2),contreordinateur,screen);
            }
        }

    /* mettre à jour l'écran */
        SDL_Flip(screen);

    } /* fin de la boucle principale */

/*
 **************************
 * LIBERER LES SDL_Surfaces
 **************************
 */

    SDL_FreeSurface(pion1);
    SDL_FreeSurface(pion2);
    SDL_FreeSurface(case_vide);
    SDL_FreeSurface(case_jouable);
    SDL_FreeSurface(case_jouable_3);
    SDL_FreeSurface(case_jouable_4);
    SDL_FreeSurface(texte_scores);
    SDL_FreeSurface(texte_niveau);
    SDL_FreeSurface(vsjoueur);
    SDL_FreeSurface(vsordi);
    for(i=0;i<10;i++)
        SDL_FreeSurface(chiffres[i]);
    SDL_FreeSurface(screen);

    plateauTestament(&jeu);
    return 0;
}