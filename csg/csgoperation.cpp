/**
 * @file    csgoperation.cpp
 * @author  Isabelle Muller
 */


# include "csgoperation.h"


CsgOperation::CsgOperation ()
{
}

CsgOperation::CsgOperation (CsgOperation operation , CsgNode * node1 , CsgNode * node2)
{

}

void CsgOperation::CO_resizeBoundingBox ()
{
    switch (m_operation)
    {
        case UNION :
        {
            m_boundingBox = m_leftChild -> CN_getBoundingBox () +
                            m_rightChild -> CN_getBoundingBox () ;
            break ;
        }
        case INTERSECTION :
        {
            m_boundingBox = m_leftChild -> CN_getBoundingBox () ^
                            m_rightChild -> CN_getBoundingBox () ;
            break ;
        }
        case DIFFERENCE :
        {
            m_boundingBox = m_leftChild -> CN_getBoundingBox () -
                            m_rightChild -> CN_getBoundingBox () ;
            break ;
        }
    }
    if (m_parent != NULL)
    {
        static_cast <CsgOperation *> (m_parent) -> CO_resizeBoundingBox () ;
    }
}
