#include "affiche.h"

SDL_Rect xy2rect(int x, int y)
{
    SDL_Rect retour;

    retour.x = UNITE_X * (x + DECAL_X);
    retour.y = UNITE_Y * (y + DECAL_Y);

    return retour;
}

void afficheQuiJoue(int j, SDL_Surface* ecran)
{
    SDL_Rect place_qui_joue;
    SDL_Surface* logo_joueur;

    place_qui_joue.x = 50;
    place_qui_joue.y = 50;

    if(j==1)
        logo_joueur = IMG_Load(LOGO_JOUEUR_1);
    else if(j==2)
        logo_joueur = IMG_Load(LOGO_JOUEUR_2);

    SDL_BlitSurface(logo_joueur, 0, ecran, &place_qui_joue);
    SDL_FreeSurface(logo_joueur);
}

void afficheScores(int s1, int s2, SDL_Surface* chiffres[], SDL_Surface* haut, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran)
{
    /* pour monter ou descendre les scores */
    int decalage_y;
    decalage_y = 50;

    /* position d'affichage */
    SDL_Rect pos;
    pos.x = 50;
    pos.y = 150 + decalage_y;

    SDL_BlitSurface(haut, 0, ecran, &pos);

    /* score du joueur 1 */
    pos.x = 100;
    pos.y += haut->h + 15;

    if(s1==0)
        SDL_BlitSurface(chiffres[0], 0, ecran, &pos);
    else
        while(s1!=0)
        {
            SDL_BlitSurface(chiffres[s1%10], 0, ecran, &pos);
            pos.x -= chiffres[s1%10]->w;
            s1 /= 10;
        }

    afficheImage(140,165 + decalage_y,pion_j1,ecran);

    /* score du joueur 2 */

    pos.x = 100;
    pos.y = 240 + decalage_y;

    if(s2==0)
        SDL_BlitSurface(chiffres[0], 0, ecran, &pos);
    else
        while(s2!=0)
        {
            SDL_BlitSurface(chiffres[s2%10], 0, ecran, &pos);
            pos.x -= chiffres[s2%10]->w;
            s2 /= 10;
        }

    afficheImage(140,215 + decalage_y,pion_j2,ecran);
}

void afficheFinJeu(int s1, int s2, SDL_Surface* ecran)
{
    SDL_Rect pos;
    SDL_Surface* bravo;

    if(s1==s2)
        bravo = IMG_Load(BRAVO_0);
    else if(s1>s2)
        bravo = IMG_Load(BRAVO_1);
    else
        bravo = IMG_Load(BRAVO_2);

    pos.x = (ecran->w - bravo->w)/2;
    pos.y = (ecran->h - bravo->h)/2;

    SDL_BlitSurface(bravo, 0, ecran, &pos);
    SDL_FreeSurface(bravo);
}

void afficheImage(int x, int y, SDL_Surface* image, SDL_Surface* ecran)
{
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;

    SDL_BlitSurface(image, 0, ecran, &dstrect);
}

void afficheImageRect(SDL_Rect rect, SDL_Surface* image, SDL_Surface* ecran)
{
    SDL_BlitSurface(image, 0, ecran, &rect);
}

void afficheJeu(const Plateau* p, SDL_Surface* image_case, SDL_Surface* pion_j1, SDL_Surface* pion_j2, SDL_Surface* ecran)
{
    int i;
    SDL_Rect position;
    Case* c;
    for(i=0;i<plateauGetCapacite(p);i++)
    {
        c = plateauGetCaseI(p,i);
        position = xy2rect(caseGetX(c),caseGetY(c));

        afficheImageRect(position,image_case,ecran);

        if(caseGetLibre(c)==0) /* il y a un pion */
        {
            if(caseGetJoueur(c)==1)
                afficheImageRect(position, pion_j1, ecran);
            else if(caseGetJoueur(c)==2)
                afficheImageRect(position, pion_j2, ecran);
        }
    }
}

void afficheVerifChargement(SDL_Surface* img)
{
    if(img==0)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        exit(-1);
    }
}

void afficheCaseJeu(const Case* c, SDL_Surface* image, SDL_Surface* ecran)
{
    SDL_Rect position;
    position = xy2rect(caseGetX(c),caseGetY(c));
    afficheImageRect(position, image,ecran);
}

void afficheCasesAutour(const Plateau* p, const Case* c, SDL_Surface* img_dupliquer, SDL_Surface* img_deplacer, SDL_Surface* ecran)
{

    Case* ctmp;
    int xtmp, ytmp;

    int x,y;
    x = caseGetX(c);
    y = caseGetY(c);

    int dist;

    int i;

    for(i=0;i<plateauGetCapacite(p);i++)
    {
        ctmp = plateauGetCaseI(p,i);
        xtmp = caseGetX(ctmp);
        ytmp = caseGetY(ctmp);
        dist = plateauTestCaseProche(xtmp-x,ytmp-y);

        if(dist==1 && caseGetLibre(ctmp)==1)
            afficheCaseJeu(ctmp,img_dupliquer,ecran);
        else if(dist==2 && caseGetLibre(ctmp)==1)
            afficheCaseJeu(ctmp,img_deplacer,ecran);
    }
}
