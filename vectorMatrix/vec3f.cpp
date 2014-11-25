/**
 * @file    vec3f.cpp
 * @author  Isabelle Muller
 */


# include "vec3f.h"

Vec3f::Vec3f ()
{
}

Vec3f::Vec3f (const float & v1 , const float & v2 , const float & v3)
{
    m_data [0] = v1 ;
    m_data [1] = v2 ;
    m_data [2] = v3 ;
}

float Vec3f::operator * (Vec3f const & v) const
{
    float result = 0 ; // Resultat nul par defaut.

    /************************ Calcul du produit scalaire. *************************/
    float r1 = (* this) [0] * v [0] ;
    float r2 = (* this) [1] * v [1] ;
    float r3 = (* this) [2] * v [2] ;
    result = r1 + r2 + r3 ;
    /******************************************************************************/

    return result ; // Retourner le resultat.
}

Vec3f Vec3f::operator ^ (Vec3f const & v) const
{
    /************************ Calcul du produit vectoriel. ************************/
    float r1 = ((* this) [1] * v [2]) - ((* this) [2] * v [1]) ;
    float r2 = ((* this) [2] * v [0]) - ((* this) [0] * v [2]) ;
    float r3 = ((* this) [0] * v [1]) - ((* this) [1] * v [0]) ;
    /******************************************************************************/

    return Vec3f (r1 , r2 , r3) ; // Retourner le resultat.
}
