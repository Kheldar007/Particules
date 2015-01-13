/**
 * @file    boundingbox.h
 * @author  Isabelle Muller
 */


# ifndef BOUNDINGBOX_H
# define BOUNDINGBOX_H


# include "vec2f.h"


/**
  * @class BoundingBox Boite englobante.
  */
class BoundingBox
{
    protected :

        /**
          * @brief xMin L'abscisse gauche.
          */
        float m_xMin ;
        /**
          * @brief xMax L'abscisse droite.
          */
        float m_xMax ;
        /**
          * @brief yMin L'ordonnee basse.
          */
        float m_yMin ;
        /**
          * @brief yMax L'ordonnee haute.
          */
        float m_yMax ;

    public :

        /**
          * @brief BoundingBox Constructeur vide.
          */
        BoundingBox () ;
        ~BoundingBox () ;

        /******************************** Accesseurs. *********************************/

        /**
          * @brief  BB_getXMin xMin.
          * @return Le cote gauche.
          */
        float BB_getXMin () ;
        /**
          * @brief  BB_getXMax xMax.
          * @return Le cote droit.
          */
        float BB_getXMax () ;
        /**
          * @brief  BB_getYMin yMin.
          * @return Le cote bas.
          */
        float BB_getYMin () ;
        /**
          * @brief  BB_getYMax yMax.
          * @return Le cote haut.
          */
        float BB_getYMax () ;

        /********************************* Mutateurs. *********************************/

        /**
         * @brief BB_setXMin Mutateur.
         * @param xMin Nouveau m_xMin.
         */
        void BB_setXMin (float xMin) ;
        /**
         * @brief BB_setXMax Mutateur.
         * @param xMax Nouveau m_xMax.
         */
        void BB_setXMax (float xMax) ;
        /**
         * @brief BB_setYMin Mutateur.
         * @param yMin Nouveau m_yMin.
         */
        void BB_setYMin (float yMin) ;
        /**
         * @brief BB_setYMax Mutateur.
         * @param yMax Nouveau m_yMax.
         */
        void BB_setYMax (float yMax) ;

        /****************** Operations entre les boites englobantes. ******************/

        /**
         * @brief  operator + Union.
         * @param  bb Une boite englobante.
         * @return Nouvelle boite englobante.
         */
        BoundingBox * operator + (BoundingBox * bb) ;
        /**
         * @brief  operator ^ Intersection.
         * @param  bb Une boite englobante.
         * @return Nouvelle boite englobante.
         */
        BoundingBox * operator ^ (BoundingBox * bb) ;
        /**
         * @brief  operator - Soustraction.
         * @param  bb Une boite englobante.
         * @return Nouvelle boite englobante.
         */
        BoundingBox * operator - (BoundingBox * bb) ;

        /******************************************************************************/

        /**
         * @brief  BB_isEmpty La boite est vide ou pas.
         * @return Vrai si elle est vide.
         */
        bool BB_isEmpty () ;
        /**
         * @brief  BB_center Le milieu de la boite.
         * @return Centre de la boite.
         */
        Vec2f * BB_center () ;
        /**
         * @brief  BB_isInside Tester si un point est situe a l'interieur de la boite.
         * @param  vector Le point.
         * @return Vrai s'il est dedans.
         */
        bool BB_isInside (const Vec2f & vector) ;
        /**
         * @brief BB_addVector Ajouter un point a la boite.
         * @param vector Le point a ajouter.
         */
        void BB_addVector (const Vec2f & vector) ;
} ;


# endif
