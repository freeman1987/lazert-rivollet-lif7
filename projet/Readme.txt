                       *********************************************
                       *                                           *
                       *   Projet LIF 7 - semestre printemps 2012  *
                       *   Thibault LAZERT et Mickael RIVOLLET     *
                       *                                           *
******************************************************************************************

ooooo   ooooo                                                                              
`888'   `888'                                                                              
 888     888   .ooooo.  oooo    ooo oooo    ooo  .oooo.    .oooooooo  .ooooo.  ooo. .oo.   
 888ooooo888  d88' `88b  `88b..8P'   `88b..8P'  `P  )88b  888' `88b  d88' `88b `888P"Y88b  
 888     888  888ooo888    Y888'       Y888'     .oP"888  888   888  888   888  888   888  
 888     888  888    .o  .o8"'88b    .o8"'88b   d8(  888  `88bod8P'  888   888  888   888  
o888o   o888o `Y8bod8P' o88'   888o o88'   888o `Y888""8o `8oooooo.  `Y8bod8P' o888o o888o 
                                                          d"     YD                        
                                                          "Y88888P'                        
                                                                                           
******************************************************************************************


-- Pour compiler le programme :
$    make
  
-- Pour jouer
$	sh jouer
(la commande precedente compile le jeu s'il ne l'est pas)

Il faut jouer a l'aide de la souris.
Pour commencer, choisir dans le menu principal un plateau et un mode de jeu.
Cliquer sur le bouton jouer.
Le joueur qui a la main doit selectionner un de ses pions en cliquant dessus.
Les differentes possibilites qui s'offrent à lui s'affichent alors :
soit dupliquer son pion dans une case adjacente, soit le deplacer vers une case de distance 1.
Les pions advserses qui se trouvent autour du pion duplique/deplace lui reviennent.
Pour qu'un joueur gagne la partie, il faut qu'il ait plus de pions que l'autre sur le plateau.
La partie s'arrete lorsqu'un joueur est bloque. Les cases vides sont automatiquement 
remplies avec le pion du joueur qui n'est plas bloque.

Remarque :
Pendant le jeu, il est possible d'enregistrer la partie et de la reprendre ensuite depuis le menu.

-- Pour nettoyer les fichiers de compilation
$	make clean

-- Pour afficher la documentation de Doxygen
$   sh documentation [actualiser]
(ajouter le parametre "actualiser" pour regenerer toute la documentation)
