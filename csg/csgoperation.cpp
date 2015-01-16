/**
 * @file    csgoperation.cpp
 * @author  Isabelle Muller
 */


# include "csgoperation.h"


CsgOperation::CsgOperation ()
{
}

CsgOperation::~CsgOperation()
{
}

CsgOperation::CsgOperation (Operation operation , CsgNode * node1 , CsgNode * node2)
{
    m_operation = operation ;

    node1 -> CN_setParent (this) ;
    node2 -> CN_setParent (this) ;

    m_leftChild = node1 ;
    m_rightChild = node2 ;
}

void CsgOperation::update_BB()
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
        m_parent -> update_BB () ;
    }
}


bool CsgOperation::intersect (Vec3f v)
{
    bool result = false ;
    if (m_boundingBox.BB_isInside (v))
    {
        switch (m_operation)
        {
            case UNION :
            {
                result = m_leftChild ->intersect(v) || m_rightChild->intersect(v) ;
                break ;
            }
            case INTERSECTION :
            {
                result = m_leftChild ->intersect(v) && m_rightChild->intersect(v) ;
                break ;
            }
            case DIFFERENCE :
            {
                result = m_leftChild ->intersect(v) && ( !m_rightChild->intersect(v)) ;
                break ;
            }
        }
    }

    return result ;
}
