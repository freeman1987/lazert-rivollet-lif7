#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int menuPrincipal()
{
    SDL_Surface* screen;
    SDL_Surface* menu;
    SDL_Event event;

    /* variables pour contenir les coordonnées de la souris */
    int sourisx;
    int sourisy;

    int retour = 1; /* par défaut, on joue */


    /* boucle principale du programme */
    int done = 0;


    /* MENU PRINCIPAL */

    menu = IMG_Load(MENU); afficheVerifChargement(menu);


    /* INITIALISATIONS POUR L'AFFICHAGE SDL */

        /* on charge l'écran d'affichage */

        screen = SDL_SetVideoMode(500, 500, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
        if (!screen)
        {
            printf("Erreur de définition de l'écran video : %s\n", SDL_GetError());
            return 1;
        }
        /* on initialise SDL video */
        if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            printf( "Erreur d'initialisation SDL: %s\n", SDL_GetError() );
            return 1;
        }
        /* make sure SDL cleans up before exit */
        atexit(SDL_Quit);



    while (done==0)
    {
        /* vider l'écran */
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 2, 15, 30));

        SDL_PollEvent(&event);
        /* récupérer la position de la souris sur l'écran */
        sourisx = event.motion.x;
        sourisy = event.motion.y;

        switch(event.type)
        {
            /* fermer */
            case SDL_QUIT:
            {
                done = 1;
                retour = 0;
            }
            break;

            /* touche enfoncée */
            case SDL_KEYDOWN:
            {
                /* fermer */
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                    retour = 0;
                }
            }
            break;
        }

        SDL_Flip(screen);
    }

    SDL_Quit();

    return retour;
}
