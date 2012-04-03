#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"

#include <SDL/SDL.h>
#include <SDL_image.h>
   SDL_Surface* rubis;
   SDL_Surface* screen;

void dessineRubi(int posX,int posY);
void dessinePerle(int posX,int posY);

int main ()
{
    rubis=IMG_Load(PION_JOUEUR_1);
    screen = SDL_SetVideoMode(1100, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 1100X800 video: %s\n", SDL_GetError());
        return 1;
    }
    if (!rubis)
    {
        printf("Unable to load image: %s\n", SDL_GetError());
        return 1;
    }

     // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    dessineRubi(160,230);
    dessineRubi(1,2);

    // create a new window
    // program main loop
    int done = 0;
    while (done==0)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = 1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = 1;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE




        // DRAWING ENDS HERE


    } // end main loop

    // free loaded bitmap


    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

void dessineRubi(int posX,int posY)
{
     // load an image

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((screen->w - rubis->w) / 2)+posX;
    dstrect.y = ((screen->h - rubis->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(rubis, 0, screen, &dstrect);
        // finally, update the screen :)


        SDL_Flip(screen);
}
void dessinePerle(int posX,int posY)
{


     // load an image
    SDL_Surface* Perle = IMG_Load(PION_JOUEUR_2);

    if (!Perle)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((screen->w - Perle->w) / 2)+posX;
    dstrect.y = ((screen->h - Perle->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(Perle, 0, screen, &dstrect);
        // finally, update the screen :)

        SDL_Flip(screen);
}
