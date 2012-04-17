#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"

#include <SDL/SDL.h>
#include <SDL_image.h>


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

    /* on charge l'image d'un case (normale et jouable) */
    case_vide = IMG_Load(CASE_VIDE);
    case_jouable = IMG_Load(CASE_JOUABLE);

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

    dessinepion1(160,230);
    dessinepion1(-160,230+2*UNITE_Y);
    dessinepion1(197.5,267.5);
    dessinepion2(-160,230);
    affichePlateau(&jeu);

    /* boucle principale du programme */
    int done = 0;
    while (done==0)
    {
        /* détection des événements */
        SDL_Event event;
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
            } /* fin du test des événements */
        }

    } /* fin de la boucle principale */


    printf("Sortie du programme --- \n");
    return 0;
}

