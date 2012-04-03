#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"

#include <SDL/SDL.h>
#include <SDL_image.h>


int main ()
{
    pion2=IMG_Load(PION_JOUEUR_2);
    if ( !pion2 )
    {
        printf("Unable to set 1100X800 video: %s\n", SDL_GetError());
        return 1;
    }
    pion1=IMG_Load(PION_JOUEUR_1);
    if ( !pion1 )
    {
        printf("Unable to load 1100X800 image: %s\n", SDL_GetError());
        return 1;
    }
    case_vide=IMG_Load(CASE_VIDE);
    if ( !case_vide )
    {
        printf("Unable to set 1100X800 video: %s\n", SDL_GetError());
        return 1;
    }
    screen = SDL_SetVideoMode(1100, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 1100X800 video: %s\n", SDL_GetError());
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
    dessinepion1(0,0);
    dessineCase(0,0);
    dessineCase(1+55.5,1+30.5);
    dessineCase(1+55.5,1-30.5);
    dessineCase(1-55.5,1+30.5);
    dessineCase(1-55.5,1-30.5);
    dessineCase(1-2*55.5,1);
    dessineCase(1-2*55.5,1-2*30.5);

    dessinepion1(160,230);
    dessinepion1(-160,230+2*UNITE_Y);
    dessinepion1(197.5,267.5);
    dessinepion2(-160,230);


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

    } // end main loop




    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

