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

        /********************************* Mutateurs. *********************************/

        /**
         * @brief I_setDimension Mutateur.
         * @param dimension Nouvelle dimension.
         */
        void I_setDimension (const Array <D , int> dimension) ;
        /**
         * @brief I_setDimension1 Mutateur du premier element du tableau.
         * @param dimension1 Nouvel element.
         */
        void I_setDimension1 (const int dimension1) ;
        /**
         * @brief I_setDimension2 Mutateur du deuxieme element du tableau.
         * @param dimension2 Nouvel element.
         */
        void I_setDimension2 (const int dimension2) ;

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
