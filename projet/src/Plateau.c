#include <stdlib.h>
#include <stdio.h>

#include "Case.h"
#include "Plateau.h"
#include <SDL/SDL.h>
#include <SDL_image.h>

void plateauInit(Plateau* p, int capa)
{
    p->capacite = capa;
    p->places_libres = 0;

    p->support = (Case **) malloc(sizeof(Case)*capa);
    if(p->support==0)
    {
        printf("Erreur d'allocation pour le tableau de Cases.");
        exit(-1);
    }
}


int getPlacesLibres(const Plateau* p)
{
    return p->places_libres;
}

void affichePiece(Plateau* p)
{
    int i;
    Case* ca;
    for(i=0;i<p->capacite;i++)
    {
        ca = p->support[i];
        if(getJoueur(ca)==1)
        dessinepion1(ca[i].posX,ca[i].posY);
        else
        dessinepion2(ca[i].posX,ca[i].posY);
    }
}

void dessinepion1(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((screen->w - pion1->w) / 2)+posX;
    dstrect.y = ((screen->h - pion1->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(pion1, 0, screen, &dstrect);
        // finally, update the screen :)


        SDL_Flip(screen);
}
void dessinepion2(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((screen->w - pion2->w) / 2)+posX;
    dstrect.y = ((screen->h - pion2->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(pion2, 0, screen, &dstrect);
        // finally, update the screen :)

        SDL_Flip(screen);
}
void dessineCase(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((screen->w - case_vide->w) / 2)+posX;
    dstrect.y = ((screen->h - case_vide->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(case_vide, 0, screen, &dstrect);
        // finally, update the screen :)

        SDL_Flip(screen);
}


void lirePlateau(Plateau* p, const char filename[])
{
    FILE* f;
	int lecture;
	int i, capacite, x, y;

    f = fopen(filename, "r");
    if (f==NULL)
    {
        printf("Erreur lors de l'ouverture de %s", filename);
        exit(-1);
    }

    lecture = fscanf( f , "%d", &capacite);
    if(lecture!=1)
    {
        printf("Erreur de lecture de la taille du plateau.");
        exit(-1);
    }

    plateauInit(p, capacite);

    for(i=0;i<capacite;i++)
    {
        lecture = fscanf(f, "\n%d,%d", &x, &y);
        if(lecture != 2)
        {
            printf("Erreur de lecture de la case.\n");
        }
        else
        {
            p->support[i] = caseInit();
            setPos(p->support[i], x, y);
        }
    }
    fclose(f);
}
