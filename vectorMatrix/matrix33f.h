/**
 * @file    matrix33f.h
 * @author  Isabelle Muller
 */


# ifndef MATRIX33F_H
# define MATRIX33F_H


# include <cmath>
# include "vec2f.h"
# include "vec3f.h"


/**
 * @brief Matrix33f Classe des matrices de flottants de dimension 3x3.
 */
class Matrix33f
{
    public :
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

        void M_setColumn1 (Vec3f c) ;
        void M_setColumn2 (Vec3f c) ;
        void M_setColumn3 (Vec3f c) ;

        /**
         * @brief  M_reverse Inverser la matrice.
         * @return Matrice inverse.
         */
        Matrix33f M_reverse () const ;
        /**
         * @brief M_applyTranslate Appliquer un vecteur de translation.
         * @param v Vecteur de translation.
         */
        void M_applyTranslate (const Vec2f v) ;
        /**
         * @brief M_setTranslate Generer une matrice de translation.
         * @param v Vecteur de translation.
         */
        void M_setTranslate (const Vec2f v) ;
        /**
         * @brief M_applyRotate Effectuer une rotation.
         * @param angle Angle de rotation.
         */
        void M_applyRotate (const float angle) ;
        /**
         * @brief M_setRotate Generer une matrice de rotation.
         * @param angle Angle de rotation.
         */
        void M_setRotate (const float angle) ;
        /**
         * @brief M_applyHomothety Effectuer une homothetie.
         * @param v Vecteur d'homothetie.
         */
        void M_applyHomothety (const Vec2f v) ;
        /**
         * @brief M_setHomothety Generer une matrice d'homothetie.
         * @param v Vecteur d'homothetie.
         */
        void M_setHomothety (const Vec2f v) ;

        /******************************** Operateurs. *********************************/

        /**
         * @brief  operator * Multiplication par un vecteur.
         * @param  v Le vecteur.
         * @return Le vecteur resultat.
         */
        Vec3f operator * (const Vec3f & v) const ;
} ;

        Matrix33f operator*(Matrix33f m1, Matrix33f m2);
        Vec3f operator*(Matrix33f m, Vec3f c);


# endif
