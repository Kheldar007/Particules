/**
 * @file    csgtree.h
 * @author  Isabelle Muller
 */


# ifndef CSGTREE_H
# define CSGTREE_H


# include <algorithm>
# include "csgnode.h"
# include "csgoperation.h"
# include "csgprimitive.h"
# include "image2grey.h"
# include <map>
# include <set>


/**
 * @brief Sort Foncteur pour le tri.
 */
class Sort
{
    public :

        bool operator () (CsgNode * node1 , CsgNode * node2)
        {
            return (node1 -> CN_getIdentifier () < node2 -> CN_getIdentifier ()) ;
        }
} ;

/**
 * @brief CsgTree Arbre.
 */
class CsgTree
{
    protected :

        /**
         * @brief roots Les racines.
         */
        std::set <CsgNode * , Sort> m_roots ;
        /**
         * @brief leaves Les feuilles.
         */
        std::set <CsgNode * , Sort> m_leaves ;
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
         * @param image       L'image.
         * @param currentNode Le noeud courant.
         */
        void CT_draw (Image2Grey & image , CsgNode * currentNode) ;
        /**
         * @brief  CT_clone Cloner un noeud.
         * @param  node Le noeud a cloner
         * @return Copie de node.
         */
        CsgNode * CT_clone (int id) ;
        /**
         * @brief CT_deleteNode Enlever un noeud et remettre ses deux fils dans les racines.
         * @param id
         */
        void CT_deleteNode (int id) ;
        /**
         * @brief CT_swapSons Swap fils droit/fils gauche.
         * @param node Le noeud.
         */
        void CT_swapSons (CsgNode * node) ;
        /**
         * @brief CT_addPrimitive Ajouter une primitive.
         * @param primitive La primitive.
         */
        void CT_addPrimitive (CsgPrimitive * primitive) ;
        /**
         * @brief  CT_addOperation Ajouter une operation.
         * @param  operation L'operation.
         * @param  node1     Le premier fils.
         * @param  node2     Le deuxieme fils.
         * @return
         */
        CsgNode * CT_addOperation(Operation operation , CsgNode * node1 ,
            CsgNode * node2) ;
} ;


# endif
