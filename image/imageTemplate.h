/**
 * @file    imageTemplate.h
 * @author  Isabelle Muller
 */


# ifndef IMAGETEMPLATE_H
# define IMAGETEMPLATE_H


# include "../vectorMatrix/arrayTemplate.h"


/**
 * @brief Image Template.
• les constructeurs (allocation dynamique de la mémoire de l'image)
• destructeur
• affectation
• échange entre deux images
• accès aux pixels
• accès au pointeurs sur la mémoire de l'image

on utilisera Array pour passer les tailles et les coordonnées
 */
template <int D , typename T> class Image
{
    public :
        Image () ;
} ;


# include "imageTemplate.hpp"


# endif
