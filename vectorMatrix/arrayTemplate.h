/**
 * @file    arrayTemplate.h
 * @author  Isabelle Muller
 */


# ifndef ARRAY_H
# define ARRAY_H


# include <algorithm>
# include <cassert>
# include <cstdio>
# include <iostream>


/**
 * @class Array Template du nombre et du type d'elements.
 */
template <int N , typename T> class Array
{
    protected :
        /**
         * @brief m_data Donnee de type T.
         */
        T * m_data ;
        /**
         * @brief m_size Nombre d'elements.
         */
        int m_size ;
        /**
         * @brief s_nb Nombre d'objets.
         */
        static int s_nb ;

    public :
        /**
         * @brief Array Constructeur.
         */
        Array () ;
        /**
         * @brief Array Constructeur.
         * @param a Un Array.
         */
        Array (const Array <N , T> & a) ;
        /**
          * @brief ~Array Destructeur.
          */
        ~Array () ;

        /**
         * @brief  A_getSize Retourner la taille de l'Array.
         * @return m_size
         */
        int A_getSize () const ;

        /**
         * @brief A_resize Modifier la taille.
         * @param size Nouvelle taille.
         */
        void A_resize (int size) ;

        /******************************** Operateurs. *********************************/

        /**
         * @brief  operator [] Retourner une case de l'Array.
         * @param  i La i-eme case.
         * @return Renvoyer la case d'indice i.
         */
        T & operator [] (int i) ;
        /**
         * @brief  operator [] Retourner une case de l'Array.
         * @param  i La i-eme case.
         * @return Renvoyer la case d'indice i.
         */
        T const & operator [] (int i) const ;
        /**
         * @brief  operator = Affectation.
         * @param  a Nouvel objet a affecter.
         * @return Copie de a.
         */
        Array <N , T> & operator = (const Array <N , T> & a) ;
        /**
         * @brief  operator == Test d'egalite.
         * @param  a Un autre Array.
         * @return Vrai si les objets sont egaux.
         */
        bool operator == (const Array <N , T> & a) const ;

        /******************************************************************************/

        /**
         * @brief A_swap Echanger deux Array.
         * @param a Un objet a echanger.
         * @param b Un objet a echanger.
         */
        static void A_swap (Array <N , T> & a , Array <N , T> & b) ;
        /**
         * @brief A_print Afficher le contenu de l'Array.
         */
        void A_print () ;
} ;


# include "arrayTemplate.hpp"


# endif
