/**
 * @file    csgregularpolygon.cpp
 * @author  Isabelle Muller
 */


# include "csgregularpolygon.h"


CsgRegularPolygon::CsgRegularPolygon()
{
}

CsgRegularPolygon::~CsgRegularPolygon()
{
}


CsgRegularPolygon::CsgRegularPolygon(int nb_sommet)
{
    m_nb_vertices = nb_sommet;
    m_tab_vertex = new Vec3f[nb_sommet];
    int scaleX = m_scale.M_getColumn3()[0];
    for (int i=0; i< m_nb_vertices; ++i)
    {
        Vec3f& v= m_tab_vertex[i];
        v[0] = scaleX * cos (2.0f * M_PI / m_nb_vertices * i);
        v[1] = scaleX * sin (2.0f * M_PI / m_nb_vertices * i);
    }
    update_BB();
}


void CsgRegularPolygon::update_BB()
{
    Vec3f tmp;
    for (int i=0; i< m_nb_vertices; ++i)
    {
        m_transform = CN_getTransformation();
        tmp = m_transform * m_tab_vertex[i];

        if(tmp[0] < m_boundingBox.BB_getXMin())
            m_boundingBox.BB_setXMin(m_tab_vertex[i][0]);

        if(tmp[0] > m_boundingBox.BB_getXMax())
            m_boundingBox.BB_setXMax(m_tab_vertex[i][0]);

        if(tmp[1] < m_boundingBox.BB_getYMin())
            m_boundingBox.BB_setYMin(m_tab_vertex[i][1]);

        if(tmp[1] > m_boundingBox.BB_getYMax())
            m_boundingBox.BB_setYMax(m_tab_vertex[i][1]);
    }
}


bool CsgRegularPolygon::intersect (Vec3f v)
{
    Vec3f direct;
    Vec3f indirect;
    Vec3f vectTest;

    m_transform = CN_getTransformation();

    v = m_transform.M_reverse() * v;


    for (int i = 0 ; i <= m_nb_vertices ; i ++)
    {
        direct[0] = m_tab_vertex [(i+1) % m_nb_vertices][0] - m_tab_vertex[i % m_nb_vertices][0] ;
        direct[1] = m_tab_vertex [(i+1) % m_nb_vertices][1] - m_tab_vertex[i % m_nb_vertices][1] ;
        direct[2] = 1 ;

        indirect[0] = m_tab_vertex[(i-1) % m_nb_vertices][0] - m_tab_vertex[i % m_nb_vertices][0] ;
        indirect[1] = m_tab_vertex[(i-1) % m_nb_vertices][1] - m_tab_vertex[i % m_nb_vertices][1] ;
        indirect[2] = 1 ;

        vectTest[0] = v[0] - m_tab_vertex[i % m_nb_vertices][0] ;
        vectTest[1] = v[1] - m_tab_vertex[i % m_nb_vertices][1] ;
        vectTest[2] = 1 ;

        if (((direct ^ vectTest) * (vectTest ^ indirect)) <= 0)
        {
            return false;
        }
    }

    return true; ;
}
