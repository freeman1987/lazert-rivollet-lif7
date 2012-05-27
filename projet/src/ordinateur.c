#include "ordinateur.h"

void ordinateurJouer(Plateau* p, int joueur, int niv)
{

    int niveau;
    int i,j;
    Case* ctmp;
    Case* ctmp2;
    int dist;
    int compteur;


    int nbAVoler, nbAVolerTmp, pionAdversePerdu, pionAdversePerduTmp;
    Case* source;
    Case* destination;
    int afficher_txt;
    int action; /* 1 dupliquer, 2 deplacer */
    #if COMMENTAIRES==0
        afficher_txt = 0; /* ne pas afficher les commantaires */
    #else
        afficher_txt = 1; /* afficher les commantaires */
        printf("--ENTREE DANS LA FONCTION ordinateurJouer--\n");
    #endif

    if(niv>=9) /* 9 étant le niveau max, on fixe une limite inatteignable */
        niveau = 1000;
    else /* pas de problème pour un niveau <1 : seule la première case jouable sera jouée */
        niveau = niv + 1;

    nbAVoler = 0;
    action = 0;
    source = 0;
    destination = 0;
    compteur = 0; /* compter le nombre de meilleures solutions trouvées */

    for(i=0;i<plateauGetCapacite(p);i++) /* on parcourt tout le plateau */
    {
        ctmp = plateauGetCaseI(p,i);

        if(afficher_txt==1 && 0) printf("Case %d : @ %d \n",i,(int) ctmp);

        /* s'il on peut voler plus de 4 pions */
        if(plateauNbPionsAVoler(p,ctmp,joueur)>=4 && caseGetLibre(ctmp)==1)
        {

            if(afficher_txt==1) printf("Il y a %d pions à voler en jouant ici (i=%d : @ %d).\n",plateauNbPionsAVoler(p,ctmp,joueur),i,(int) ctmp);

            ctmp2 = ctmp; /* on suppose que ce sera la case de destination */
            action = 1; /* on suppose que l'on se dupliquera */
            for(j=0;j<plateauGetCapacite(p);j++) /* on cherche un pion qui pourrait se dupliquer */
            {
                ctmp = plateauGetCaseI(p,j);
                if(plateauTestCaseProche(caseGetX(ctmp2)-caseGetX(ctmp),caseGetY(ctmp2)-caseGetY(ctmp))==1 && caseGetJoueur(ctmp)==joueur)
                {
                    /* on a trouvé un tel pion */
                    destination = ctmp2;
                    source = ctmp;
                    /* on sort de la boucle */
                    i = plateauGetCapacite(p) + 1;
                    j = plateauGetCapacite(p) + 1;
                }
            }
        }
        else
        {
            /* la case appartient au joueur */
            if(caseGetLibre(ctmp)==0 && caseGetJoueur(ctmp)==joueur)
            {
                if(afficher_txt==1) printf("Case %d (%d) appartient au joueur.\n",i,(int) ctmp);
                /* on parcourt les autres cases pour voir ce que l'on peut faire */
                for(j=0;j<plateauGetCapacite(p);j++)
                {
                    ctmp2 = plateauGetCaseI(p,j); /* case temporaire de destination */

                    /* il est possible de jouer ici */
                    if(caseGetLibre(ctmp2)==1)
                    {
                        /* on regarde si la case est atteignable (dist = 1 ou 2) */
                        dist = plateauTestCaseProche(caseGetX(ctmp)-caseGetX(ctmp2),caseGetY(ctmp)-caseGetY(ctmp2));

                        if(afficher_txt==1 && dist!=0) printf("\t- case %d (%d) libre, dst : %d\n",j,(int) ctmp2,dist);

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
                            if(afficher_txt==1) printf("\t\ton peut s'y dupliquer et voler %d pion(s) - adv perd : %d\n",nbAVolerTmp,pionAdversePerduTmp);

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
                            if(afficher_txt==1) printf("\t\ton peut s'y deplacer et voler %d pion(s) - adv perd : %d\n",nbAVolerTmp,pionAdversePerduTmp);

                            /* il y a plus de pions à prendre en jouant ici*/
                            if(((nbAVolerTmp>nbAVoler && niveau>compteur && (plateauNbPionsPerdu(p,ctmp,joueur)+plateauNbPionsAVolerAdjacent(p,ctmp,joueur))<=4)
                                ||
                               ((plateauNbPionEnnemi(p,ctmp2,joueur)-nbAVolerTmp)==0 && pionAdversePerduTmp>pionAdversePerdu && niveau>compteur && (plateauNbPionsPerdu(p,ctmp,joueur)+plateauNbPionsAVolerAdjacent(p,ctmp,joueur))<=4))
                               || destination==0)
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
    } /* fin de la boucle sur i */

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
