#include "affiche.h"

Rectangle xy2rect(int x, int y)
{
    Rectangle retour;

    retour.x = UNITE_X * (x + DECAL_X);
    retour.y = UNITE_Y * (y + DECAL_Y);

    return retour;
}

int afficheInit()
{
    return (int) SDL_Init(SDL_INIT_VIDEO);
}

void afficheQuiJoue(int j, Image* ecran)
{
    Rectangle place_qui_joue;
    Image* logo_joueur;

    place_qui_joue.x = 50;
    place_qui_joue.y = 50;

    if(j==1)
        logo_joueur = IMG_Load(LOGO_JOUEUR_1);
    else if(j==2)
        logo_joueur = IMG_Load(LOGO_JOUEUR_2);

    SDL_BlitSurface(logo_joueur, 0, ecran, &place_qui_joue);
    SDL_FreeSurface(logo_joueur);
}

void afficheScores(int s1, int s2, Image* chiffres[], Image* haut, Image* pion_j1, Image* pion_j2, Image* ecran)
{
    /* pour monter ou descendre les scores */
    int decalage_y;


    /* position d'affichage */
    Rectangle pos;

    decalage_y = 50;
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

void afficheNiveauOrdinateur(int x, int y, int niv, Image* chiffre[], Image* ecran)
{
    int niveau;
    if(niv<1)
        niveau = 1;
    else if(niv>9)
        niveau = 9;
    else
        niveau = niv;

    afficheImage(x,y,chiffre[niveau],ecran);
}

void afficheFinJeu(int s1, int s2, int ordi, Image* ecran)
{
    Rectangle pos;
    Image* bravo;

    if(s1==s2)
        bravo = IMG_Load(BRAVO_0);
    else if(s1<s2 && ordi==0)
        bravo = IMG_Load(BRAVO_2);
    else if(s1<s2 && ordi==1)
        bravo = IMG_Load(BRAVO_3);
    else
        bravo = IMG_Load(BRAVO_1);

    pos.x = (ecran->w - bravo->w)/2 + 90;
    pos.y = (ecran->h - bravo->h)/2 ;

    SDL_BlitSurface(bravo, 0, ecran, &pos);
    SDL_FreeSurface(bravo);
}

void afficheImage(int x, int y, Image* image, Image* ecran)
{
    Rectangle dstrect;
    dstrect.x = x;
    dstrect.y = y;

    SDL_BlitSurface(image, 0, ecran, &dstrect);
}

void afficheImageRect(Rectangle rect, Image* image, Image* ecran)
{
    SDL_BlitSurface(image, 0, ecran, &rect);
}

void afficheJeu(const Plateau* p, Image* image_case, Image* pion_j1, Image* pion_j2, Image* ecran)
{
    int i;
    Rectangle position;
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

void afficheVerifChargement(Image* img)
{
    if(img==0)
    {
        printf("[!] Erreur de chargement de l'image : %s\n",SDL_GetError());
        exit(-1);
    }
}

void afficheCaseJeu(const Case* c, Image* image, Image* ecran)
{
    Rectangle position;
    position = xy2rect(caseGetX(c),caseGetY(c));
    afficheImageRect(position, image,ecran);
}

void afficheCasesAutour(const Plateau* p, const Case* c, Image* img_dupliquer, Image* img_deplacer, Image* ecran)
{

    Case* ctmp;
    int xtmp, ytmp;
    int x,y;
    int dist;
    int i;

    x = caseGetX(c);
    y = caseGetY(c);
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

void afficheFree(Image* img)
{
    SDL_FreeSurface(img);
}

void afficheQuit()
{
    SDL_Quit();
}

void afficheVideEcran(Image* ecran)
{
    SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 2, 15, 30));
}

Image* afficheChargeImage(char fichier[])
{
    return (Image*) IMG_Load(fichier);
}

int afficheEvenements(Evenements* ev)
{
    return (int) SDL_PollEvent(ev);
}

Touche afficheToucheAppuyee(Evenements* ev)
{
    return (Touche) ev->key.keysym.sym;
}

int afficheCoordonneeSouris(Evenements* ev, char coord)
{
    if(coord=='x' || coord=='X')
        return ev->motion.x;
    else
        return ev->motion.y;
}

void afficheMiseAJour(Image* ecran)
{
    SDL_Flip(ecran);
}

Image* afficheSetEcran()
{
    return (Image*) SDL_SetVideoMode(1100, 720, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
}

void afficheErreur()
{
    printf("Détails de l'erreur :\n%s\n",SDL_GetError());
}

void afficheSetTitre(char titre1[], char titre2[])
{
    SDL_WM_SetCaption(titre1, titre2);
}

EvenementsType afficheTypeEvenement(Evenements* ev)
{
    return (EvenementsType) ev->type;
}


int sourisDansRectangle(int x, int y, Rectangle rectangle)
{
    if(x>=rectangle.x && x<=(rectangle.w+rectangle.x) && y>=rectangle.y && y<=(rectangle.h+rectangle.y))
        return 1;
    else
        return 0;
}
