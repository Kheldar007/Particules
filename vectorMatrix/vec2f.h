/**
 * @file    vec2f.h
 * @author  Isabelle Muller
 */


# ifndef VEC2F_H
# define VEC2F_H


# include "vectorTemplate.h"


typedef Vector <2 , float> VEC2F ; // Simplifier l'ecriture.


/**
 * @class Vec2f Vecteurs de deux flottants.
 */
class Vec2f : public VEC2F
{
    public :
        /**
         * @brief Vec2f Constructeur vide.
         */
        Vec2f () ;
        /**
         * @brief Vec2f Constructeur.
         * @param v1 Premier element.
         * @param v2 Deuxieme element.
         */
        Vec2f (const float & v1 , const float & v2) ;

        /**
         * @brief  operator * Produit scalaire.
         * @param  v Autre vecteur.
         * @return Flottant resultat du produit scalaire entre deux vecteurs.
         */
        float operator * (Vec2f const & v) const ;
        /**
         * @brief  operator ^ Produit vectoriel.
         * @param  v Autre vecteur.
         * @return Vec2f resultat du produit vectoriel entre deux vecteurs.
         */
        Vec2f operator ^ (Vec2f const & v) const ;
} ;


# endif
