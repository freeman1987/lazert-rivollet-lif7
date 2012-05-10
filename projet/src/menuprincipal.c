#include "menuprincipal.h"

int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau)
{
    SDL_Surface* screen;
    SDL_Surface* menu, *imageContreJoueur, *imageContreOrdi, *imageSelection;
    SDL_Rect positionMenu, positionContreJoueur, positionContreOrdi;
    SDL_Event event;

    *contreordinateur = 1;
    *niveauordinateur = 1;
    *plateau = 1;

    /* variables pour contenir les coordonnées de la souris */
    int sourisx;
    int sourisy;

    int retour = 1; /* par défaut, on joue */


    /* boucle principale du programme */
    int done = 0;





    /* INITIALISATIONS POUR L'AFFICHAGE SDL */

        /* on charge l'écran d'affichage */

        screen = SDL_SetVideoMode(1100, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
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

        /* MENU PRINCIPAL */

        menu = IMG_Load(MENU); afficheVerifChargement(menu);
        positionMenu.x = 0;
        positionMenu.y = 0;

        imageContreJoueur = IMG_Load(VSJOUEUR); afficheVerifChargement(imageContreJoueur);
        positionContreJoueur.x = 100;
        positionContreJoueur.y = screen->h - 200;

        imageContreOrdi = IMG_Load(VSORDI); afficheVerifChargement(imageContreOrdi);
        positionContreOrdi.x = 300;
        positionContreOrdi.y = screen->h - 200;

        imageSelection = IMG_Load(SELECTIONMODE); afficheVerifChargement(imageSelection);


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

                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    done = 1;
                    retour = 1;
                }

                if((event.key.keysym.sym == SDLK_LEFT && *contreordinateur==1) || (event.key.keysym.sym == SDLK_RIGHT && *contreordinateur==0))
                {
                    *contreordinateur = ((*contreordinateur + 1) % 2);
                    printf("Changement mode jeu %d\n",*contreordinateur);
                }
            }
            break;
        }

        SDL_BlitSurface(menu,0,screen,&positionMenu);

        if(*contreordinateur==1)
            SDL_BlitSurface(imageSelection,0,screen,&positionContreOrdi);
        else
            SDL_BlitSurface(imageSelection,0,screen,&positionContreJoueur);

        SDL_BlitSurface(imageContreJoueur,0,screen,&positionContreJoueur);
        SDL_BlitSurface(imageContreOrdi,0,screen,&positionContreOrdi);


        SDL_Flip(screen);
    }

    SDL_Quit();

    return retour;
}
