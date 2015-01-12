/**
 * @file    gradientsobel.h
 * @author  Isabelle Muller
 */


# ifndef GRADIENTSOBEL_H
# define GRADIENTSOBEL_H


# include "image2dTemplate.h"
# include "image2grey.h"
# include "../vectorMatrix/vec2f.h"


/**
 * @brief GradientSobel Classe.
 */
class GradientSobel : public Image2D <Vec2f>
{
    public :

        /**
          * @brief GradientSobel Filtre sobel 5x5.
          * @param image Une image de niveau de gris.
          */
        GradientSobel (Image2Grey & image) ;
} ;


# endif
