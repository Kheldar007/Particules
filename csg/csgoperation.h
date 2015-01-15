/**
 * @file    csgoperation.h
 * @author  Isabelle Muller
 */


# ifndef CSGOPERATION_H
# define CSGOPERATION_H


# include "csgnode.h"


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

        Operation m_operation ;

    public :

        CsgOperation () ;
        CsgOperation (Operation operation , CsgNode * node1 , CsgNode * node2) ;
        virtual BoundingBox get_BB () ;
} ;


# endif
