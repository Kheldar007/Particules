/**
 * @file    csgtree.h
 * @author  Isabelle Muller
 */


# ifndef CSGTREE_H
# define CSGTREE_H


# include <algorithm>
# include "csgnode.h"
# include "image2grey.h"
# include <map>
# include <vector>


/**
 * @brief CsgTree Arbre.

Enlever un nœud et remettre ces 2 fils dans les racines
Swap fils droit/ fils gauche

 */
class CsgTree
{
    protected :

        /**
         * @brief roots Les racines.
         */
        std::vector <CsgNode *> m_roots ;
        /**
         * @brief leaves Les feuilles.
         */
        std::vector <CsgNode *> m_leaves ;
        /**
         * @brief m_map Une map permettant de retrouver un nœud (son adresse) a partir de son id (un entier).
         */
        std::map <int , CsgNode *> m_map ;

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
        CsgNode * CT_map (int id) ;
        /**
         * @brief CT_load Chargement.
         * @param format Le format du fichier.
         */
        void CT_load (std::string format) ;
        /**
         * @brief CT_save Sauvegarde.
         * @param format Le format du fichier.
         */
        void CT_save (std::string format) ;
        /**
         * @brief CT_draw Rendu du graphe dans une image a niveau de gris.
         * @param image L'image.
         */
        void CT_draw (const Image2Grey & image) ;
        /**
         * @brief  CT_clone Cloner un noeud.
         * @param  node Le noeud a cloner
         * @return Copie de node.
         */
        CsgNode * CT_clone (CsgNode * node) ;
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
