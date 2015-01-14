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

void CsgTree::CT_draw (const Image2Grey & image)
{
    std::vector <CsgNode *>::iterator it = m_roots.begin() ;
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
//                    if((*it1)->intersect(x, y))
//                    {
//                        p_image.setPixel(y, x, 255);
//                        //std::cout << "YES" << x << y << std::endl;
//                    } else
//                    {
//                        p_image.setPixel(y, x, 0);
//                        //std::cout << "NO" << x << y << std::endl;
//                    }
                }

                j ++ ;
            }

            i ++ ;
        }

        i ++ ;
    }
}

CsgNode * CsgTree::CT_clone (CsgNode * node)
{
    return new CsgNode (node -> CN_getIdentifier () , node -> CN_getParent ()) ;
}
