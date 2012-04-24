#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Case.h"
#include "Plateau.h"
#include <SDL/SDL.h>
#include <SDL_image.h>
const int pos1[] = {0,2, 0,-2, 1,1, -1,-1, -1,1, 1,-1};
const int pos2[] = {0,4, 0,-4, 2,0, -2,0, 2,2, 1,3, -2,-2, -1,-3, -1,3, -2,2, 1,-3, 2,-2};
 /*
    les valeurs du tableau pos1 et du tableaû pos2 sont à lire 2 par 2
    pos1 : les valeurs correspondent à des décalages par rapport à C
    pos2 : les valeurs correspondent à des décalages de 2 cases par rapport à
    */

void plateauInit(Plateau* p, int capa)
{
    p->capacite = capa;
    p->places_libres = capa;

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

void decrementePlacesLibres(Plateau* p)
{
    p->places_libres -= 1;
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
            dessinepion1(UNITE_X*(getX(ca)+DECAL_X),UNITE_Y*(getY(ca)+DECAL_Y));
        else if(getJoueur(ca)==2)
            dessinepion2(UNITE_X*(getX(ca)+DECAL_X),UNITE_Y*(getY(ca)+DECAL_Y));
    }
}

void dessinepion1(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = posX;
    dstrect.y = posY;
    // draw bitmap
        SDL_BlitSurface(pion1, 0, screen, &dstrect);
}
void dessinepion2(int posX,int posY)
{
    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = posX;
    dstrect.y = posY;
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
    else if(C==1)
        SDL_BlitSurface(case_jouable, 0, screen, &dstrect);
    else if(C==2)
        SDL_BlitSurface(case_jouable_3, 0, screen, &dstrect);
    else
        SDL_BlitSurface(case_jouable_4, 0, screen, &dstrect);
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
	int i, capacite, x, y, j;

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
        lecture = fscanf(f, "\n%d,%d,%d", &x, &y, &j);
        if(lecture != 3)
        {
            printf("Erreur de lecture de la case.\n");
        }
        else
        {
            p->support[i] = caseInit();
            setPos(p->support[i], x, y);
            changeJoueur(p->support[i], j);
        }
    }
    fclose(f);
}

void casesAutour(const Plateau* p,Case* c)
{
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    int x, y; /* coordonnées de ctemp */
    Case* ctemp;

    cx = getX(c);
    cy = getY(c);

    /* on parcourt le tableau */
    for(i=0;i<(p->capacite);i++)
    {
        ctemp = p->support[i];
        x = UNITE_X*(getX(ctemp)+DECAL_X);
        y = UNITE_Y*(getY(ctemp)+DECAL_Y);
        for(j=0;j<12;j+=2)
        {
             /* allumer cette case qui se touve juste à côté de c */
             if((coordonneeCorrespondante(ctemp,cx+pos1[j],cy+pos1[j+1])==1) && (getLibre(ctemp)==1))
             {
                dessineCase(x,y,2);
             }
        }
        for(j=0;j<24;j+=2)
        {
             /* allumer cette case qui se touve à 2 cases de c */
             if((coordonneeCorrespondante(ctemp,cx+pos2[j],cy+pos2[j+1])==1) && (getLibre(ctemp)==1))
             {
                dessineCase(x,y,3);
             }
        }
    }
}
int testCaseProche(int x,int y)
{
    int i;
    for(i=0;i<12;i+=2)
    {
        if(x==pos1[i]&&y==pos1[i+1])
            return 1;
    }
    for(i=0;i<24;i+=2)
    {
        if(x==pos2[i]&&y==pos2[i+1])
        return 2;
    }
    return 0;
}

void changeCasesAutour(const Plateau* p,Case* c,int joueur)
{
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    int x, y; /* coordonnées de ctemp */
    Case* ctemp;

    cx = getX(c);
    cy = getY(c);

    /* on parcourt le tableau */
    for(i=0;i<(p->capacite);i++)
    {
        ctemp = p->support[i];
        x = UNITE_X*(getX(ctemp)+DECAL_X);
        y = UNITE_Y*(getY(ctemp)+DECAL_Y);
        for(j=0;j<12;j+=2)
        {
             /* allumer cette case qui se touve juste à côté de c */
             if((coordonneeCorrespondante(ctemp,cx+pos1[j],cy+pos1[j+1])==1) && (getLibre(ctemp)==0))
             {
                changeJoueur(ctemp,joueur);
             }
        }
    }
}
