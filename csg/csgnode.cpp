/**
 * @file    csgnode.cpp
 * @author  Isabelle Muller
 */


# include "csgnode.h"


CsgNode::CsgNode ()
{
    parent = NULL ; // Par defaut pour la racine, pas de parent.
    identifier = 0 ; // La racine est 0.
}

CsgNode::CsgNode (int id, CsgNode * p)
{
    identifier = id ; //
    parent = p ; // Le parent du noeud courant.
}

void CsgNode::CN_setBoundingBox (BoundingBox bb)
{
    boundingBox = bb ; // Affecter la bounding box.
}

CsgNode * CsgNode::CN_getParent ()
{
    return parent ; // Retourner le parent.
}

int CsgNode::CN_getIdentifier ()
{
    return identifier ; // Retourner l'identifiant.
}
