/**
 * @file    imageTemplate.h
 * @author  Isabelle Muller
 */


# ifndef IMAGETEMPLATE_H
# define IMAGETEMPLATE_H


# include "../vectorMatrix/arrayTemplate.h"


/**
 * @brief Image Template.
 */
template <int D , typename T> class Image
{
    protected :

        /**
         * @brief m_dimension Dimension.
         */
        Array <D , int> m_dimension ;
        /**
         * @brief m_image L'image.
         */
        T * m_image ;

    public :

        /******************************* Constructeurs. *******************************/

        /**
         * @brief Image Constructeur.
         */
        Image () ;
        /**
         * @brief Image Constructeur avec dimension.
         * @param dim Dimension.
         */
        Image (const Array <D , int> dimension) ;

        /******************************** Destructeur. ********************************/

        /**
         * @brief ~Image Destructeur.
         */
        ~Image () ;

        /******************************** Accesseurs. *********************************/

        /**
         * @brief  I_getDimension Accesseur.
         * @return m_dimension
         */
        Array <D , int> I_getDimension () const ;
        /**
         * @brief  I_getImage Accesseur.
         * @return m_image
         */
        T * I_getImage () const ;

        /******************************************************************************/

        /**
         * @brief I_swap Echanger deux images.
         * @param image1 Une image.
         * @param image2 Une autre image.
         */
        static void I_swap (Image <D , T> & image1 , Image <D , T> & image2) ;
} ;


# include "imageTemplate.hpp"


# endif
