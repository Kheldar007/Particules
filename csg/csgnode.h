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
         * @brief m_identifier L'identifiant du noeud.
         */
        int m_identifier ;
        /**
         * @brief m_parent Le noeud parent.
         */
        CsgNode * m_parent ;
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

        /**
         * @brief setBoundingBox Mutateur.
         * @param bb             Nouvelle bounding box.
         */
        void CN_setBoundingBox (BoundingBox bb) ;

        /******************************** Accesseurs. *********************************/

        /**
         * @brief  CN_getParent Retourner le parent.
         * @return Le parent.
         */
        CsgNode * CN_getParent () ;
        /**
         * @brief  CN_getIdentifier Retourner l'identifiant.
         * @return L'identifiant.
         */
        int CN_getIdentifier () ;
        /**
         * @brief  CN_getBoundingBox Retourner la boite englobante.
         * @return m_boundingBox.
         */
        BoundingBox CN_getBoundingBox () ;
} ;


# endif
