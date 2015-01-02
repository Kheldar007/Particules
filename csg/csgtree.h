/**
 * @file    csgtree.h
 * @author  Isabelle Muller
 */


# ifndef CSGTREE_H
# define CSGTREE_H


# include <algorithm>
# include "csgnode.h"
# include <vector>


class CsgTree
{
    private :
        /**
         * @brief leaves Les feuilles.
         */
        std::vector <CsgNode *> leaves ;
        /**
         * @brief roots Les racines.
         */
        std::vector <CsgNode *> roots ;

    public :
        /**
         * @brief CsgTree Constructeur vide.
         */
        CsgTree () ;

        /**
         * ~CsgTree Destructeur.
         */
        ~CsgTree () ;

        /**
         * @brief  map Retrouver un noeud par son identifiant.
         * @param  id  L'identifiant du noeud.
         * @return Le noeud d'identifiant id.
         */
        CsgNode * map (int id) ;
} ;

class Map
{
    public :

        int id ;

        CsgNode * operator () (CsgNode * node)
        {
            CsgNode * node_t = node ; // Pour remonter l'arbre.
            while (node_t != NULL) // Examiner chaque noeud de l'arbre.
            {
                if (node_t -> CN_getIdentifier () == id) // On a trouve le noeud.
                {
                    return node_t ; // Le noeud est trouve.
                }

                node_t = node_t -> CN_getParent () ; // Remonter dans l'arbre.
            }
            return NULL ;
        } ;
} ;


# endif
