/**
 * @file    vectorTemplate.h
 * @author  Isabelle Muller
 */


# ifndef VECTOR_H
# define VECTOR_H


# include "arrayTemplate.h"


/**
 * @class Vector Etend Array avec de nouvelles operations arithmetiques.
 * Comment faire pour pouvoir écrire V = 0.5f * V ?
 */
template <int N , typename T> class Vector : public Array <N , T>
{
    public :
        /**
         * @brief Vector Constructeur.
         */
        Vector () ;
        /**
         * @brief Vector Constructeur.
         * @param v Un Vector.
         */
        Vector (const Vector <N , T> & v) ;
        /**
          * ~Vector Destructeur.
          */
        ~Vector () ;

        /*********************** Operations entre les vecteurs. ***********************/

        /**
         * @brief  operator + Addition.
         * @param  v Un autre Vector.
         * @return La somme.
         */
        Vector <N , T> operator + (const Vector <N , T> & v) ;
        /**
         * @brief  operator - Soustraction.
         * @param  v Un autre Vector.
         * @return La difference.
         */
        Vector <N , T> operator - (const Vector <N , T> & v) ;
        /**
         * @brief  operator += Addition.
         * @param  v Un autre Vector.
         * @return La somme.
         */
        Vector <N , T> & operator += (const Vector <N , T> & v) ;
        /**
         * @brief  operator -= Soustraction.
         * @param  v Un autre Vector.
         * @return La difference.
         */
        Vector <N , T> & operator -= (const Vector <N , T> & v) ;

        /************************ Operations avec un scalaire. ************************/

        /**
         * @brief  operator * Multiplication.
         * @param  scalar Un scalaire.
         * @return Le resultat.
         */
        Vector <N , T> operator * (const T scalar) ;
        /**
         * @brief  operator / Division.
         * @param  scalar Un scalaire.
         * @return Le resultat.
         */
        Vector <N , T> operator / (const T scalar) ;
        /**
         * @brief  operator *= Multiplication.
         * @param  scalar Un scalaire.
         * @return Le resultat.
         */
        Vector <N , T> & operator *= (const T scalar) ;
        /**
         * @brief  operator /= Division.
         * @param  scalar Un scalaire.
         * @return Le resultat.
         */
        Vector <N , T> & operator /= (const T scalar) ;
} ;

/********************** Operateurs binaires non-membres. **********************/

template <int N , typename T> Vector <N , T>
    operator + (const T & t  , const Vector <N , T> & v) ;
template <int N , typename T> Vector <N , T>
    operator - (const T & t  , const Vector <N , T> & v) ;
template <int N , typename T> Vector <N , T>
    operator * (const T & t  , const Vector <N , T> & v) ;
template <int N , typename T> Vector <N , T>
    operator / (const T & t  , const Vector <N , T> & v) ;


# include "vectorTemplate.hpp"


# endif
