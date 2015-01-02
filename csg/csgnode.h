/**
 * @file    csgnode.h
 * @author  Isabelle Muller
 */


# ifndef CSGNODE_H
# define CSGNODE_H


# include "boundingbox.h"
# include <cstdio>


/**
 * @brief CsgNode Un noeud.
 */
class CsgNode
{
    private :
        /**
         * @brief identifier L'identifiant du noeud.
         */
        int identifier ;
        /**
         * @brief parent Le noeud parent.
         */
        CsgNode * parent ;
        /**
         * @brief boundingBox
         */
        BoundingBox boundingBox ;

    public :
        /**
         * @brief CsgNode Constructeur vide.
         */
        CsgNode () ;
        /**
         * @brief CsgNode Constructeur.
         */
        CsgNode (int id , CsgNode * p) ;

        /**
         * @brief setBoundingBox Mutateur.
         * @param bb             Nouvelle bounding box.
         */
        void CN_setBoundingBox (BoundingBox bb) ;

        /**
         * @brief  CN_getParent Retourner le parent.
         * @return Le parent.
         */
        CsgNode * CN_getParent () ;
        /**
         * @brief  CN_getIdentifier Retourner l'identifiant'.
         * @return L'identifiant.
         */
        int CN_getIdentifier () ;
} ;


# endif
