/**
 * @file    vectorTemplate.h
 * @author  Isabelle Muller
 */


# ifndef VECTOR_H
# define VECTOR_H


# include "arrayTemplate.h"


/**
 * @class Vector Etend Array avec de nouvelles operations arithmetiques.
 * opérateurs entre vecteurs: + - += -=
 * opérateurs avec un scalaire * / *= /=
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

        /**
         * @brief  operator + Addition.
         * @param  v Un autre Vector.
         * @return La somme.
         */
        Vector <N , T> operator + (const Vector <N , T> & v) ;
        Vector <N , T> operator - (const Vector <N , T> & v) ;
} ;


# include "vectorTemplate.hpp"


# endif
