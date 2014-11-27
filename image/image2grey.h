/**
 * @file    image2grey.h
 * @author  Isabelle Muller
 */


# ifndef IMAGE2GREY_H
# define IMAGE2GREY_H


# include <fstream>
# include <string>
# include "image2dTemplate.h"


typedef Image2D <unsigned char> IMAGE2GREY ; // Simplifier l'ecriture.


/**
 * @brief Image2Grey Classe.
sous-échantillonnage (diviser la taille de l'image par 2, renvoie une nouvelle image)
llissage (moyenne des pixels avec les (2n+1) 2 pixels voisins, renvoie une nouvelle image)
seuillage par une valeur (0 en dessous 255 au dessus)

Qu'impliquerait d'écrire le seuillage dans Image2D<T> ?
Comment contourner le problème ?
 */
class Image2Grey : public IMAGE2GREY
{
    public :

        /******************************* Constructeurs. *******************************/

        /**
         * @brief Image2Grey Constructeur vide.
         */
        Image2Grey () ;
        /**
         * @brief Image2Grey Constructeur.
         * @param x Largeur de l'image.
         * @param y Hauteur de l'image.
         */
        Image2Grey (const int x , const int y) ;

        /******************************************************************************/

        /**
         * @brief loadFromPGM Charger un fichier PGM.
         * @param file Le nom du fichier.
         */
        void I2G_loadFromPGM (const std::string & file) ;
        /**
         * @brief saveToPGM Sauver l'image au format PGM.
         * @param file Le nom du fichier.
         */
        void I2G_saveToPGM (const std::string & file) const ;
        /**
         * @brief  I2G_subsampling Diviser l'image par deux.
         * @return Nouvelle image.
         */
        Image2Grey I2G_subsampling () const ;
} ;


# endif
