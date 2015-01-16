/**
 * @file    csgnode.h
 * @author  Isabelle Muller
 */


# ifndef CSGNODE_H
# define CSGNODE_H


# include "boundingbox.h"
# include "matrix33f.h"
# include "vec3f.h"
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

        Matrix33f m_position;
        Matrix33f m_rotation;
        Matrix33f m_scale;
        Matrix33f m_transform;

    public :

        static int countId ;
        /**
         * @brief CsgNode Constructeur vide.
         */
        CsgNode () ;
        virtual ~CsgNode () ;
        /**
         * @brief CsgNode Constructeur.
         */
        CsgNode (int id , CsgNode * p) ;

        /********************************* Mutateurs. *********************************/

        /**
         * @brief setBoundingBox Mutateur.
         * @param bb Nouvelle bounding box.
         */
        void CN_set_BB (BoundingBox & bb) ;
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
        /**
         * @brief set_position Mutateur.
         * @param m m_position
         */
        void CN_setPosition(Matrix33f &m);
        /**
         * @brief set_rotation Mutateur.
         * @param m m_rotation
         */
        void CN_setRotation(Matrix33f &m);
        /**
         * @brief set_scale Mutateur.
         * @param m m_scale
         */
        void CN_setScale(Matrix33f &m);

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
         * @brief  CN_getBoundingBox Retourner la boite englobante.
         * @return boundingBox
         */
        BoundingBox & CN_getBoundingBox () ;
        /**
         * @brief  get_transformation Retourner la matrice de transformation.
         * @return m_transform
         */
        Matrix33f CN_getTransformation();
        /**
         * @brief  get_position Retourner la matrice de position.
         * @return m_position
         */
        const Matrix33f& CN_getPosition();
        /**
         * @brief  get_rotation Retourner la matrice de rotation.
         * @return m_rotation
         */
        const Matrix33f& CN_getRotation();
        /**
         * @brief  get_scale Retourner la matrice d'homotethie.
         * @return m_scale
         */
        const Matrix33f& CN_getScale();

        /******************************************************************************/

        /**
         * @brief  intersect Intersect avec un point.
         * @param  v Le vecteur.
         * @return Vrai si intersection.
         */
        virtual bool intersect (Vec3f v) ;
        /**
         * @brief update_BB Mettre a jour la boite englobante.
         */
        virtual void update_BB () ;
} ;


# endif
