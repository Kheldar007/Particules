/**
 * @file    csgnode.cpp
 * @author  Isabelle Muller
 */


# include "csgnode.h"


CsgNode::CsgNode ()
{
    m_parent = NULL ; // Par defaut pour la racine, pas de parent.
    m_identifier = 0 ; // La racine est 0.
}

CsgNode::CsgNode (int id, CsgNode * p)
{
    m_identifier = id ; //
    m_parent = p ; // Le parent du noeud courant.
}

void CsgNode::CN_setBoundingBox (BoundingBox bb)
{
    m_boundingBox = bb ; // Affecter la bounding box.
}

CsgNode * CsgNode::CN_getParent ()
{
    return m_parent ; // Retourner le parent.
}

int CsgNode::CN_getIdentifier ()
{
    return m_identifier ; // Retourner l'identifiant.
}

BoundingBox CsgNode::CN_getBoundingBox ()
{
    return m_boundingBox ;
}
