#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"

/**
    @mainpage Jeu Hexxagon
    @section Informations

    @author Mickaël Rivollet (mickael.rivollet@atu.univ-lyon1.fr - P1005202)
    @author Thibault Lazert (thibault.lazert@etu.univ-lyon1.fr - P1003011)

    @date Printemps 2012

    @section Cadre

    Application réalisée dans le cadre de l'UE LIF7.<br />
    Université Lyon 1<br />

    @section Jouer

    Pour jouer, depuis la racine du jeu :<br />
    <span style="font-family: monospace, consolas; color: blue;">$    sh jouer</span><br />
    <br />
    <em>Remarque :<br />
    &nbsp;&nbsp;Si le programme n'est pas compilé, il le sera automatiquement.<br />
    &nbsp;&nbsp;La compilation nécéssite que la librairie SDL soit installée sur la machine.</em>
*/

/**
    @brief <b>Fonction du jeu.</b><br />
    Appel de cette fonction pour lancer le jeu.<br />
    Pour les tests de régression : appel avec le paramètre -r

    @param argc : nombre de paramètres
    @param argv : valeur des paramètres

    @return int
*/
int main(int argc, char *argv[]);

/**
    @brief <b>Fonction d'appel des tests de regression.</b><br />
    Fonction qui teste les fonctions des modules.

    @return 0
*/
int regression(void);
