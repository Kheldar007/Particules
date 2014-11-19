/**
 * @file    arrayTemplate.h
 * @author  Isabelle Muller
 */


# ifndef ARRAY_H
# define ARRAY_H


/**
 * @class Array : template du nombre et du type d'elements.
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
         * @brief Constructeur.
         */
        Array () ;
        /**
         * @brief Constructeur.
         * @param a Un Array.
         */
        Array (const Array <N , T> & a) ;
        /**
          * @brief Destructeur.
          */
        ~Array () ;
        /**
         * @brief  getSize Retourner la taille de l'Array.
         * @return m_size
         */
        int getSize () const ;
        /**
         * @brief  getData Retourner l'Array.
         * @return m_data
         */
        T * getData () const ;
        /**
         * @brief resize Modifier la taille.
         * @param size Nouvelle taille.
         */
        void resize (int size) ;
        /**
         * @brief  operator= Affectation.
         * @param  a Nouvel objet a affecter.
         * @return Copie de a.
         */
        Array <N , T> & operator= (const Array <N , T> & a) ;
} ;


# include "arrayTemplate.hpp"


# endif
