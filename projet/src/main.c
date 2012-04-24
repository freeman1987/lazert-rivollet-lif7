#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"

#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>

/**
    @brief Afficher les scores des joueurs

    @param [in] s1 : score 1
    @param [IN] s2 : score 2

    @return void
*/
void affiche_score(int s1, int s2);

int main ()
{
    Plateau jeu;

    /* on charge le plateau de jeu */
    lirePlateau(&jeu,"../data/Plateau1.txt");

    /* on charge les images pour les pions des 2 joueurs */
    pion1 = IMG_Load(PION_JOUEUR_1);
    pion2 = IMG_Load(PION_JOUEUR_2);

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

    int i;

    /* on charge l'image d'un case (normale et jouable) */
    case_vide = IMG_Load(CASE_VIDE);
    case_jouable = IMG_Load(CASE_JOUABLE);
    case_jouable_3 = IMG_Load(CASE_JOUABLE_3);
    case_jouable_4 = IMG_Load(CASE_JOUABLE_4);
    logo_joueur_1 = IMG_Load(LOGO_JOUEUR_1);
    logo_joueur_2 = IMG_Load(LOGO_JOUEUR_2);

    /* la tableau pour les images des chiffres (déclaré dans parametres.h) */
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

    Case* caseCliquee = 0;
    Case* caseTemp; /* case temporaire */

    int xtemp, ytemp; /* coordonnées temporaires */

    /* boucle principale du programme */
    int done = 0;
    int test;
    while (done==0)
    {
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        /* afficher le terrain de jeu */
        affichePlateau(&jeu);
        affichePiece(&jeu);

        /* détection des événements */
        SDL_Event event;

        /* position de la souris sur l'écran */
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
                        /* touche ECHAP */
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            done = 1;
                        break;
                    }
                /* clic de souris */
                case SDL_MOUSEBUTTONDOWN:
                    {

                        /* on récupère la case cliquée si on clique dans une case */
                        caseTemp = caseSurvollee(sourisx,sourisy,&jeu);
                        if(caseTemp!=0)
                        {

                            /* si on clique sur un pion du joueur qui doit jouer */
                            if((getJoueur(caseTemp))==qui_joue)
                            {
                                /* on sélectionne un pion pour le faire "agir" */
                                caseCliquee = caseTemp;
                            }

                            /* le joueur a deja selectionné un case et clique sur un autre */
                            else if(caseCliquee!=0)
                            {
                                if(getLibre(caseTemp)==1)
                                {
                                     xtemp = getX(caseTemp) - getX(caseCliquee);
                                     ytemp = getY(caseTemp) - getY(caseCliquee);
                                     test = testCaseProche(xtemp,ytemp);
                                     if(test==1)
                                     {
                                        decrementePlacesLibres(&jeu);
                                        changeJoueur(&jeu,caseTemp,qui_joue);
                                        caseCliquee=0;
                                     }
                                     else if(test==2)
                                     {
                                        changeJoueur(&jeu, caseTemp,qui_joue);
                                        changeJoueur(&jeu, caseCliquee,0);
                                        caseCliquee=0;
                                     }
                                     if(test!=0)
                                     {
                                          changeCasesAutour(&jeu,caseTemp,qui_joue);
                                          qui_joue=(qui_joue%2)+1;
                                     }
                                }
                                printf("score J1 %d\n score J2 %d \n", jeu.score_j1,jeu.score_j2);
                            }
                        }

                        /* si la partie est finie */
                        if((getPlacesLibres(&jeu)==0)||(jeu.score_j1==0)||(jeu.score_j2==0))
                            done = 1;

                    }
            } /* fin du test des événements */
        }

        // afficher quel joueur doit jouer
        SDL_Rect place_qui_joue;
        place_qui_joue.x = 50;
        place_qui_joue.y = 50;
        if(qui_joue==1)
            SDL_BlitSurface(logo_joueur_1, 0, screen, &place_qui_joue);
        else if(qui_joue==2)
            SDL_BlitSurface(logo_joueur_2, 0, screen, &place_qui_joue);


        float x;
        float y;
        /* si on a un pointeur de case cliquée non nul */
        if(caseCliquee!=0)
        {
            /* on affiche la case en surbrillance */
            x = UNITE_X*(getX(caseCliquee)+DECAL_X);
            y = UNITE_Y*(getY(caseCliquee)+DECAL_Y);
            dessineCase(x,y,1);

            casesAutour(&jeu,caseCliquee);
        }

        affiche_score(getScore(&jeu,1),getScore(&jeu,2));

        SDL_Flip(screen);

    } /* fin de la boucle principale */

    printf("Sortie du programme --- \n");
    return 0;
}

void affiche_score(int s1, int s2)
{
    /* pour monter ou descendre les scores */
    int decalage_y;
    decalage_y = 50;
    /* position d'affichage */
    SDL_Rect pos;
    pos.x = 50;
    pos.y = 150 + decalage_y;

    SDL_BlitSurface(texte_scores, 0, screen, &pos);

    pos.x = 100;
    pos.y = 190 + decalage_y;

    while(s1!=0)
    {
        SDL_BlitSurface(chiffres[s1%10], 0, screen, &pos);
        pos.x -= chiffres[s1%10]->w;
        s1 /= 10;
    }

    dessinepion1(140,165 + decalage_y);


    pos.x = 100;
    pos.y = 240 + decalage_y;

    while(s2!=0)
    {
        SDL_BlitSurface(chiffres[s2%10], 0, screen, &pos);
        pos.x -= chiffres[s2%10]->w;
        s2 /= 10;
    }

    dessinepion2(140,215 + decalage_y);

}

