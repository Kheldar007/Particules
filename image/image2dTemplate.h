/**
 * @file    image2dTemplate.h
 * @author  Isabelle Muller
 */


# ifndef IMAGE2DTEMPLATE_H
# define IMAGE2DTEMPLATE_H


# include "imageTemplate.h"


/**
 * @brief Image2D Template.
 */
template <typename T> class Image2D : public Image <2 , T>
{
    public :

        /******************************* Constructeurs. *******************************/

        /**
         * @brief Image2D Constructeur.
         */
        Image2D () ;
        /**
         * @brief Image2D Constructeur.
         * @param x Largeur de l'image.
         * @param y Hauteur de l'image.
         */
        Image2D (const int x , const int y) ;

        /******************************** Accesseurs. *********************************/

        /**
         * @brief  I2D_getDimension Accesseur.
         * @return m_dimension
         */
        Array <2 , int> I2D_getDimension () const ;
        /**
         * @brief  I2D_getImage Accesseur.
         * @return m_image
         */
        T * I2D_getImage () const ;
} ;


# include "image2dTemplate.hpp"


# endif
