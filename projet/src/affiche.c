#include <stdlib.h>
#include <stdio.h>

#include "affiche.h"
#include <SDL/SDL.h>


void afficheQuiJoue(int j)
{
    SDL_Rect place_qui_joue;
    SDL_Surface* logo_joueur;

    place_qui_joue.x = 50;
    place_qui_joue.y = 50;

    if(j==1)
        logo_joueur = IMG_Load(LOGO_JOUEUR_1);
    else if(j==2)
        logo_joueur = IMG_Load(LOGO_JOUEUR_2);

    SDL_BlitSurface(logo_joueur, 0, screen, &place_qui_joue);
}

void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion1, SDL_Surface* pion2)
{
    /* pour monter ou descendre les scores */
    int decalage_y;
    decalage_y = 50;

    /* position d'affichage */
    SDL_Rect pos;
    pos.x = 50;
    pos.y = 150 + decalage_y;

    SDL_BlitSurface(haut, 0, screen, &pos);

    /* score du joueur 1 */
    pos.x = 100;
    pos.y += haut->h + 5;

    if(s1==0)
        SDL_BlitSurface(chiffres[0], 0, screen, &pos);
    else
        while(s1!=0)
        {
            SDL_BlitSurface(chiffres[s1%10], 0, screen, &pos);
            pos.x -= chiffres[s1%10]->w;
            s1 /= 10;
        }

    affichePion(140,165 + decalage_y,pion1);

    /* score du joueur 2 */

    pos.x = 100;
    pos.y = 240 + decalage_y;

    if(s2==0)
        SDL_BlitSurface(chiffres[0], 0, screen, &pos);
    else
        while(s2!=0)
        {
            SDL_BlitSurface(chiffres[s2%10], 0, screen, &pos);
            pos.x -= chiffres[s2%10]->w;
            s2 /= 10;
        }

    affichePion(140,215 + decalage_y,pion2);
}

void afficheFinJeu(int s1, int s2)
{
    SDL_Rect pos;
    SDL_Surface* bravo;

    if(s1==s2)
        bravo = IMG_Load(BRAVO_0);
    else if(s1>s2)
        bravo = IMG_Load(BRAVO_1);
    else
        bravo = IMG_Load(BRAVO_2);

    pos.x = (screen->w - bravo->w)/2;
    pos.y = (screen->h - bravo->h)/2;

    SDL_BlitSurface(bravo, 0, screen, &pos);
}

void affichePion(int x, int y, SDL_Surface* image)
{
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;

    SDL_BlitSurface(image, 0, screen, &dstrect);
}

void afficheJeu(const Plateau* p)
{
    int i;
    Case* c;
    for(i=0;i<plateauGetCapacite(p);i++)
    {
        c = plateauGetCaseI(p,i);
        printf("Case %d : adresse %d\n",i,(int) c);
    }
}
