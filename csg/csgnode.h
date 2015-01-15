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
    protected :

        /**
         * @brief m_identifier L'identifiant du noeud.
         */
        int m_identifier ;
        /**
         * @brief m_parent Le noeud parent.
         */
        CsgNode * m_parent ;
        /**
         * @brief m_leftChild Fils gauche.
         */
        CsgNode * m_leftChild ;
        /**
         * @brief m_rightChild Fils droit.
         */
        CsgNode * m_rightChild ;
        /**
         * @brief m_boundingBox
         */
        BoundingBox m_boundingBox ;

    public :

        /**
         * @brief CsgNode Constructeur vide.
         */
        CsgNode () ;
        /**
         * @brief CsgNode Constructeur.
         */
        CsgNode (int id , CsgNode * p) ;

        /********************************* Mutateurs. *********************************/

        /**
         * @brief setBoundingBox Mutateur.
         * @param bb Nouvelle bounding box.
         */
        void CN_set_BB (BoundingBox bb) ;
        /**
         * @brief CN_setParent Mutateur.
         * @param node m_parent
         */
        void CN_setParent (CsgNode * node) ;
        /**
         * @brief CN_setLeftChild Mutateur.
         * @param node m_leftChild
         */
        void CN_setLeftChild (CsgNode * node) ;
        /**
         * @brief CN_setRightChild Mutateur.
         * @param node m_rightChild
         */
        void CN_setRightChild (CsgNode * node) ;

        /******************************** Accesseurs. *********************************/

        /**
         * @brief  CN_getIdentifier Retourner l'identifiant.
         * @return L'identifiant.
         */
        int CN_getIdentifier () ;
        /**
         * @brief  CN_getParent Retourner le parent.
         * @return Le parent.
         */
        CsgNode * CN_getParent () ;
        /**
         * @brief  CN_getLeftChild Retourner le fils gauche.
         * @return m_leftChild
         */
        CsgNode * CN_getLeftChild () ;
        /**
         * @brief  CN_getRightChild Retourner le fils droit.
         * @return m_rightChild
         */
        CsgNode * CN_getRightChild () ;
        /**
         * @brief  get_local_BB Retourner la boite englobante.
         * @return m_boundingBox.
         */
        BoundingBox get_local_BB () ;
        virtual BoundingBox get_BB () ;
} ;


# endif
