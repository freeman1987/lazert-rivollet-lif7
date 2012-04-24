#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

void affichePlateau(Plateau* p)
{
    int i;
    for(i=0;i<p->capacite;i++)
    {
        dessineCase(UNITE_X*(getX(p->support[i])+DECAL_X),UNITE_Y*(getY(p->support[i])+DECAL_Y),0);
    }
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
}
void dessinepion2(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = ((case_vide->w - pion2->w) / 2)+posX;
    dstrect.y = ((case_vide->h - pion2->h) / 2)+posY;
    // draw bitmap
        SDL_BlitSurface(pion2, 0, screen, &dstrect);
}
void dessineCase(float posX,float posY,int C)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (int)posX;
    dstrect.y = (int)posY;
    // draw bitmap
    if(C==0)
        SDL_BlitSurface(case_vide, 0, screen, &dstrect);
    else
        SDL_BlitSurface(case_jouable, 0, screen, &dstrect);
}

int sourisDansCase(int sx, int sy, const Case* c)
{
    int cx, cy;
    float dist;
    cx = (getX(c) + DECAL_X) * UNITE_X + (case_vide->w/2);
    cy = (getY(c) + DECAL_Y) * UNITE_Y + (case_vide->w/2);
    dist = sqrt(pow(cx - sx,2) + pow(cy - sy,2));

    /*
    // affichage pour débeug
    printf("souris : %u,%u\n",sx,sy);
    printf("case : %u,%u\n",cx,cy);
    printf("distance : %f\n",dist);
    */

    if(dist<=UNITE_Y)
        return 1;
    else
        return 0;
}

Case* caseSurvollee(int sx, int sy, const Plateau* p)
{
    int i;
    for(i=0;i<p->capacite;i++)
    {
        if(sourisDansCase(sx, sy, p->support[i])==1)
            return p->support[i];
    }
    /* aucune case survollée */
    return 0;
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

void casesAutour(const Plateau* p,Case* c)
{
    /*
    les valeurs du tableau pos1 et du tableaû pos2 sont à lire 2 par 2
    pos1 : les valeurs correspondent à des décalages par rapport à C
    pos2 : les valeurs correspondent à des décalages de 2 cases par rapport à
    */
    int pos1[] = {0,2, 0,-2, 1,1 -1,-1, -1,1, 1,-1};
    int pos2[] = {0,4, 0,-4, 2,0, -2,0, 2,2, 3,1 -2,-2, -3,-1, -3,1, -2,2, 3,-1, 2,-2};
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    int x, y; /* coordonnées de ctemp */
    Case* ctemp;

    cx = getX(c);
    cy = getY(c);

    /* on parcourt le tableau */
    for(i=0;i<(p->capacite);i++)
    {
        printf("Boucle %d\n",i);
        ctemp = p->support[i];
        x = UNITE_X*(getX(ctemp)+DECAL_X);
        y = UNITE_Y*(getY(ctemp)+DECAL_Y);
        for(j=0;j<12;j+=2)
        {
             printf("\tsous boucle %d\n",j);
             /* allumer cette case qui se touve juste à côté de c */
             if(coordonneeCorrespondante(ctemp,cx+pos1[j],cy+pos1[j+1])==1)
             {
                dessineCase(x,y,1);
             }
        }
       /* for(j=0;j<24;j+=2)
        {
             printf("\tsous boucle %d\n",j);
             /* allumer cette case qui se touve à 2 cases de c *
             if(coordonneeCorrespondante(ctemp,cx+pos2[j],cy+pos2[j+1])==1)
             {
                dessineCase(x,y,1);
             }
        }*/



    }
}
