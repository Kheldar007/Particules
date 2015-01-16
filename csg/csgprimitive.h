/**
 * @file    csgprimitive.h
 * @author  Isabelle Muller
 */


# ifndef CSGPRIMITIVE_H
# define CSGPRIMITIVE_H


# include "csgnode.h"


/**
 * @brief CsgPrimitive Une primitive.
 */
class CsgPrimitive : public CsgNode
{
    protected :

        /**
         * @brief m_tab_vertex Les sommets.
         */
        Vec3f * m_tab_vertex ;
        /**
         * @brief m_nb_vertices Le nombre de sommets.
         */
        int m_nb_vertices ;

    public :

        /**
         * @brief CsgPrimitive Constructeur.
         */
        CsgPrimitive () ;
        /**
         * @brief ~CsgPrimitive Destructeur.
         */
        virtual ~CsgPrimitive();

        /**
         * @brief set_nb_vertices Mutateur.
         * @param nb m_nb_vertices
         */
        void set_nb_vertices(int nb);

        /**
         * @brief  get_nb_vertices Accesseur.
         * @return m_nb_vertices
         */
        int get_nb_vertices();
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
