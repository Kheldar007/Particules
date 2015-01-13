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
//    if (m_leaves.size () > 0) // S'il y a quelque chose dans l'arbre.
//    {
//        int i = 0 ;
//        Map m ; // Le foncteur.
//        m.id = id ;
//        while (i < m_leaves.size ()) // Parcourir les feuilles.
//        {
//            std::for_each (m_leaves.begin () , m_leaves.end () , m) ; // Chercher l'object contenant l'identifiant.

//            i ++ ;
//        }
//    }
    std::map <int , CsgNode *>::iterator i = m_map.find (id) ; // Trouver le noeud grace a son indice.
    return i -> second ;
}

void CsgTree::CT_load (std::string format)
{
}

void CsgTree::CT_save (std::string format)
{
}

void CsgTree::CT_treeToImage (const Image2Grey & image)
{
}
