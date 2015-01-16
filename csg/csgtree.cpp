/**
 * @file    csgtree.cpp
 * @author  Isabelle Muller
 */


# include "csgtree.h"


CsgTree::CsgTree ()
{
    m_leaves.clear () ;
    m_roots.clear () ;
}

CsgTree::~CsgTree ()
{
    m_leaves.clear () ;
    m_roots.clear () ;
}

CsgNode * CsgTree::CT_map (int id)
{
    std::map <int , CsgNode *>::iterator i = m_map.find (id) ; // Trouver le noeud grace a son indice.
    return i -> second ;
}

void CsgTree::CT_load (std::string format)
{
}

void CsgTree::CT_save (std::string format)
{
}

void CsgTree::CT_draw (Image2Grey & image , CsgNode * currentNode)
{
    Vec3f v ;
    int i = currentNode -> CN_getBoundingBox ().BB_getXMin () , j;
    while (i < currentNode -> CN_getBoundingBox ().BB_getXMax ()) // Parcourir la bounding box en largeur.
    {
        j = currentNode -> CN_getBoundingBox ().BB_getYMin () ;
        while (j < currentNode -> CN_getBoundingBox ().BB_getYMax ()) // Parcourir la bounding box en hauteur.
        {
            if ((i >= 0) && (i < image.I2D_getDimension()[0]) && (j >= 0) && (j < image.I2D_getDimension()[1]))
            {
                v [0] = i ;
                v[1] = j ;
                if (currentNode -> intersect (v))
                {
                    image.I2D_setPixel (j , i , 255) ;
                }
                else
                {
                    image.I2D_setPixel (j , i , 0) ;
                }
            }
            j ++ ;
        }
        i ++ ;
    }

}

CsgNode * CsgTree::CT_clone (int id)
{
    CsgNode * node = CT_map (id) ; // Trouver le noeud.
    CsgNode * result = new CsgNode (id , node -> CN_getParent ()) ;

    result -> CN_setLeftChild (node -> CN_getLeftChild ()) ;
    result -> CN_setRightChild (node -> CN_getRightChild ()) ;

    return result ;
}

void CsgTree::CT_deleteNode (int id)
{
    CsgNode * node = CT_map (id) ;
    CsgNode * filsG = node ->CN_getLeftChild ();
    CsgNode * filsD = node ->CN_getRightChild ();

    std::set <CsgNode *>::iterator it = m_roots.find (node) ;
    if (it != m_roots.end ()) // Le noeud correspond a une racine.
    {
        m_roots.erase (node) ; // Supprimer l'element.
    }
    m_map.erase (id) ; // Supprimer de la map.
    m_roots.insert (filsG) ; // Rajouter les fils dans m_roots.
    m_roots.insert (filsD) ;

    // on met les fils.m_parent a NULL, car une racine n'a pas de parent.
    filsG->CN_setParent(NULL);
    filsD->CN_setParent(NULL);
    delete node ;
}

void CsgTree::CT_swapSons (CsgNode * node)
{
    CsgNode * node_t = node -> CN_getLeftChild () ;
    node -> CN_setLeftChild (node -> CN_getRightChild ()) ;
    node -> CN_setRightChild (node_t) ;
}

void CsgTree::CT_addPrimitive (CsgPrimitive * primitive)
{
    CsgNode * node = primitive ; // La primitive doit etre un CsgNode.
    m_leaves.insert (node) ;
    m_roots.insert (node) ;
    m_map.insert (std::pair <int , CsgNode *> (node -> CN_getIdentifier () ,
        node)) ;
    node -> countId++;
}

CsgNode * CsgTree::CT_addOperation (Operation operation , CsgNode * node1 ,
    CsgNode * node2)
{
    /***************** Chercher les deux noeuds dans les racines. *****************/
    std::set <CsgNode * , Sort>::iterator it1 = m_roots.find (node1) ;
    std::set <CsgNode * , Sort>::iterator it2 = m_roots.find (node2) ;

    // on test si it1 it2 non null
    assert (it1 != m_roots.end ()) ;
    assert (it2 != m_roots.end ()) ;

    CsgNode * node = new CsgOperation (operation , node1 , node2) ;
    node->CN_getBoundingBox() ;

    /****************** Suppression des noeuds dans les racines. ******************/
    m_roots.erase (it1) ;
    m_roots.erase (it2) ;
    /******************************************************************************/

    m_roots.insert (node) ;
    m_map.insert (std::pair <int , CsgNode *> (node -> CN_getIdentifier () ,
        node)) ;

    // On renvoie le node courant.
    return node;
}
