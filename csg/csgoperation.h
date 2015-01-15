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
        CsgOperation (CsgOperation operation , CsgNode * node1 , CsgNode * node2) ;
        void CO_resizeBoundingBox () ;
} ;


# endif
