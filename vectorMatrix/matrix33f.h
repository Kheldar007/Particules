/**
 * @file    matrix33f.h
 * @author  Isabelle Muller
 */


# ifndef MATRIX33F_H
# define MATRIX33F_H


# include "vec3f.h"


/**
 * @brief Matrix33f Classe des matrices de flottants de dimension 3x3.
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

        /******************************* Constructeurs. *******************************/

        /**
         * @brief Matrix33f Constructeur vide, matrice unitaire.
         */
        Matrix33f () ;
        /**
         * @brief Matrix33f Constructeur.
         * @param l1c1 Case de la matrice.
         * @param l1c2 Case de la matrice.
         * @param l1c3 Case de la matrice.
         * @param l2c1 Case de la matrice.
         * @param l2c2 Case de la matrice.
         * @param l2c3 Case de la matrice.
         * @param l3c1 Case de la matrice.
         * @param l3c2 Case de la matrice.
         * @param l3c3 Case de la matrice.
         */
        Matrix33f (const float & l1c1 , const float & l2c1 , const float & l3c1 ,
                   const float & l1c2 , const float & l2c2 , const float & l3c2 ,
                   const float & l1c3 , const float & l2c3 , const float & l3c3) ;

        /******************************** Accesseurs. *********************************/

        /**
         * @brief  M_getColumn1 Accesseur.
         * @return Premiere colonne.
         */
        Vec3f M_getColumn1 () ;
        /**
         * @brief  M_getColumn2 Accesseur.
         * @return Deuxieme colonne.
         */
        Vec3f M_getColumn2 () ;
        /**
         * @brief  M_getColumn2 Accesseur.
         * @return Troisieme colonne.
         */
        Vec3f M_getColumn3 () ;

        /******************************************************************************/

        /**
         * @brief  M_reverse Inverser la matrice.
         * @return Matrice inverse.
         */
        Matrix33f M_reverse () const ;
} ;


# endif
