/**
 * @file    csgprimitive.cpp
 * @author  Isabelle Muller
 */


# include "csgprimitive.h"


CsgPrimitive::CsgPrimitive()
{
}

CsgPrimitive::~CsgPrimitive()
{
}

void CsgPrimitive::set_nb_vertices(int nb)
{
    m_nb_vertices = nb;
}

int CsgPrimitive::get_nb_vertices()
{
    return m_nb_vertices;
}

void CsgPrimitive::update_BB()
{
}

bool CsgPrimitive::intersect (Vec3f vector)
{
}
