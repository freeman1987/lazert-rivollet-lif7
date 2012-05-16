#include "ordinateur.h"

void ordinateurJouer(Plateau* p, int joueur, int niv)
{
    #if COMMENTAIRES==0
        int afficher_txt = 0; /* ne pas afficher les commantaires */
    #else
        int afficher_txt = 1; /* afficher les commantaires */
        printf("--ENTREE DANS LA FONCTION ordinateurJouer--\n");
    #endif

    int niveau;

    if(niv>=9) /* 9 étant le niveau max, on fixe une limite inatteignable */
        niveau = 1000;
    else /* pas de problème pour un niveau <1 : seule la première case jouable sera jouée */
        niveau = niv;

    int i,j;
    Case* ctmp;
    Case* ctmp2;
    int dist;
    int compteur = 0; /* compter le nombre de meilleurs solutions trouvées */

    int nbAVoler, nbAVolerTmp, pionAdversePerdu, pionAdversePerduTmp;
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

        if(plateauNbPionsAVoler(p,ctmp,((joueur+1)%2))>=4 && caseGetLibre(ctmp)==1)
        {
            ctmp2=ctmp;
            action=1;
            for(j=0;j<plateauGetCapacite(p);j++)
            {
                ctmp=plateauGetCaseI(p,j);
                if(plateauTestCaseProche(caseGetX(destination)-caseGetX(ctmp),caseGetY(destination)-caseGetY(ctmp))==1 && caseGetJoueur(ctmp)==joueur);
                {
                    destination=ctmp2;
                    source=ctmp;
                    i=10000000;
                }
            }
        }else{
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
                    if((action==0 || source==0 || destination==0) && dist==1)
                    {
                        source = ctmp; destination = ctmp2; action = dist;
                        if(afficher_txt==1) printf("\tPar défaut\n");
                        compteur++;
                    }

                    /* on peut se dupliquer ctmp dans ctmp2 */
                    if(dist==1)
                    {
                        nbAVolerTmp = plateauNbPionsAVoler(p,ctmp2,joueur) + 1; /* +1 car on duplique */
                        pionAdversePerduTmp = nbAVolerTmp - 1;
                        if(afficher_txt==1) printf("\t\ton peut s'y dupliquer et voler %d pion(s)\n",nbAVolerTmp);

                        /* il y a plus de pions à prendre en jouant ici */
                        if(nbAVolerTmp>nbAVoler && niveau>compteur)
                        {
                            source = ctmp;
                            destination = ctmp2;
                            action = 1; /* dupliquer */
                            nbAVoler = nbAVolerTmp;
                            pionAdversePerdu = pionAdversePerduTmp;
                            if(afficher_txt==1) printf("\t\t\tC'est mieux ici !\n");
                            compteur++;
                        }

                    }
                    /* on peut se deplacer ctmp vers ctmp2 */
                    else if(dist==2)
                    {
                        nbAVolerTmp = plateauNbPionsAVoler(p,ctmp2,joueur);
                        pionAdversePerduTmp = nbAVolerTmp;
                        if(afficher_txt==1) printf("\t\ton peut s'y deplacer et voler %d pion(s)\n",nbAVolerTmp);

                        /* il y a plus de pions à prendre en jouant ici && plateauNbPionsPerdu(p,ctmp,joueur)<=7 */
                        if(((nbAVolerTmp>nbAVoler && niveau>compteur && (plateauNbPionsPerdu(p,ctmp,joueur)+plateauNbPionsAVolerAdjacent(p,ctmp,joueur))<=4)||
                           ((plateauNbPionEnnemi(p,ctmp2,joueur)-nbAVolerTmp)==0 && pionAdversePerduTmp>pionAdversePerdu && niveau>compteur && (plateauNbPionsPerdu(p,ctmp,joueur)+plateauNbPionsAVolerAdjacent(p,ctmp,joueur))<=4))||destination==0)
                        {
                            source = ctmp;
                            destination = ctmp2;
                            action = 2; /* dupliquer */
                            nbAVoler = nbAVolerTmp;
                            pionAdversePerdu = pionAdversePerduTmp;
                            if(afficher_txt==1) printf("\t\t\tC'est mieux ici !\n");
                            compteur++;
                        }
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
