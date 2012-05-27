#include "Case.h"

Case* caseInit()
{
    Case* c;
    c = 0;
    c = (Case *) malloc(sizeof(Case));
    if(c==0)
    {
        printf("[!] Erreur d'allocation pour une case.");
        exit(1);
    }
    else
    {
        #if COMMENTAIRES==1
            printf("| MALLOC : %d o\t%d\t(case)\n",sizeof(Case),(int)c);
        #endif
    }
    c->libre = 1;
    c->joueur = 0;

    return c;
}

void caseSetLibre(Case* c, int val)
{
    c->libre = val;
    c->joueur = 0;
}

void caseSetPos(Case* c, int x, int y)
{
    if(x<0 || y<0)
    {
        printf("[!] Erreur pour fixer les coordonnes de la case :\n\tles valeurs ne sont pas positives.\n");
        exit(1);
    }

    c->posX = x;
    c->posY = y;
}


int caseGetLibre(const Case* c)
{
    return c->libre;
}

int caseGetJoueur(const Case* c)
{
    return c->joueur;
}

void caseSetJoueur(Case* c, int j)
{
    c->joueur = j;
    if(j==0)
        c->libre = 1;
    else
        c->libre = 0;
}

int caseGetX(const Case* c)
{
    return c->posX;
}

int caseGetY(const Case* c)
{
    return c->posY;
}

int caseTestCoordonnees(Case* c,int sx,int sy)
{
    if((c->posX==sx)&&(c->posY==sy))
        return 1;
    else
        return 0;
}

void caseTestament(Case* c)
{
    /* libérer la mémoire */
    if(c!=0)
    {
        free(c);
        #if COMMENTAIRES==1
            printf("| FREE   : %d o\t%d\t(case)\n",sizeof(Case),(int)c);
        #endif
        c = 0;
    }

}

void caseAfficheTout(const Case* c)
{
    printf("| [+] Contenu de la case :\n");
    printf("| | -> libre  = %d\n",c->libre);
    printf("| | -> joueur = %d\n",c->joueur);
    printf("| | -> pos x  = %d\n",c->posX);
    printf("| | -> pos y  = %d\n",c->posY);
}

void caseTestRegression(void)
{
    Case *pc2;
    printf("| TEST DU MODULE CASE\n");
    pc2 = 0;
    pc2 = caseInit();
    if(pc2==0)
    {
        printf("| [!] Erreur d'initialisation !\n");
    }
    else
    {
        printf("| [+] Inisialisation : OK (adresse %u)\n",(int) pc2);
        caseAfficheTout(pc2);

        caseSetJoueur(pc2,1);
        if(caseGetJoueur(pc2)!=1 || caseGetLibre(pc2)!=0)
        {
            printf("| [!] Erreur d'affectation !\n");
        }
        else
        {
            printf("| [+] Affectation du joueur !\n");
            caseAfficheTout(pc2);

            caseSetPos(pc2,15,20);
            if(caseGetX(pc2)!=15 || caseGetY(pc2)!=20 || caseTestCoordonnees(pc2,15,20)==0)
            {
                printf("| [!] Erreur de positionnement de la case !\n");
            }
            else
            {
                printf("| [+] Positionnement de la case à 15,20 !\n");
                caseAfficheTout(pc2);

                caseSetLibre(pc2,0);
                if(caseGetLibre(pc2)!=0 || caseGetJoueur(pc2)!=0)
                {
                    printf("| [!] Erreur de libération de la case !\n");
                }
                else
                {
                    printf("| [+] Case libre !\n");
                    caseAfficheTout(pc2);

                    caseTestament(pc2);
                    /*pc2 = 0;*/
                    printf("| [+] Case supprimée !\n");
                }
            }
        }
    }
}
