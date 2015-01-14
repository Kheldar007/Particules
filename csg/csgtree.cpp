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

void CsgTree::CT_draw (const Image2Grey & image)
{
    std::set <CsgNode *>::iterator it = m_roots.begin() ;
    while (it != m_roots.end ())
    {
        int i = (* it) -> CN_getBoundingBox ().BB_getXMin () , j = 0 ;
        while (i < (* it) -> CN_getBoundingBox ().BB_getXMax ()) // Parcourir la bounding box en largeur.
        {
            j = (* it) -> CN_getBoundingBox ().BB_getYMin () ;
            while (j < (* it) -> CN_getBoundingBox ().BB_getYMax ()) // Parcourir la bounding box en hauteur.
            {
                if ((i >= 0) && (i < image.I_getDimension () [0]) && (j >= 0) && (j < image.I2D_getDimension () [0]))
                {
//                    if ((* it) -> intersect (x , y))
//                    {
//                        image.I2D_setPixel (j , i , 1) ;
//                    }
//                    else
//                    {
//                        image.I2D_setPixel (j , i , 0) ;
//                    }
                }

                j ++ ;
            }

            i ++ ;
        }

        i ++ ;
    }
}

CsgNode * CsgTree::CT_clone (int id)
{
    return new CsgNode (id , CT_map (id) -> CN_getParent ()) ;
}

void CsgTree::CT_deleteNode (int id)
{
    CsgNode * node = CT_map (id) ; // Rechercher le noeud.
    assert (node != NULL) ; // Si le noeud existe.
    std::set <CsgNode *>::iterator it = m_roots.find (node) ;
//    if (it != m_roots.end ()) // Le noeud correspond a une racine.
    {
        m_roots.erase (node) ; // Supprimer l'element.
        delete node ;
    }
}

void CsgTree::CT_swapSons (CsgNode * node)
{
    CsgNode * node_t = node -> CN_getLeftChild () ;
    node -> CN_setLeftChild (node -> CN_getRightChild ()) ;
    node -> CN_setRightChild (node_t) ;
}
