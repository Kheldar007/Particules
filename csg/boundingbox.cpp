/**
 * @file    boundingbox.cpp
 * @author  Isabelle Muller
 */


# include "boundingbox.h"


BoundingBox::BoundingBox ()
{
    m_xMin = 0 ;
    m_xMax = 0 ;
    m_yMin = 0 ;
    m_yMax = 0 ;
}

BoundingBox::~BoundingBox ()
{
}

float BoundingBox::BB_getXMin ()
{
    return m_xMin ;
}

float BoundingBox::BB_getXMax ()
{
    return m_xMax ;
}

float BoundingBox::BB_getYMin ()
{
    return m_yMin ;
}

float BoundingBox::BB_getYMax ()
{
    return m_yMax ;
}

void BoundingBox::BB_setXMin (float xMin)
{
    m_xMin = xMin ;
}

void BoundingBox::BB_setXMax (float xMax)
{
    m_xMax = xMax ;
}

void BoundingBox::BB_setYMin (float yMin)
{
    m_yMin = yMin ;
}

void BoundingBox::BB_setYMax (float yMax)
{
    m_yMax = yMax ;
}

BoundingBox * BoundingBox::operator + (BoundingBox * bb)
{
    BoundingBox * result = new BoundingBox () ;

    /*************************** Cote le plus a gauche. ***************************/
    if (m_xMin <= bb -> BB_getXMin ())
    {
        result -> BB_setXMin (m_xMin) ;
    }
    else
    {
        result -> BB_setXMin (bb -> BB_getXMin ()) ;
    }
    /*************************** Cote le plus a droite. ***************************/
    if (m_xMax >= bb -> BB_getXMax ())
    {
        result -> BB_setXMax (m_xMax) ;
    }
    else
    {
        result -> BB_setXMax (bb -> BB_getXMax ()) ;
    }
    /**************************** Cote le plus en bas. ****************************/
    if (m_yMin <= bb -> BB_getYMin ())
    {
        result -> BB_setYMin (m_yMin) ;
    }
    else
    {
        result -> BB_setYMin (bb -> BB_getYMin ()) ;
    }
    /*************************** Cote le plus en haut. ****************************/
    if (m_yMax >= bb -> BB_getYMax ())
    {
        result -> BB_setYMax (m_yMax) ;
    }
    else
    {
        result -> BB_setYMax (bb -> BB_getYMax ()) ;
    }
    /******************************************************************************/

    return result ;
}

BoundingBox * BoundingBox::operator ^ (BoundingBox * bb)
{
    BoundingBox * result = new BoundingBox () ;

    /************************** Cote le moins a gauche. ***************************/
    if (m_xMin <= bb -> BB_getXMin ())
    {
        result -> BB_setXMin (bb -> BB_getXMin ()) ;
    }
    else
    {
        result -> BB_setXMin (m_xMin) ;
    }
    /************************** Cote le moins a droite. ***************************/
    if (m_xMax >= bb -> BB_getXMax ())
    {
        result -> BB_setXMax (bb -> BB_getXMax ()) ;
    }
    else
    {
        result -> BB_setXMax (m_xMax) ;
    }
    /*************************** Cote le moins en bas. ****************************/
    if (m_yMin <= bb -> BB_getYMin ())
    {
        result -> BB_setYMin (bb -> BB_getYMin ()) ;
    }
    else
    {
        result -> BB_setYMin (m_yMin) ;
    }
    /*************************** Cote le moins en haut. ***************************/
    if (m_yMax >= bb -> BB_getYMax ())
    {
        result -> BB_setYMax (bb -> BB_getYMax ()) ;
    }
    else
    {
        result -> BB_setYMax (m_yMax) ;
    }
    /******************************************************************************/

    return result ;
}

BoundingBox * BoundingBox::operator - (BoundingBox * bb)
{
    BoundingBox * result = new BoundingBox () ;

    result -> BB_setXMin (m_xMin - bb -> BB_getXMin ()) ;
    result -> BB_setXMax (m_xMax - bb -> BB_getXMax ()) ;
    result -> BB_setYMin (m_yMin - bb -> BB_getYMin ()) ;
    result -> BB_setYMin (m_yMax - bb -> BB_getYMax ()) ;

    return result ;
}

bool BoundingBox::BB_isEmpty ()
{
    if ((m_xMin == 0) && (m_xMax == 0) && (m_yMin == 0) && (m_yMax == 0))
    {
        return true ;
    }
    return false ;
}

Vec2f * BoundingBox::BB_center ()
{
    return new Vec2f ((m_xMax - m_xMin) / 2 , (m_yMax - m_yMin) / 2) ;
}

bool BoundingBox::BB_isInside (const Vec2f & vector)
{
    if ((vector [0] >= m_xMin) && (vector [0] <= m_xMax) &&
        (vector [1] >= m_yMin) && (vector [1] <= m_yMax))
    {
        return true ;
    }
    return false ;
}

void BoundingBox::BB_addVector (Vec2f * vector)
{
    // TODO.
}
