/**
 * @file    vec2f.cpp
 * @author  Isabelle Muller
 */


# include "vec2f.h"


Vec2f::Vec2f ()
{
}

Vec2f::Vec2f (const float & v1 , const float & v2)
{
    m_data [0] = v1 ;
    m_data [1] = v2 ;
}

float Vec2f::operator * (const Vec2f & v) const
{
    float result = 0 ; // Resultat nul par defaut.

    /************************ Calcul du produit scalaire. *************************/
    float r1 = (* this) [0] * v [0] ;
    float r2 = (* this) [1] * v [1] ;
    result = r1 + r2 ;
    /******************************************************************************/

    return result ; // Retourner le resultat.
}

Vec2f Vec2f::operator ^ (const Vec2f & v) const
{
    /************************ Calcul du produit vectoriel. ************************/
    float r1 = ((* this) [1] * v [0]) - ((* this) [0] * v [1]) ;
    float r2 = ((* this) [0] * v [1]) - ((* this) [1] * v [0]) ;
    /******************************************************************************/

    return Vec2f (r1 , r2) ; // Retourner le resultat.
}
