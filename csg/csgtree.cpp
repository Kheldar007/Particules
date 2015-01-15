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
    CsgNode * node = CT_map (id) ; // Trouver le noeud.
    CsgNode * result = new CsgNode (id , node -> CN_getParent ()) ;

    result -> CN_setLeftChild (node -> CN_getLeftChild ()) ;
    result -> CN_setRightChild (node -> CN_getRightChild ()) ;

    return result ;
}

void CsgTree::CT_deleteNodesRec (CsgNode * node)
{
    m_map.erase (node -> CN_getIdentifier ()) ; // Supprimer de la map.
    node -> CN_getParent () -> CN_setLeftChild (node -> CN_getLeftChild ()) ;
    node -> CN_getParent () -> CN_setRightChild (node -> CN_getRightChild ()) ;
    delete node ;
}

void CsgTree::CT_deleteNode (int id)
{
    CsgNode * node = CT_map (id) ; // Rechercher le noeud.
    assert (node != NULL) ; // Si le noeud existe.
    std::set <CsgNode *>::iterator it = m_roots.find (node) ;
    if (it != m_roots.end ()) // Le noeud correspond a une racine.
    {
        m_roots.erase (node) ; // Supprimer l'element.
        delete node ;
    }
    else
    {
        CsgNode * parent = node -> CN_getParent () ;
        assert (parent != NULL) ; // Verifier qu'il n'y ait pas d'erreur. Si le noeud n'est pas une racine, il ne devrait pas avoir de parent.
        std::set <CsgNode *>::iterator it2 = m_roots.find (parent) ;
        if (it2 != m_roots.end ()) // Si le pere est une racine.
        {
            CT_deleteNodesRec (node) ;
            m_roots.erase (parent) ;
            if (parent -> CN_getLeftChild () == node) // Si c'est le fils gauche, placer le fils droit dans la racine.
            {
                m_roots.insert (parent -> CN_getRightChild ()) ;
                parent -> CN_setRightChild (NULL) ;
                delete (parent) ;
            }
            else if (parent -> CN_getRightChild () == node) // Si c'est le fils droit, placer le fils gauche dans la racine.
            {
                m_roots.insert (parent -> CN_getLeftChild ()) ;
                parent -> CN_setLeftChild (NULL) ;
                delete (parent) ;
            }
        }
        else
        {
            CsgNode * grandParent = parent -> CN_getParent () ;
            assert (grandParent != NULL) ; // Il y a un grand-parent, vu que le parent n'est pas dans la racine.
            std::set <CsgNode *>::iterator it3 = m_roots.find (grandParent) ;
//            if(it3 != m_roots.end())//Cas général grand père qui est racine
//            {
//                removeNodeRec(new_ptr);
//                csgNode * parent = new_ptr->CN_getParent ();
//                csgNode * grandParent = (new_ptr->CN_getParent ())->CN_getParent ();
//                if(static_cast<csgOperation *>(new_ptr->CN_getParent ())->isLeft(new_ptr))
//                {
//                    if(static_cast<csgOperation *>(grandParent)->isLeft(parent))
//                    {
//                        (grandParent)->setLeft(static_cast<csgOperation *>(parent)->getRight());
//                        (parent)->setRight(NULL);
//                        delete parent;
//                    }
//                    else if(static_cast<csgOperation *>(grandParent)->isRight(parent))
//                    {
//                        (grandParent)->setRight(static_cast<csgOperation *>(parent)->getRight());
//                        (parent)->setRight(NULL);
//                        delete parent;
//                    }
//                    else
//                    {
//                        assert(0);
//                    }
//                }
//                else if(static_cast<csgOperation *>(new_ptr->CN_getParent ())->isRight(new_ptr))
//                {
//                    if(static_cast<csgOperation *>(grandParent)->isLeft(parent))
//                    {
//                        (grandParent)->setLeft(static_cast<csgOperation *>(parent)->getLeft());
//                        (parent)->setLeft(NULL);
//                        delete parent;
//                    }
//                    else if(static_cast<csgOperation *>(grandParent)->isRight(parent))
//                    {
//                        (grandParent)->setRight(static_cast<csgOperation *>(parent)->getLeft());
//                        (parent)->setLeft(NULL);
//                        delete parent;
//                    }
//                    else
//                    {
//                        assert(0);
//                    }
//                }
//                else
//                {
//                    assert(0);
//                }
//            }
        }
    }
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

void CsgTree::CT_addOperation(CsgOperation operation , CsgNode * node1 ,
            CsgNode * node2)
{
    /***************** Chercher les deux noeuds dans les racines. *****************/
    std::set <CsgNode * , Sort>::iterator it1 = m_roots.find (node1) ;
    std::set <CsgNode * , Sort>::iterator it2 = m_roots.find (node2) ;
    assert (it1 != m_roots.end ()) ;
    assert (it2 != m_roots.end ()) ;
    /******************************************************************************/

    CsgNode * node = new CsgOperation (operation , node1 , node2) ;
    static_cast <CsgOperation *> (node) -> CO_resizeBoundingBox () ;

    /****************** Suppression des noeuds dans les racines. ******************/
    m_roots.erase (it1) ;
    m_roots.erase (it2) ;
    /******************************************************************************/

    m_roots.insert (node) ;
    m_map.insert (std::pair <int , CsgNode *> (node -> CN_getIdentifier () ,
        node)) ;
}
