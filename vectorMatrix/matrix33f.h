/**
 * @file    matrix33f.h
 * @author  Isabelle Muller
 */


# ifndef MATRIX33F_H
# define MATRIX33F_H


# include "vec3f.h"


/**
 * @brief Matrix33f Classe des matrices de flottants de dimension 3x3.
• constructeur
• accesseurs
• inverse
• set & apply translation
• set & apply rotation
• set & apply homothétie
• multiplication par un vecteur (coordonnée homogène Vec3f )
• appliquer la transformation à un vecteur (Vec2f)
 */
class Matrix33f
{
    protected :
        /**
         * @brief column1 Premiere colonne de la matrice.
         */
        Vec3f column1 ;
        /**
         * @brief column2 Deuxieme colonne de la matrice.
         */
        Vec3f column2 ;
        /**
         * @brief column3 Troisieme colonne de la matrice.
         */
        Vec3f column3 ;

    public :
        /**
         * @brief Matrix33f Constructeur vide.
         */
        Matrix33f () ;
} ;


# endif
