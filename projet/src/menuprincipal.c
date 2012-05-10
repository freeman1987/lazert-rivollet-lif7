#include "menuprincipal.h"

int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau)
{
    SDL_Surface* screen;
    SDL_Surface *menu, *imageContreJoueur, *imageContreOrdi, *imageSelection, *imageBoutonJouer, *imageBoutonJouerSurvol;
    SDL_Surface *imagePlateau[3], *imagePlateauSelectionne;
    SDL_Rect positionPlateau[3];
    SDL_Rect positionMenu, positionContreJoueur, positionContreOrdi, positionBoutonJouer;
    SDL_Event event;

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

        SDL_WM_SetCaption("Hexxagon : Menu du jeu","Hexxagon");

        /* MENU PRINCIPAL */

        menu = IMG_Load(MENU); afficheVerifChargement(menu);
        positionMenu.x = 0;
        positionMenu.y = 0;

        imageContreJoueur = IMG_Load(VSJOUEUR); afficheVerifChargement(imageContreJoueur);
        positionContreJoueur.x = 100;
        positionContreJoueur.y = screen->h - 120;
        positionContreJoueur.h = imageContreJoueur->h;
        positionContreJoueur.w = imageContreJoueur->w;

        imageContreOrdi = IMG_Load(VSORDI); afficheVerifChargement(imageContreOrdi);
        positionContreOrdi.x = 300;
        positionContreOrdi.y = screen->h - 120;
        positionContreOrdi.h = imageContreOrdi->h;
        positionContreOrdi.w = imageContreOrdi->w;

        imagePlateau[0] = IMG_Load(PLATEAU1_MENU); afficheVerifChargement(imagePlateau[0]);
        positionPlateau[0].x = 800;
        positionPlateau[0].y = 20;
        positionPlateau[0].h = imagePlateau[0]->h;
        positionPlateau[0].w = imagePlateau[0]->w;

        imagePlateau[1] = IMG_Load(PLATEAU2_MENU); afficheVerifChargement(imagePlateau[1]);
        positionPlateau[1].x = 800;
        positionPlateau[1].y = 250;
        positionPlateau[1].h = imagePlateau[1]->h;
        positionPlateau[1].w = imagePlateau[1]->w;

        imagePlateau[2] = IMG_Load(PLATEAU3_MENU); afficheVerifChargement(imagePlateau[2]);
        positionPlateau[2].x = 800;
        positionPlateau[2].y = 450;
        positionPlateau[2].h = imagePlateau[2]->h;
        positionPlateau[2].w = imagePlateau[2]->w;

        imagePlateauSelectionne = IMG_Load(PLATEAU_SELECTIONNE_MENU); afficheVerifChargement(imagePlateau[0]);

        imageSelection = IMG_Load(SELECTIONMODE); afficheVerifChargement(imageSelection);

        imageBoutonJouer = IMG_Load(BOUTONJOUER); afficheVerifChargement(imageBoutonJouer);
        imageBoutonJouerSurvol = IMG_Load(BOUTONJOUERSURVOL); afficheVerifChargement(imageBoutonJouerSurvol);
        positionBoutonJouer.x = 600;
        positionBoutonJouer.y = screen->h - 120;
        positionBoutonJouer.h = imageBoutonJouer->h;
        positionBoutonJouer.w = imageBoutonJouer->w;


    while (done==0)
    {
        /* vider l'écran */
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 2, 15, 30));


        /* récupérer la position de la souris sur l'écran */
        sourisx = event.motion.x;
        sourisy = event.motion.y;

        while(SDL_PollEvent(&event))
        {
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
                    }
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                {
                    if(sourisDansRectangle(sourisx,sourisy,positionContreJoueur)) /* clic sur contre joueur */
                    {
                        *contreordinateur = 0;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionContreOrdi)) /* clic sur contre ordi */
                    {
                        *contreordinateur = 1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionBoutonJouer)) /* clic sur bouton jouer */
                    {
                        done = 1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[0]))
                    {
                        *plateau=1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[1]))
                    {
                        *plateau=2;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[2]))
                    {
                        *plateau=3;
                    }

                }
                break;
            }
        }

        SDL_BlitSurface(menu,0,screen,&positionMenu);

        if(*contreordinateur==1)
            SDL_BlitSurface(imageSelection,0,screen,&positionContreOrdi);
        else
            SDL_BlitSurface(imageSelection,0,screen,&positionContreJoueur);

        SDL_BlitSurface(imageContreJoueur,0,screen,&positionContreJoueur);
        SDL_BlitSurface(imageContreOrdi,0,screen,&positionContreOrdi);

        SDL_BlitSurface(imagePlateauSelectionne,0,screen,&positionPlateau[*plateau-1]);
        SDL_BlitSurface(imagePlateau[0],0,screen,&positionPlateau[0]);
        SDL_BlitSurface(imagePlateau[1],0,screen,&positionPlateau[1]);
        SDL_BlitSurface(imagePlateau[2],0,screen,&positionPlateau[2]);

        if(sourisDansRectangle(sourisx,sourisy,positionBoutonJouer))
            SDL_BlitSurface(imageBoutonJouerSurvol,0,screen,&positionBoutonJouer);
        else
            SDL_BlitSurface(imageBoutonJouer,0,screen,&positionBoutonJouer);


        SDL_Flip(screen);
    }

    SDL_Quit();

    return retour;
}

int sourisDansRectangle(int x, int y, SDL_Rect rectangle)
{
    if(x>=rectangle.x && x<=(rectangle.w+rectangle.x) && y>=rectangle.y && y<=(rectangle.h+rectangle.y))
        return 1;
    else
        return 0;
}
