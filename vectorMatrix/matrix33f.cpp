/**
 * @file    matrix33f.cpp
 * @author  Isabelle Muller
 */


# include "matrix33f.h"


Matrix33f::Matrix33f ()
{
    column1 = Vec3f (1 , 0 , 0) ;
    column2 = Vec3f (0 , 1 , 0) ;
    column3 = Vec3f (0 , 0 , 1) ;
}

Matrix33f::Matrix33f
    (const float & l1c1 , const float & l2c1 , const float & l3c1 ,
     const float & l1c2 , const float & l2c2 , const float & l3c2 ,
     const float & l1c3 , const float & l2c3 , const float & l3c3)
{
    column1 = Vec3f (l1c1 , l2c1 , l3c1) ; // Premiere colonne.
    column2 = Vec3f (l1c2 , l2c2 , l3c2) ; // Deuxieme colonne.
    column3 = Vec3f (l1c3 , l2c3 , l3c3) ; // Troisieme colonne.
}

Vec3f Matrix33f::M_getColumn1 ()
{
    return column1 ; // Renvoyer la premiere colonne.
}

Vec3f Matrix33f::M_getColumn2 ()
{
    return column2 ; // Renvoyer la deuxieme colonne.
}

Vec3f Matrix33f::M_getColumn3 ()
{
    return column3 ; // Renvoyer la troisieme colonne.
}

Matrix33f Matrix33f::M_reverse () const
{
    float determinant = (column1 [0] * column2 [1] * column3 [2]) +
                        (column2 [0] * column3 [1] * column1 [2]) +
                        (column3 [0] * column1 [1] * column2 [2]) -
                        (column3 [0] * column2 [1] * column1 [2]) -
                        (column3 [1] * column2 [2] * column1 [0]) -
                        (column3 [2] * column2 [0] * column1 [1]) ; // Determinant de la matrice en utilisant la regle de Sarrus.
    if (determinant != 0) // Si le determinant n'est pas nul.
    {
        Vec3f newColumn1 =
            Vec3f (((column2 [1] * column3 [2]) - (column3 [1] * column2 [2])) / determinant ,
                   ((column3 [0] * column2 [2]) - (column2 [0] * column3 [2])) / determinant ,
                   ((column2 [0] * column3 [1]) - (column3 [0] * column2 [1])) / determinant) ;
        Vec3f newColumn2 =
            Vec3f (((column3 [1] * column1 [2]) - (column1 [1] * column3 [2])) / determinant ,
                   ((column1 [0] * column3 [2]) - (column3 [0] * column1 [2])) / determinant ,
                   ((column3 [0] * column1 [1]) - (column1 [0] * column3 [1])) / determinant) ;
        Vec3f newColumn3 =
            Vec3f (((column1 [1] * column2 [2]) - (column2 [1] * column1 [2])) / determinant ,
                   ((column2 [0] * column1 [2]) - (column1 [0] * column2 [2])) / determinant ,
                   ((column1 [0] * column2 [1]) - (column2 [0] * column1 [1])) / determinant) ;
        return Matrix33f (newColumn1 [0] , newColumn1 [1] , newColumn1 [2] ,
                          newColumn2 [0] , newColumn2 [1] , newColumn2 [2] ,
                          newColumn3 [0] , newColumn3 [1] , newColumn3 [2]) ;
    }
    else
    {
        return Matrix33f (column1 [0] , column1 [1] , column1 [2] ,
                          column2 [0] , column2 [1] , column2 [2] ,
                          column3 [0] , column3 [1] , column3 [2]) ; // Si la matrice n'est pas inversible.
    }
}

void Matrix33f::M_applyTranslate (const Vec2f v)
{
    int i = 0 ;
    while (i < 3)
    {
        (* this).column3 [i] += ((* this).column1 [i] * v [0]) +
                                ((* this).column2 [i] * v [1]) ;
        i ++ ;
    }
}

void Matrix33f::M_setTranslate (const Vec2f v)
{
    column1 = Vec3f (1 ,     0 ,     0) ;
    column2 = Vec3f (0 ,     1 ,     0) ;
    column3 = Vec3f (v [0] , v [1] , 1) ;
}

void Matrix33f::M_applyRotate (const float angle)
{
    float m11 = (cos (angle) * column1 [0]) - (sin (angle) * column2 [0]) ;
    float m12 = (sin (angle) * column1 [0]) + (cos (angle) * column2 [0]) ;
    float m21 = (cos (angle) * column1 [1]) - (sin (angle) * column2 [1]) ;
    float m22 = (sin (angle) * column1 [1]) + (cos (angle) * column2 [1]) ;
    float m31 = (cos (angle) * column1 [2]) - (sin (angle) * column2 [2]) ;
    float m32 = (sin (angle) * column1 [2]) + (cos (angle) * column2 [2]) ;

    column1 = Vec3f (m11 , m21 , m31) ;
    column2 = Vec3f (m12 , m22 , m32) ;
}

void Matrix33f::M_setRotate (const float angle)
{
    column1 = Vec3f (cos (angle) ,   sin (angle) , 0) ;
    column2 = Vec3f (- sin (angle) , cos (angle) , 0) ;
    column3 = Vec3f (0 ,             0 ,           1) ;
}

void Matrix33f::M_applyHomothety (const Vec2f v)
{
    int i = 0 ;
    while (i < 3)
    {
        (* this).column1 [i] *= v [0] ;
        (* this).column2 [i] *= v [1] ;
        i ++ ;
    }
}

void Matrix33f::M_setHomothety (const Vec2f v)
{
    column1 = Vec3f (v [0] , 0 ,     0) ;
    column2 = Vec3f (0 ,     v [1] , 0) ;
    column3 = Vec3f (0 ,     0 ,     1) ;
}

Vec3f Matrix33f::operator * (const Vec3f & v) const
{
    float l1 = (column1 [0] * v [0]) + (column2 [0] * v [1]) + (column3 [0] * v [2]) ;
    float l2 = (column1 [1] * v [0]) + (column2 [1] * v [1]) + (column3 [1] * v [2]) ;
    float l3 = (column1 [2] * v [0]) + (column2 [2] * v [1]) + (column3 [2] * v [2]) ;

    return Vec3f (l1 , l2 , l3) ;
}
