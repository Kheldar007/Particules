/**
 * @file    csgnode.cpp
 * @author  Isabelle Muller
 */


# include "csgnode.h"


CsgNode::CsgNode ()
{
    m_parent     = NULL ; // Par defaut pour la racine, pas de parent.
    m_identifier = countId; ; // La racine est 0.
    m_leftChild    = NULL ; // Pas de fils gauche.
    m_rightChild   = NULL ; // Pas de fils droit.
    m_boundingBox = BoundingBox();
    m_position = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
    m_rotation = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
    m_scale = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
}

int CsgNode::countId =0;

CsgNode::~CsgNode ()
{
}

CsgNode::CsgNode (int id, CsgNode * p)
{
    m_identifier = id ; // L'identifiant.
    m_parent     = p ; // Le parent du noeud courant.
    m_leftChild  = NULL ; // Pas de fils gauche.
    m_rightChild = NULL ; // Pas de fils droit.
    m_boundingBox = BoundingBox();
    m_position = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
    m_rotation = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
    m_scale = Matrix33f(1.0f , 0 , 0 , 0 , 1.0f , 0 , 0 , 0 , 1.0f);
}

void CsgNode::CN_set_BB (BoundingBox& bb)
{
    m_boundingBox = bb ; // Affecter la bounding box.
}

void CsgNode::CN_setParent (CsgNode * node)
{
    m_parent = node ;
}

void CsgNode::CN_setLeftChild (CsgNode * node)
{
    m_leftChild = node ;
}

void CsgNode::CN_setRightChild (CsgNode * node)
{
    m_rightChild = node ;
}

int CsgNode::CN_getIdentifier ()
{
    return m_identifier ; // Retourner l'identifiant.
}

CsgNode * CsgNode::CN_getParent ()
{
    return m_parent ; // Retourner le parent.
}

CsgNode * CsgNode::CN_getLeftChild ()
{
    return m_leftChild ;
}

CsgNode * CsgNode::CN_getRightChild ()
{
    return m_rightChild ;
}

BoundingBox & CsgNode::CN_getBoundingBox ()
{
    return m_boundingBox ;
}

void CsgNode::update_BB ()
{
}

bool CsgNode::intersect (Vec3f vector)
{
}


Matrix33f CsgNode::CN_getTransformation()
{
    m_transform = m_scale * m_rotation * m_position;

    if(CN_getParent() == NULL)
    {
        return m_transform;
    }
    else
    {
        return CN_getParent()->CN_getTransformation() * m_transform;
    }
}

const Matrix33f &CsgNode::CN_getPosition()
{
    return m_position;
}

const Matrix33f &CsgNode::CN_getRotation()
{
    return m_rotation;
}

const Matrix33f &CsgNode::CN_getScale()
{
    return m_scale;
}

void CsgNode::CN_setPosition(Matrix33f& m)
{
    m_position = m;
}

void CsgNode::CN_setRotation(Matrix33f& m)
{
    m_rotation = m;
}

void CsgNode::CN_setScale(Matrix33f& m)
{
    m_scale = m;
}
