#include "ordinateur.h"

void ordinateurJouer(Plateau* p, int joueur, int niveau)
{
    int afficher_txt = 1;

    int i,j;
    Case* ctmp;
    Case* ctmp2;
    int dist;
    int compteur = 0; /* compter le nombre de meilleurs solutions trouvées */

    int nbAVoler, nbAVolerTmp;
    Case* source;
    Case* destination;
    int action; /* 1 dupliquer, 2 deplacer */
    nbAVoler = 0;
    action = 0;
    source = 0;
    destination = 0;

    for(i=0;i<plateauGetCapacite(p);i++)
    {
        ctmp = plateauGetCaseI(p,i);

        if(afficher_txt==1) printf("Case %d (%d)\n",i,(int) ctmp);

        /* la case appartient au joueur */
        if(caseGetLibre(ctmp)==0 && caseGetJoueur(ctmp)==joueur)
        {
            if(afficher_txt==1) printf("\tCase qui appartient au joueur.\n");
            for(j=0;j<plateauGetCapacite(p);j++)
            {
                ctmp2 = plateauGetCaseI(p,j);
                if(afficher_txt==1) printf("\t- case %d (%d)\n",j,(int) ctmp2);

                /* on peut jouer ici */
                if(caseGetLibre(ctmp2)==1)
                {
                    dist = plateauTestCaseProche(caseGetX(ctmp)-caseGetX(ctmp2),caseGetY(ctmp)-caseGetY(ctmp2));

                    /* par défaut, on suppose que le premier pion jouable est la meilleure solution */
                    if((action==0 || source==0 || destination==0) && (dist==1 || dist==2))
                    {
                        source = ctmp; destination = ctmp2; action = dist;
                        if(afficher_txt==1) printf("\tPar défaut\n");
                        compteur++;
                    }

                    /* on peut se dupliquer ctmp dans ctmp2 */
                    if(dist==1)
                    {
                        nbAVolerTmp = plateauNbPionsAVoler(p,ctmp2,joueur) + 1; /* +1 car on duplique */
                        if(afficher_txt==1) printf("\t\ton peut s'y dupliquer et voler %d pion(s)\n",nbAVolerTmp);

                        /* il y a plus de pions à prendre en jouant ici */
                        if(nbAVolerTmp>nbAVoler && niveau>compteur)
                        {
                            source = ctmp;
                            destination = ctmp2;
                            action = 1; /* dupliquer */
                            nbAVoler = nbAVolerTmp;
                            if(afficher_txt==1) printf("\t\t\tC'est mieux ici !\n");
                            compteur++;
                        }

                    }
                    /* on peut se deplacer ctmp vers ctmp2 */
                    else if(dist==2)
                    {
                        nbAVolerTmp = plateauNbPionsAVoler(p,ctmp2,joueur);
                        if(afficher_txt==1) printf("\t\ton peut s'y deplacer et voler %d pion(s)\n",nbAVolerTmp);

                        /* il y a plus de pions à prendre en jouant ici */
                        if(nbAVolerTmp>nbAVoler && niveau>compteur)
                        {
                            source = ctmp;
                            destination = ctmp2;
                            action = 2; /* dupliquer */
                            nbAVoler = nbAVolerTmp;
                            if(afficher_txt==1) printf("\t\t\tC'est mieux ici !\n");
                            compteur++;
                        }
                    }
                }
            }

        }

    }

    if(afficher_txt==1)
    {
        printf("Bilan : ");
        if(action==1)
            printf("dupliquer %d sur %d. Gain : %d\n", (int) source, (int) destination, nbAVoler);
        else if(action==2)
            printf("déplacer %d vers %d. Gain : %d\n", (int) source, (int) destination, nbAVoler);
        else
            printf("Rien !\n");
    }

    if(action==1) /* on duplique */
    {
        plateauDecrementePlacesLibres(p);
        plateauChangeJoueur(p,destination,joueur);
        plateauVolerPions(p,destination,joueur);
    }
   else if(action==2) /* on deplacer */
    {
        plateauChangeJoueur(p, source,0);
        plateauChangeJoueur(p,destination,joueur);
        plateauVolerPions(p,destination,joueur);
    }
}
