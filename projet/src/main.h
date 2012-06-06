#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"

/**
    @mainpage Jeu Hexxagon - LIF7

    <img src="http://code.google.com/p/lazert-rivollet-lif7/logo?cct=1334641814" alt="" border="0" style="float: right;" />

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
    <br />
    Il faut jouer a l'aide de la souris.<br />
    Pour commencer, choisir dans le menu principal un plateau et un mode de jeu.<br />
    Cliquer sur le bouton jouer.<br />
    Le joueur qui a la main doit selectionner un de ses pions en cliquant dessus.<br />
    Les differentes possibilites qui s'offrent à lui s'affichent alors :<br />
    soit dupliquer son pion dans une case adjacente, soit le deplacer vers une case de distance 1.<br />
    Les pions advserses qui se trouvent autour du pion duplique/deplace lui reviennent.<br />
    Pour qu'un joueur gagne la partie, il faut qu'il ait plus de pions que l'autre sur le plateau.<br />
    La partie s'arrete lorsqu'un joueur est bloque. Les cases vides sont automatiquement <br />
    remplies avec le pion du joueur qui n'est plas bloque.<br />
    <br />
    Remarque :<br />
    Pendant le jeu, il est possible d'enregistrer la partie et de la reprendre ensuite depuis le menu.<br />

    <em>Remarque :<br />
    &nbsp;&nbsp;Si le programme n'est pas compilé, il le sera automatiquement.<br />
    &nbsp;&nbsp;La compilation nécéssite que la librairie SDL soit installée sur la machine.</em>

    @section Organisation

    <b>Fichiers</b><br />

    Les fichiers source se trouvent dans le répertoire src/<br />
    Les images, plateaux et sons dans le répertoire data/<br />
    Les librairies dans lib/ et bin/lib/ (pour la compilation et le jeu)

   <br /><br /><b>Nommage des sources</b><br />

    Les fichiers des modules avec structure ont le même nom que la structure (avec majuscule)<br />
    Les autres commencent par une lettre minuscule.<br />
    Les fichiers *.h contient la liste des déclarations des fonctions publiques avec leur documentation.<br />
    Les fonctions sont implémentées dans les fichiers *.c.

    <br /><br /><b>Nommage des fonctions de modules</b><br />

    Les fonctions du modules commencent toutes par le nom du module avec une lettre miniscule au début.<br />

    <br /><br /><b>Nommage des fonctions et des variables</b><br />

    Les variables commencent généralement par une minuscule et chaque nouveau mot commence par une majuscule.

    <br /><br /><b>Variables de pré-processeur</b><br />

    Elles sont écrites en lettres majuscules et les mots sont séparées par _<br />
    Les variables d'inclusion des fichiers commencent par le symbole _
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
