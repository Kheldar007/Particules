/**
 * @file    csgdisk.h
 * @author  Isabelle Muller
 */


# ifndef CSGDISK_H
# define CSGDISK_H


# include "csgprimitive.h"


/**
 * @brief CsgDisk Un disque.
 */
class CsgDisk : public CsgPrimitive
{
    public :

        /**
         * @brief CsgDisk Constructeur.
         */
        CsgDisk () ;

        /**
         * @brief ~CsgDisk Destructeur.
         */
        virtual ~CsgDisk () ;

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
