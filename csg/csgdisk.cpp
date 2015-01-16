/**
 * @file    csgdisk.cpp
 * @author  Isabelle Muller
 */


# include "csgdisk.h"


# define NB_VERT_DISK 200


CsgDisk::CsgDisk()
{
    m_nb_vertices = NB_VERT_DISK;
    update_BB();
    int scaleX = m_scale.M_getColumn3()[0];

    m_tab_vertex = new Vec3f[NB_VERT_DISK];

    for (int i=0; i< m_nb_vertices; ++i)
    {
        Vec3f& v= m_tab_vertex[i];
        v[0] = scaleX * cos (2.0f * M_PI / m_nb_vertices * i);
        v[1] = scaleX * sin (2.0f * M_PI / m_nb_vertices * i);
    }
}

CsgDisk::~CsgDisk()
{
}

bool CsgDisk::intersect (Vec3f v)
{

}

void CsgDisk::update_BB ()
{
    Vec3f tmp;
    m_transform = CN_getTransformation();
    int scaleX = m_transform.M_getColumn3()[0];

    m_boundingBox.BB_setXMax(scaleX);
    m_boundingBox.BB_setYMax(scaleX);
    m_boundingBox.BB_setXMin(-scaleX);
    m_boundingBox.BB_setYMin(-scaleX);
}
