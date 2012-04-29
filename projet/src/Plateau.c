#include "Case.h"
#include "Plateau.h"

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
        printf("Erreur d'allocation pour le tableau de %d Cases.",capa);
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
    if(0<=i && i<(p->capacite))
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

int plateauSourisDansCase(int sx, int sy, const Case* c, int dim)
{
    int cx, cy;
    float dist;
    cx = (int) ((caseGetX(c) + DECAL_X) * UNITE_X + (dim/2));
    cy = (int) ((caseGetY(c) + DECAL_Y) * UNITE_Y + (dim/2));
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

Case* plateauCaseSurvollee(int sx, int sy, const Plateau* p, int dim)
{
    int i;
    for(i=0;i<p->capacite;i++)
    {
        if(plateauSourisDansCase(sx, sy, p->support[i],dim)==1)
            return p->support[i];
    }
    /* aucune case survollée */
    return 0;
}

void plateauLireFichier(Plateau* p, const char filename[])
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

int plateauNbPossibilites(const Plateau* p,Case* c)
{
    Case* ctmp;
    int xtmp, ytmp;

    int x,y;
    x = caseGetX(c);
    y = caseGetY(c);

    int dist;

    int retour;
    retour = 0;

    int i;

    #if COMMENTAIRES==1
        printf("\tOn compte le nombre de possibilités pour le case %d.\n",(int) c);
    #endif

    for(i=0;i<plateauGetCapacite(p);i++)
    {
        ctmp = plateauGetCaseI(p,i);
        xtmp = caseGetX(ctmp);
        ytmp = caseGetY(ctmp);
        dist = plateauTestCaseProche(xtmp-x,ytmp-y);

        if(dist>0 && caseGetLibre(ctmp)==1)
        {
            retour++;

            #if COMMENTAIRES==1
                printf("\t\tcase trouvée => %d\n",retour);
            #endif
        }
    }

    return retour;
}

int plateauTestCaseProche(int x,int y)
{
    int i;
    /*
    Remarque importante : les valeurs du tableau pos1 et du tableau pos2 sont à lire 2 par 2
    pos1 : les valeurs correspondent à des décalages d'une case par rapport à C
    pos2 : les valeurs correspondent à des décalages de 2 cases par rapport à
    */
    const int pos1[] = {0,2, 0,-2, 1,1, -1,-1, -1,1, 1,-1};
    const int pos2[] = {0,4, 0,-4, 2,0, -2,0, 2,2, 1,3, -2,-2, -1,-3, -1,3, -2,2, 1,-3, 2,-2};

    for(i=0;i<12;i+=2)
    {
        if(x==pos1[i] && y==pos1[i+1])
            return 1;
    }
    for(i=0;i<24;i+=2)
    {
        if(x==pos2[i] && y==pos2[i+1])
        return 2;
    }
    return 0;
}

void plateauVolerPions(Plateau* p, Case* c, int joueur)
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

        if(dist==1 && caseGetLibre(ctmp)==0)
            plateauChangeJoueur(p, ctmp,joueur);
    }
}

int plateauNbPionsAVoler(Plateau* p, Case* c, int joueur)
{
    Case* ctmp;
    int xtmp, ytmp;

    int x,y;
    x = caseGetX(c);
    y = caseGetY(c);

    int dist;

    int i;

    int retour;
    retour = 0;

    for(i=0;i<plateauGetCapacite(p);i++)
    {
        ctmp = plateauGetCaseI(p,i);
        xtmp = caseGetX(ctmp);
        ytmp = caseGetY(ctmp);
        dist = plateauTestCaseProche(xtmp-x,ytmp-y);

        if(dist==1 && caseGetLibre(ctmp)==0 && caseGetJoueur(ctmp)!=joueur)
            retour++;
    }

    return retour;
}

int plateauGetScore(const Plateau* p, int j)
{
    if(j==1)
        return p->score_j1;
    else if(j==2)
        return p->score_j2;
    else
        return 0;
}

int plateauPeutJouer(const Plateau* p, int j)
{
    int i;
    Case* ctemp;

    #if COMMENTAIRES==1
        printf("On regarde si le joueur %d peut jouer.\n",(int) j);
    #endif

    /* on parcourt toutes les cases du plateau qui appartiennent au joueur */
    for(i=0;i<p->capacite;i++)
    {
        ctemp = p->support[i];
        if(caseGetJoueur(ctemp)==j)
        {
            /* si au moins une a une possibilité de déplacement */
            if(plateauNbPossibilites(p,ctemp)>=1)
            {
                #if COMMENTAIRES==1
                    printf("\tIl peut jouer à la case %d.\n",(int) ctemp);
                #endif
                return 1;
            }
        }
    }

    #if COMMENTAIRES==1
        printf("\tAucune case trouvée...\n");
    #endif

    return 0;
}

void plateauRemplirPions(Plateau* p, int j)
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
        /*printf("Lecture du plateau : case %u\n\t", i);*/
        caseTestament(p->support[i]);
        p->support[i] = 0;
    }

    /*printf("Libérer le tableau de cases à l'adresse %u \n", (int) p->support);*/
    if(p->support!=0)
        free(p->support);
    p->support = 0;
    p->capacite = 0;
    p->places_libres = 0;

    p->score_j1 = 0;
    p->score_j2 = 0;
}
