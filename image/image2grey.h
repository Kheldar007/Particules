/**
 * @file    image2grey.h
 * @author  Isabelle Muller
 */


# ifndef IMAGE2GREY_H
# define IMAGE2GREY_H


# include "image2dTemplate.h"


/**
 * @brief Image2Grey Classe.
image 2D de unsigned char
fonctions de chargement et sauvegarde du format PGM (ascii)
sous-échantillonnage (diviser la taille de l'image par 2, renvoie une nouvelle image)
llissage (moyenne des pixels avec les (2n+1) 2 pixels voisins, renvoie une nouvelle image)
seuillage par une valeur (0 en dessous 255 au dessus)

Qu'impliquerait d'écrire le seuillage dans Image2D<T> ?
Comment contourner le problème ?
 */
class Image2Grey
{
    public :
        Image2Grey () ;
} ;


# endif
