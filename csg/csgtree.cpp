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

void CsgTree::CT_draw (const Image2Grey & image , CsgNode * currentNode)
{
    currentNode -> CN_set_BB (currentNode -> get_BB ()) ;
    CsgNode * castedNode = static_cast <CsgNode *> (currentNode) ;
    int i = castedNode -> get_BB ().BB_getXMin () , j = 0 ;
    while (i < castedNode -> get_BB ().BB_getXMax ()) // Parcourir la bounding box en largeur.
    {
        j = castedNode -> get_BB ().BB_getYMin () ;
        while (j < castedNode -> get_BB ().BB_getYMax ()) // Parcourir la bounding box en hauteur.
        {
            if ((i >= 0) && (i < image.I_getDimension () [0]) && (j >= 0) && (j < image.I2D_getDimension () [0]))
            {
//                if ((* it) -> intersect (x , y))
//                {
//                    image.I2D_setPixel (j , i , 1) ;
//                }
//                else
//                {
//                    image.I2D_setPixel (j , i , 0) ;
//                }
            }

            j ++ ;
        }

        i ++ ;
    }

    i ++ ;
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
    std::set <CsgNode *>::iterator it = m_roots.find (node) ;
    if (it != m_roots.end ()) // Le noeud correspond a une racine.
    {
        m_roots.erase (node) ; // Supprimer l'element.
    }
    m_map.erase (id) ; // Supprimer de la map.
    m_roots.insert (node ->CN_getLeftChild ()) ; // Rajouter les fils dans m_roots.
    m_roots.insert (node ->CN_getRightChild ()) ;
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
}

CsgNode * CsgTree::CT_addOperation (Operation operation , CsgNode * node1 ,
    CsgNode * node2)
{
    /***************** Chercher les deux noeuds dans les racines. *****************/
    std::set <CsgNode * , Sort>::iterator it1 = m_roots.find (node1) ;
    std::set <CsgNode * , Sort>::iterator it2 = m_roots.find (node2) ;
    assert (it1 != m_roots.end ()) ;
    assert (it2 != m_roots.end ()) ;
    /******************************************************************************/

    CsgNode * node = new CsgOperation (operation , node1 , node2) ;
    static_cast <CsgOperation *> (node) -> get_BB () ;

    /****************** Suppression des noeuds dans les racines. ******************/
    m_roots.erase (it1) ;
    m_roots.erase (it2) ;
    /******************************************************************************/

    m_roots.insert (node) ;
    m_map.insert (std::pair <int , CsgNode *> (node -> CN_getIdentifier () ,
        node)) ;

    node ;
}
