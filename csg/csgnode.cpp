/**
 * @file    csgnode.cpp
 * @author  Isabelle Muller
 */


# include "csgnode.h"


CsgNode::CsgNode ()
{
    m_parent     = NULL ; // Par defaut pour la racine, pas de parent.
    m_identifier = 0 ; // La racine est 0.
    m_leftChild    = NULL ; // Pas de fils gauche.
    m_rightChild   = NULL ; // Pas de fils droit.
}

CsgNode::CsgNode (int id, CsgNode * p)
{
    m_identifier = id ; // L'identifiant.
    m_parent     = p ; // Le parent du noeud courant.
    m_leftChild  = NULL ; // Pas de fils gauche.
    m_rightChild = NULL ; // Pas de fils droit.
}

void CsgNode::CN_setBoundingBox (BoundingBox bb)
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

BoundingBox CsgNode::CN_getBoundingBox ()
{
    return m_boundingBox ;
}
