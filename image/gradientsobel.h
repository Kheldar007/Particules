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
Ã  partir d'une image Ã  niveau de gris calcul une image
de Vec2f
 */
class GradientSobel : public Image2D <Vec2f>
{
    public :

        GradientSobel (Image2Grey & image) ;
} ;


# endif
