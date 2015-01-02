/**
 * @file    csgtree.cpp
 * @author  Isabelle Muller
 */


# include "csgtree.h"


CsgTree::CsgTree ()
{
    leaves.clear () ;
    roots.clear () ;
}

CsgTree::~CsgTree ()
{
    leaves.clear () ;
    roots.clear () ;
}

CsgNode * CsgTree::map (int id)
{
    if (leaves.size () > 0) // S'il y a quelque chose dans l'arbre.
    {
        int i = 0 ;
        Map m ; // Le foncteur.
        m.id = id ;
        while (i < leaves.size ()) // Parcourir les feuilles.
        {
            std::for_each (leaves.begin () , leaves.end () , m) ; // Chercher l'object contenant l'identifiant.

            i ++ ;
        }
    }
}
