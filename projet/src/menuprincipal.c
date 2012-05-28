#include "menuprincipal.h"

int menuPrincipal(int* contreordinateur, int* niveauordinateur, int* plateau)
{
    /* ecran de jeu */
    Image* screen;
    /* images du menu */
    Image *menu, *imageContreJoueur, *imageContreOrdi, *imageSelection, *imageBoutonJouer, *imageBoutonJouerSurvol, *imageBoutonPlus, *imageBoutonMoins;
    Image *imagePlateau[3], *imagePlateauSelectionne;
    /* images animees */
    Image *imageAnimeeRubis, *imageAnimeePerle;

    /* positions des images */
    Rectangle positionPlateau[3];
    Rectangle positionMenu, positionContreJoueur, positionContreOrdi, positionBoutonJouer, positionNiveau, positionTexteNiveau, positionBoutonPlus, positionBoutonMoins;
    Image *chiffres[10], *texte_niveau; int ich;
    Rectangle positionRubis, positionPerle, vecteurPerle, vecteurRubis;

    /* evenements */
    Evenements event;

    /* variables pour contenir les coordonnées de la souris */
    int sourisx;
    int sourisy;

    int retour;

    /* boucle principale du programme */
    int done;

    #if SONS==1
        FMOD_SYSTEM *system;

        FMOD_SOUND *hello = NULL;
        FMOD_SOUND *menuMus = NULL;
        FMOD_System_Create(&system);
        FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);

        FMOD_System_CreateSound(system, SON_HELLO, FMOD_CREATESAMPLE, 0, &hello); afficheVerifChargementSon(hello);
        FMOD_System_CreateSound(system, SON_MENU, FMOD_LOOP_NORMAL, 0, &menuMus); afficheVerifChargementSon(menuMus);

        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, hello, 0, NULL);
        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, menuMus, 0, NULL);
    #endif

    retour = 1; /* par défaut on accède au jeu après le menu */
    done = 0; /* sortie de boucle */

    /* INITIALISATIONS POUR L'AFFICHAGE */

        /* on charge l'écran d'affichage */

        screen = afficheSetEcran();
        if (!screen)
        {
            printf("[!] Erreur de définition de l'écran video.\n");
            afficheErreur();
            return 1;
        }
        /* on initialise l'affichage video */
        if ( afficheInit() < 0 )
        {
            printf("[!] Erreur d'initialisation de l'affichage.\n");
            afficheErreur();
            return 1;
        }
        /* être sûr que l'écran soit fermé à la fin */
        atexit(afficheQuit);

        afficheSetTitre("Hexxagon : Menu du jeu","Hexxagon");

        /* MENU PRINCIPAL */

        menu = afficheChargeImage(MENU); afficheVerifChargement(menu);
        positionMenu.x = 0;
        positionMenu.y = 0;

        imageContreJoueur = afficheChargeImage(VSJOUEUR); afficheVerifChargement(imageContreJoueur);
        positionContreJoueur.x = 100;
        positionContreJoueur.y = screen->h - 120;
        positionContreJoueur.h = imageContreJoueur->h;
        positionContreJoueur.w = imageContreJoueur->w;

        imageContreOrdi = afficheChargeImage(VSORDI); afficheVerifChargement(imageContreOrdi);
        positionContreOrdi.x = 300;
        positionContreOrdi.y = screen->h - 120;
        positionContreOrdi.h = imageContreOrdi->h;
        positionContreOrdi.w = imageContreOrdi->w;

        imagePlateau[0] = afficheChargeImage(PLATEAU1_MENU); afficheVerifChargement(imagePlateau[0]);
        positionPlateau[0].x = 800;
        positionPlateau[0].y = 20;
        positionPlateau[0].h = imagePlateau[0]->h;
        positionPlateau[0].w = imagePlateau[0]->w;

        imagePlateau[1] = afficheChargeImage(PLATEAU2_MENU); afficheVerifChargement(imagePlateau[1]);
        positionPlateau[1].x = 800;
        positionPlateau[1].y = 250;
        positionPlateau[1].h = imagePlateau[1]->h;
        positionPlateau[1].w = imagePlateau[1]->w;

        imagePlateau[2] = afficheChargeImage(PLATEAU3_MENU); afficheVerifChargement(imagePlateau[2]);
        positionPlateau[2].x = 800;
        positionPlateau[2].y = 450;
        positionPlateau[2].h = imagePlateau[2]->h;
        positionPlateau[2].w = imagePlateau[2]->w;

        /* pions qui se déplacent sur l'écran */
        imageAnimeePerle = afficheChargeImage(PION_JOUEUR_2); afficheVerifChargement(imageAnimeePerle);
        imageAnimeeRubis = afficheChargeImage(PION_JOUEUR_1); afficheVerifChargement(imageAnimeeRubis);

        positionPerle.x = 5;
        positionPerle.y = 5;
        positionRubis.x = 600;
        positionRubis.y = 400;
        vecteurPerle.x = 5;
        vecteurPerle.y = 5;
        vecteurRubis.x = -5;
        vecteurRubis.y = 5;

        imagePlateauSelectionne = afficheChargeImage(PLATEAU_SELECTIONNE_MENU); afficheVerifChargement(imagePlateau[0]);

        imageSelection = afficheChargeImage(SELECTIONMODE); afficheVerifChargement(imageSelection);

        imageBoutonJouer = afficheChargeImage(BOUTONJOUER); afficheVerifChargement(imageBoutonJouer);
        imageBoutonJouerSurvol = afficheChargeImage(BOUTONJOUERSURVOL); afficheVerifChargement(imageBoutonJouerSurvol);
        positionBoutonJouer.x = 600;
        positionBoutonJouer.y = screen->h - 120;
        positionBoutonJouer.h = imageBoutonJouer->h;
        positionBoutonJouer.w = imageBoutonJouer->w;

        chiffres[0] = afficheChargeImage(CHIFFRE0); afficheVerifChargement(chiffres[0]);
        chiffres[1] = afficheChargeImage(CHIFFRE1); afficheVerifChargement(chiffres[1]);
        chiffres[2] = afficheChargeImage(CHIFFRE2); afficheVerifChargement(chiffres[2]);
        chiffres[3] = afficheChargeImage(CHIFFRE3); afficheVerifChargement(chiffres[3]);
        chiffres[4] = afficheChargeImage(CHIFFRE4); afficheVerifChargement(chiffres[4]);
        chiffres[5] = afficheChargeImage(CHIFFRE5); afficheVerifChargement(chiffres[5]);
        chiffres[6] = afficheChargeImage(CHIFFRE6); afficheVerifChargement(chiffres[6]);
        chiffres[7] = afficheChargeImage(CHIFFRE7); afficheVerifChargement(chiffres[7]);
        chiffres[8] = afficheChargeImage(CHIFFRE8); afficheVerifChargement(chiffres[8]);
        chiffres[9] = afficheChargeImage(CHIFFRE9); afficheVerifChargement(chiffres[9]);
        positionNiveau.x = 370;
        positionNiveau.y = screen->h - 40;

        texte_niveau = afficheChargeImage(TEXTE_NIVEAU);
        positionTexteNiveau.x = 300;
        positionTexteNiveau.y = screen->h - 40;

        imageBoutonPlus = afficheChargeImage(BOUTONPLUS); afficheVerifChargement(imageBoutonPlus);
        imageBoutonMoins = afficheChargeImage(BOUTONMOINS); afficheVerifChargement(imageBoutonMoins);
        positionBoutonPlus.x = 425;
        positionBoutonPlus.y = screen->h - 40;
        positionBoutonPlus.w = imageBoutonPlus->w;
        positionBoutonPlus.h = imageBoutonPlus->h;
        positionBoutonMoins.x = 400;
        positionBoutonMoins.y = screen->h - 40;
        positionBoutonMoins.w = imageBoutonPlus->w;
        positionBoutonMoins.h = imageBoutonPlus->h;

        sourisx = 0;
        sourisy = 0;

    while (done==0)
    {
        /* vider l'écran */
        afficheVideEcran(screen);

        /* animer les pions qui se déplacent à l'écran */
        if(positionPerle.x>(screen->w-(imageAnimeePerle->w)*3/4) || positionPerle.x<=0)
        {
            vecteurPerle.x*=-1;
        }
        if(positionPerle.y<=0 || positionPerle.y>(screen->h-(imageAnimeePerle->h)*3/4))
        {
            vecteurPerle.y*=-1;
        }
        if(positionRubis.x>(screen->w-(imageAnimeeRubis->w)*3/4) || positionRubis.x<=0)
        {
            vecteurRubis.x*=-1;
        }
        if(positionRubis.y<=0 || positionRubis.y>(screen->h-(imageAnimeeRubis->h)*3/4))
        {
            vecteurRubis.y*=-1;
        }
        positionPerle.x += vecteurPerle.x;
        positionPerle.y += vecteurPerle.y;
        positionRubis.x += vecteurRubis.x;
        positionRubis.y += vecteurRubis.y;

        while(afficheEvenements(&event))
        {
            switch(afficheTypeEvenement(&event))
            {
                /* récupérer la position de la souris sur l'écran */
                case EVENT_SOURISBOUGE:
                {
                    sourisx = afficheCoordonneeSouris(&event,'x');
                    sourisy = afficheCoordonneeSouris(&event,'y');
                }
                break;

                /* fermer */
                case AFFICHE_FIN:
                {
                    done = 1;
                    retour = 0;
                }
                break;

                /* touche enfoncée */
                case EVENT_TOUCHEENFONCEE:
                {
                    /* fermer */
                    if(afficheToucheAppuyee(&event) == T_ECHAP)
                    {
                        done = 1;
                        retour = 0;
                    }

                    if(afficheToucheAppuyee(&event) == T_ESPACE)
                    {
                        done = 1;
                        retour = 1;
                    }

                    if((afficheToucheAppuyee(&event) == T_GAUCHE && *contreordinateur==1) || (afficheToucheAppuyee(&event) == T_DROITE && *contreordinateur==0))
                    {
                        *contreordinateur = ((*contreordinateur + 1) % 2);
                    }

                    if((afficheToucheAppuyee(&event) == T_HAUT || afficheToucheAppuyee(&event) == T_PN_PLUS) && *niveauordinateur<9 && *contreordinateur==1)
                    {
                        (*niveauordinateur)++;
                    }

                    if((afficheToucheAppuyee(&event) == T_BAS || afficheToucheAppuyee(&event) == T_PN_MOINS) && *niveauordinateur>1 && *contreordinateur==1)
                    {
                        (*niveauordinateur)--;
                    }

                    if(afficheToucheAppuyee(&event) == T_PN_ENTREE || afficheToucheAppuyee(&event) == T_ENTREE)
                    {
                        done = 1;
                    }
                }
                break;

                case EVENT_SOURISCLIC:
                {
                    if(sourisDansRectangle(sourisx,sourisy,positionContreJoueur)) /* clic sur contre joueur */
                    {
                        *contreordinateur = 0;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionContreOrdi)) /* clic sur contre ordi */
                    {
                        *contreordinateur = 1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionBoutonJouer)) /* clic sur bouton jouer */
                    {
                        done = 1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[0]))
                    {
                        *plateau=1;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[1]))
                    {
                        *plateau=2;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionPlateau[2]))
                    {
                        *plateau=3;
                    }

                    /* changer de niveau ordi */
                    if(sourisDansRectangle(sourisx,sourisy,positionBoutonPlus) && *niveauordinateur<9 && *contreordinateur==1)
                    {
                        (*niveauordinateur)++;
                    }
                    else if(sourisDansRectangle(sourisx,sourisy,positionBoutonMoins) && *niveauordinateur>1 && *contreordinateur==1)
                    {
                        (*niveauordinateur)--;
                    }
                }
                break;
            }
        }

        afficheImageRect(positionMenu,menu,screen);

        if(*contreordinateur==1)
        {
            afficheImageRect(positionContreOrdi,imageSelection,screen);
            afficheImageRect(positionTexteNiveau,texte_niveau,screen);
            afficheImageRect(positionNiveau,chiffres[*niveauordinateur],screen);
        }
        else
        {
            afficheImageRect(positionContreJoueur,imageSelection,screen);
        }

        afficheImageRect(positionContreJoueur,imageContreJoueur,screen);
        afficheImageRect(positionContreOrdi,imageContreOrdi,screen);

        afficheImageRect(positionPlateau[*plateau-1],imagePlateauSelectionne,screen);
        afficheImageRect(positionPlateau[0],imagePlateau[0],screen);
        afficheImageRect(positionPlateau[1],imagePlateau[1],screen);
        afficheImageRect(positionPlateau[2],imagePlateau[2],screen);

        if(*niveauordinateur<9 && *contreordinateur==1)
            afficheImageRect(positionBoutonPlus,imageBoutonPlus,screen);
        if(*niveauordinateur>1 && *contreordinateur==1)
            afficheImageRect(positionBoutonMoins,imageBoutonMoins,screen);


        if(sourisDansRectangle(sourisx,sourisy,positionBoutonJouer))
            afficheImageRect(positionBoutonJouer,imageBoutonJouerSurvol,screen);
        else
            afficheImageRect(positionBoutonJouer,imageBoutonJouer,screen);

        afficheImageRect(positionPerle,imageAnimeePerle,screen);
        afficheImageRect(positionRubis,imageAnimeeRubis,screen);

        afficheMiseAJour(screen);
    }

    #if SONS==1
        FMOD_Sound_Release(hello);
        FMOD_Sound_Release(menuMus);
        FMOD_System_Close(system);
        FMOD_System_Release(system);
    #endif

    afficheFree(menu);
    afficheFree(imageContreJoueur);
    afficheFree(imageContreOrdi);
    afficheFree(imageSelection);
    afficheFree(imageBoutonJouer);
    afficheFree(imageBoutonJouerSurvol);
    afficheFree(imageBoutonPlus);
    afficheFree(imageBoutonMoins);
    afficheFree(imagePlateau[0]);
    afficheFree(imagePlateau[1]);
    afficheFree(imagePlateau[2]);
    afficheFree(imagePlateauSelectionne);
    afficheFree(imageAnimeeRubis);
    afficheFree(imageAnimeePerle);
    afficheFree(texte_niveau);
    for(ich=0;ich<10;ich++)
        afficheFree(chiffres[ich]);
    afficheFree(screen);

    afficheQuit();

    return retour;
}

int sourisDansRectangle(int x, int y, Rectangle rectangle)
{
    if(x>=rectangle.x && x<=(rectangle.w+rectangle.x) && y>=rectangle.y && y<=(rectangle.h+rectangle.y))
        return 1;
    else
        return 0;
}

void afficheVerifChargementSon(const FMOD_SOUND* son)
{
    if(son==0)
    {
        printf("[!] Erreur de chargement du son.\n");
        exit(1);
    }
}
