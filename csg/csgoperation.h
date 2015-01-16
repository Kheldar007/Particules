/**
 * @file    csgoperation.h
 * @author  Isabelle Muller
 */


# ifndef CSGOPERATION_H
# define CSGOPERATION_H


# include "csgnode.h"


/**
 * @brief Operation Les differents types d'operation.
 */
enum Operation
{
    UNION ,
    INTERSECTION ,
    DIFFERENCE
} ;

/**
 * @brief CsgOperation Une operation.
 */
class CsgOperation : public CsgNode
{
    protected :

        /**
         * @brief m_operation L'operation.
         */
        Operation m_operation ;

    public :

        /**
         * @brief CsgOperation Constructeur vide.
         */
        CsgOperation () ;
        /**
         * @brief ~CsgOperation Destructeur.
         */
        virtual ~CsgOperation () ;
        /**
         * @brief CsgOperation Constructeur.
         * @param operation L'operation.
         * @param node1     Le premier fils.
         * @param node2     Le deuxieme fils.
         */
        CsgOperation (Operation operation , CsgNode * node1 , CsgNode * node2) ;
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
