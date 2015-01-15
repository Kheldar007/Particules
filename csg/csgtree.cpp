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
//    if (dynamic_cast <CsgPrimitive *> (node) != NULL) // Si c'est une primitive.
//    {
//        m_leaves.erase (node) ; // Supprimer des feuilles, car c'est une primitive.
//    }
//    else if (dynamic_cast <CsgOperation *> (node) != NULL) // C'est une operation.
//    {
//        /***************** Supprimer les enfants, leurs enfants etc. ******************/
//        CT_deleteNodesRec (node -> CN_getLeftChild ()) ;
//        CT_deleteNodesRec (node -> CN_getRightChild ()) ;
//        /******************************************************************************/
//    }
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
        assert (node -> CN_getParent() != NULL) ; // Verifier qu'il n'y ait pas d'erreur. Si le noeud n'est pas une racine, il ne devrait pas avoir de parent.
        std::set <CsgNode *>::iterator it2 = m_roots.find (node -> CN_getParent ()) ;
        if (it2 != m_roots.end ()) // Si le pere est une racine.
        {
            CT_deleteNodesRec (node) ;
            m_roots.erase (node -> CN_getParent ()) ;
            if (node -> CN_getParent () -> CN_getLeftChild () == node) // Si c'est le fils gauche, placer le fils droit dans la racine.
            {
                m_roots.insert (node -> CN_getParent () -> CN_getRightChild ()) ;
                node -> CN_getParent () -> CN_setRightChild (NULL) ;
                delete (node -> CN_getParent ()) ;
            }
            else if (node -> CN_getParent () -> CN_getRightChild () == node) // Si c'est le fils droit, placer le fils gauche dans la racine.
            {
                m_roots.insert (node -> CN_getParent () -> CN_getLeftChild ()) ;
                node -> CN_getParent () -> CN_setLeftChild (NULL) ;
                delete (node -> CN_getParent ()) ;
            }
        }
//        else
//        {
//            assert((new_ptr->getParent())->getParent()!=NULL);
//            std::set<csgNode *>::iterator it3 = roots.find((new_ptr->getParent())->getParent());
//            if(it3 != roots.end())//Cas général grand père qui est racine
//            {
//                removeNodeRec(new_ptr);
//                csgNode * Father = new_ptr->getParent();
//                csgNode * grandFather = (new_ptr->getParent())->getParent();
//                if(static_cast<csgOperation *>(new_ptr->getParent())->isLeft(new_ptr))
//                {
//                    if(static_cast<csgOperation *>(grandFather)->isLeft(Father))
//                    {
//                        static_cast<csgOperation *>(grandFather)->setLeft(static_cast<csgOperation *>(Father)->getRight());
//                        static_cast<csgOperation *>(Father)->setRight(NULL);
//                        delete Father;
//                    }
//                    else if(static_cast<csgOperation *>(grandFather)->isRight(Father))
//                    {
//                        static_cast<csgOperation *>(grandFather)->setRight(static_cast<csgOperation *>(Father)->getRight());
//                        static_cast<csgOperation *>(Father)->setRight(NULL);
//                        delete Father;
//                    }
//                    else
//                    {
//                        assert(0);
//                    }
//                }
//                else if(static_cast<csgOperation *>(new_ptr->getParent())->isRight(new_ptr))
//                {
//                    if(static_cast<csgOperation *>(grandFather)->isLeft(Father))
//                    {
//                        static_cast<csgOperation *>(grandFather)->setLeft(static_cast<csgOperation *>(Father)->getLeft());
//                        static_cast<csgOperation *>(Father)->setLeft(NULL);
//                        delete Father;
//                    }
//                    else if(static_cast<csgOperation *>(grandFather)->isRight(Father))
//                    {
//                        static_cast<csgOperation *>(grandFather)->setRight(static_cast<csgOperation *>(Father)->getLeft());
//                        static_cast<csgOperation *>(Father)->setLeft(NULL);
//                        delete Father;
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
//        }
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
