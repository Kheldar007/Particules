/**
 * @file    vec3f.h
 * @author  Isabelle Muller
 */


# ifndef VEC3F_H
# define VEC3F_H


# include "vectorTemplate.h"


typedef Vector <3 , float> VEC3F ; // Simplifier l'ecriture.


/**
 * @class Vec3f Vecteurs de trois flottants.
 */
class Vec3f : public VEC3F
{
    public :

        /******************************* Constructeurs. *******************************/

        /**
         * @brief Vec3f Constructeur vide.
         */
        Vec3f () ;
        /**
         * @brief Vec3f Constructeur.
         * @param v1 Premier element.
         * @param v2 Deuxieme element.
         * @param v3 Troisieme element.
         */
        Vec3f (const float & v1 , const float & v2 , const float & v3) ;

        /******************************** Operateurs. *********************************/

        /**
         * @brief  operator * Produit scalaire.
         * @param  v Autre vecteur.
         * @return Flottant resultat du produit scalaire entre deux vecteurs.
         */
        float operator * (const Vec3f & v) const ;
        /**
         * @brief  operator ^ Produit vectoriel.
         * @param  v Autre vecteur.
         * @return Vec3f resultat du produit vectoriel entre deux vecteurs.
         */
        Vec3f operator ^ (const Vec3f & v) const ;
} ;


# endif
