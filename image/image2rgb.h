/**
 * @file    image2rgb.h
 * @author  Isabelle Muller
 */


# ifndef IMAGE2RGB_H
# define IMAGE2RGB_H

# include <fstream>
# include <string>
# include "image2dTemplate.h"
# include "../vectorMatrix/vec3f.h"


/**
 * @brief Pixel Stocker les valeurs RGB d'un pixel.
 */
class Pixel
{
    public :

        unsigned char r ;
        unsigned char g ;
        unsigned char b ;
} ;


typedef Image2D <Pixel> IMAGE2RGB ; // Simplifier l'ecriture.


/**
 * @brief Image2RGB Classe.
fonctions de chargement et sauvegarde du format PPM (ascii)
 */
class Image2RGB : public IMAGE2RGB
{
    public :

        /**
         * @brief Image2RGB Constructeur vide.
         */
        Image2RGB () ;

        /**
          * @brief I2RGB_loadFromPGM Ouvrir une image pgm.
          * @param f Nom du fichier.
          */
        void I2RGB_loadFromPGM (const std::string & file) const ;
        /**
          * @brief I2RGB_saveToPGM Enregistrer une image pgm.
          * @param f Nom du fichier.
          */
        void I2RGB_saveToPGM (const std::string & file) ;
} ;


# endif
