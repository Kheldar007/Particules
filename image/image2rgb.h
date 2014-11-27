/**
 * @file    image2rgb.h
 * @author  Isabelle Muller
 */


# ifndef IMAGE2RGB_H
# define IMAGE2RGB_H


# include "image2dTemplate.h"
# include "../vectorMatrix/vec3f.h"


/**
 * @brief Pixel Stocker les valeurs RGB d'un pixel.
 */
class Pixel
{
    public :

        float r ;
        float g ;
        float b ;
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
} ;


# endif
