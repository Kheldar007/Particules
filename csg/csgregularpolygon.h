/**
 * @file    csgregularpolygon.h
 * @author  Isabelle Muller
 */


# ifndef CSGREGULARPOLYGON_H
# define CSGREGULARPOLYGON_H


# include "csgprimitive.h"


/**
 * @brief CsgRegularPolygon Polygone regulier.
 */
class CsgRegularPolygon : public CsgPrimitive
{
    public :

        /**
         * @brief CsgRegularPolygon Constructeur vide.
         */
        CsgRegularPolygon () ;
        /**
         * @brief ~CsgRegularPolygon Destructeur.
         */
        virtual ~CsgRegularPolygon () ;
        /**
         * @brief CsgRegularPolygon Constructeur.
         * @param nb_sommet Le nombre de sommets.
         */
        CsgRegularPolygon (int nb_sommet) ;

        /**
         * @brief  intersect Intersect avec un point.
         * @param  v Le vecteur.
         * @return Vrai si intersection.
         */
        virtual bool intersect (Vec3f v) ;
        /**
         * @brief update_BB Mettre a jour la boite englobante.
         */
        virtual void update_BB () ;
} ;


# endif
