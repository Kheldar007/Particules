/**
 * @file    vectorTemplate.h
 * @author  Isabelle Muller
 */


# ifndef VECTOR_H
# define VECTOR_H


/**
 * @class Vector : etend Array avec de nouvelles operations arithmetiques.
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
} ;


# include "vectorTemplate.hpp"
