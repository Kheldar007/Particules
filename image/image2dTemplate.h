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
        /**
         * @brief  I2D_getPixel Accesseur.
         * @param  i L'abscisse.
         * @param  j L'ordonnee.
         * @return Le pixel de coordonnees (i,j).
         */
        T I2D_getPixel (int i , int j) ;

        /******************************************************************************/

        /**
         * @brief I2D_setPixel Modifier un pixel d'une image.
         * @param i     L'abscisse.
         * @param j     L'ordonnee.
         * @param color La nouvelle valeur du pixel.
         */
        void I2D_setPixel (int i , int j , T color) ;
} ;


# include "image2dTemplate.hpp"


# endif
