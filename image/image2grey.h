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
         */
        void I2G_saveToPGM (const std::string & file) const ;
        /**
         * @brief  I2G_subsampling Diviser l'image par deux.
         * @return Nouvelle image.
         */
        Image2Grey I2G_subsampling () const ;
        /**
          * @brief  I2G_smoothing Moyenne des pixels avec les (2n+1) 2 pixels voisins.
          * @param  n Nombre de pixels a utiliser pour faire la moyenne.
          * @return Image lissee.
          */
        Image2Grey I2G_smoothing (int n) const ;
        /**
          * @brief  I2G_thresholding Seuillage par une valeur (0 en dessous 255 au dessus).
          * @param  threshold Le seuil.
          * @return Image seuillee.
          */
        Image2Grey I2G_thresholding (int threshold) const ;
} ;


# endif
