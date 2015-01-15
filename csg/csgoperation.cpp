/**
 * @file    csgoperation.cpp
 * @author  Isabelle Muller
 */


# include "csgoperation.h"


CsgOperation::CsgOperation ()
{
}

CsgOperation::CsgOperation (Operation operation , CsgNode * node1 , CsgNode * node2)
{

}

BoundingBox CsgOperation::get_BB ()
{
    switch (m_operation)
    {
        case UNION :
        {
            m_boundingBox = m_leftChild -> get_BB () +
                            m_rightChild -> get_BB () ;
            break ;
        }
        case INTERSECTION :
        {
            m_boundingBox = m_leftChild -> get_BB () ^
                            m_rightChild -> get_BB () ;
            break ;
        }
        case DIFFERENCE :
        {
            m_boundingBox = m_leftChild -> get_BB () -
                            m_rightChild -> get_BB () ;
            break ;
        }
    }
    if (m_parent != NULL)
    {
        static_cast <CsgOperation *> (m_parent) -> get_BB () ;
    }
}
