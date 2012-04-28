#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Case.h"
#include "Plateau.h"
#include <SDL/SDL.h>
#include <SDL_image.h>

    /*
    VALEURS POUR TROUVER DES CASES ADJACENTES A UNE CASE
    les valeurs du tableau pos1 et du tableaû pos2 sont à lire 2 par 2
    pos1 : les valeurs correspondent à des décalages d'une case par rapport à C
    pos2 : les valeurs correspondent à des décalages de 2 cases par rapport à
    */
    const int pos1[] = {0,2, 0,-2, 1,1, -1,-1, -1,1, 1,-1};
    const int pos2[] = {0,4, 0,-4, 2,0, -2,0, 2,2, 1,3, -2,-2, -1,-3, -1,3, -2,2, 1,-3, 2,-2};


void plateauInit(Plateau* p, int capa)
{
    /* nombre de places au total sur la plateau */
    p->capacite = capa;
    p->places_libres = capa;

    p->score_j1 = 0;
    p->score_j2 = 0;

    p->support = (Case **) malloc(sizeof(Case)*capa);
    if(p->support==0)
    {
        printf("Erreur d'allocation pour le tableau de Cases.");
        exit(-1);
    }
}

int plateauGetPlacesLibres(Plateau* p)
{
    return p->places_libres;
}

int plateauGetCapacite(const Plateau* p)
{
    return p->capacite;
}

Case* plateauGetCaseI(const Plateau* p, int i)
{
    if(0<=i && i<p->capacite)
        return p->support[i];
    else
        return 0;
}

void plateauChangeJoueur(Plateau* p, Case* c, int joueur)
{
    /* on regarde quel joueur avait un pion sur la case pour changer son score */
    if(caseGetJoueur(c)==1)
        p->score_j1--;
    else if(caseGetJoueur(c)==2)
        p->score_j2--;

    if(joueur==0) /* liberer la case */
    {
        caseSetLibre(c,1);
    }
    else if(joueur==1) /* mettre le joueur 1 */
    {
        p->score_j1++;
        caseSetJoueur(c,1);
    }
    else if(joueur==2)
    {
        p->score_j2++;
        caseSetJoueur(c,2);
    }
}

void plateauDecrementePlacesLibres(Plateau* p)
{
    p->places_libres--;
}

void affichePlateau(Plateau* p)
{
    int i;
    for(i=0;i<p->capacite;i++)
    {
        dessineCase(UNITE_X*(caseGetX(p->support[i])+DECAL_X),UNITE_Y*(caseGetY(p->support[i])+DECAL_Y),0);
    }
}

void affichePiece(Plateau* p)
{
    int i;
    Case* ca;
    for(i=0;i<p->capacite;i++)
    {
        ca = p->support[i];
        if(caseGetJoueur(ca)==1)
            dessinepion1(UNITE_X*(caseGetX(ca)+DECAL_X),UNITE_Y*(caseGetY(ca)+DECAL_Y));
        else if(caseGetJoueur(ca)==2)
            dessinepion2(UNITE_X*(caseGetX(ca)+DECAL_X),UNITE_Y*(caseGetY(ca)+DECAL_Y));
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

void dessinepion2(int posX, int posY)
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
    cx = (caseGetX(c) + DECAL_X) * UNITE_X + (case_vide->w/2);
    cy = (caseGetY(c) + DECAL_Y) * UNITE_Y + (case_vide->w/2);
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
	int i, capacite, x, y, j, scor_j1, scor_j2;
	scor_j1 = 0;
	scor_j2 = 0;

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

    /* on initialise la plateau en allouant le bon nombre de cases */
    plateauInit(p, capacite);

    /* on lit ensuite toutes les cases :
    chaque ligne du fichier texte comprend 3 valeurs séparées par des virgules :
    coordonnée x, coordonnée y, joueur (0 pour aucun, 1 ou 2) */
    for(i=0;i<capacite;i++)
    {
        lecture = fscanf(f, "\n%d,%d,%d", &x, &y, &j);
        if(lecture != 3)
        {
            printf("Erreur de lecture de la case.\n");
        }
        else
        {
            /* on crée une case */
            p->support[i] = caseInit();
            caseSetPos(p->support[i], x, y);
            plateauChangeJoueur(p, p->support[i], j);
            /* si il y a un joueur dans la case, on diminue le nombre de cases libres */
            if(j!=0)
            {
                 p->places_libres -= 1;
            }

            if(j==1)
                scor_j1++;
            else if(j==2)
                scor_j2++;
        }
    }

    p->score_j1 = scor_j1;
    p->score_j2 = scor_j2;

    fclose(f);
}

void casesAutour(const Plateau* p,Case* c)
{
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    int x, y; /* coordonnées de ctemp */
    Case* ctemp;

    cx = caseGetX(c);
    cy = caseGetY(c);

    /* on parcourt le tableau */
    for(i=0;i<(p->capacite);i++)
    {
        ctemp = p->support[i];
        x = UNITE_X*(caseGetX(ctemp)+DECAL_X);
        y = UNITE_Y*(caseGetY(ctemp)+DECAL_Y);
        for(j=0;j<12;j+=2)
        {
             /* allumer cette case qui se touve juste à côté de c */
             if((caseTestCoordonnees(ctemp,cx+pos1[j],cy+pos1[j+1])==1) && (caseGetLibre(ctemp)==1))
             {
                dessineCase(x,y,2);
             }
        }
        for(j=0;j<24;j+=2)
        {
             /* allumer cette case qui se touve à 2 cases de c */
             if((caseTestCoordonnees(ctemp,cx+pos2[j],cy+pos2[j+1])==1) && (caseGetLibre(ctemp)==1))
             {
                dessineCase(x,y,3);
             }
        }
    }
}

int nbPossibilites(const Plateau* p,Case* c)
{
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    Case* ctemp;
    int retour;
    retour = 0;

    cx = caseGetX(c);
    cy = caseGetY(c);

    /* on parcourt le tableau pour compteur les cases libres autour de c */
    for(i=0;i<(p->capacite);i++)
    {
        ctemp = p->support[i];
        for(j=0;j<12;j+=2)
        {
             if((caseTestCoordonnees(ctemp,cx+pos1[j],cy+pos1[j+1])==1) && (caseGetLibre(ctemp)==1))
                retour++;
        }
        for(j=0;j<24;j+=2)
        {
             if((caseTestCoordonnees(ctemp,cx+pos2[j],cy+pos2[j+1])==1) && (caseGetLibre(ctemp)==1))
                retour++;
        }
    }

    return retour;
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

void changeCasesAutour(Plateau* p,Case* c,int joueur)
{
    int i,j; /* pour les boucles */
    int cx, cy; /* coordonnées de c */
    Case* ctemp;

    cx = caseGetX(c);
    cy = caseGetY(c);

    /* on parcourt le tableau */
    for(i=0;i<(p->capacite);i++)
    {
        ctemp = p->support[i];
        for(j=0;j<12;j+=2)
        {
             /* allumer cette case qui se touve juste à côté de c */
             if((caseTestCoordonnees(ctemp,cx+pos1[j],cy+pos1[j+1])==1) && (caseGetLibre(ctemp)==0)&&(caseGetJoueur(ctemp)!=joueur))
             {
                plateauChangeJoueur(p, ctemp,joueur);
             }
        }
    }
}

int getScore(const Plateau* p, int j)
{
    if(j==1)
        return p->score_j1;
    else if(j==2)
        return p->score_j2;
    else
        return 0;
}

int peutJouer(const Plateau* p, int j)
{
    int i;
    Case* ctemp;

    /* on parcourt toutes les cases du plateau qui appartiennent au joueur */
    for(i=0;i<p->capacite;i++)
    {
        ctemp = p->support[i];
        if(caseGetJoueur(ctemp)==j)
        {
            /* si au moins une a une possibilité de déplacement */
            if(nbPossibilites(p,ctemp)>=1)
                return 1;
        }
    }

    return 0;
}

void remplirPlateau(Plateau* p, int j)
{
    int i;
    int cpt;
    Case* ctemp;

    cpt = 0;
    /* on parcourt toutes les cases du plateau */
    for(i=0;i<p->capacite;i++)
    {
        ctemp = p->support[i];
        if(caseGetLibre(ctemp)==1)
        {
            /* si la case est libre */
            caseSetJoueur(ctemp,j);
            cpt++;
        }
    }

    if(j==1)
        p->score_j1 += cpt;
    else if(j==2)
        p->score_j2 += cpt;
}

void plateauTestament(Plateau* p)
{
    int i;

    /* libérer toutes les cases */
    for(i=0;i<(p->capacite);i++)
    {
        printf("Lecture du plateau : case %u\n\t", i);
        caseTestament(p->support[i]);
        p->support[i] = 0;
    }

    printf("Libérer le tableau de cases à l'adresse %u \n", (int) p->support);
    if(p->support!=0)
        free(p->support);
    p->support = 0;
    p->capacite = 0;
    p->places_libres = 0;

    p->score_j1 = 0;
    p->score_j2 = 0;
}
