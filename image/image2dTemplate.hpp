/**
 * @file    image2dTemplate.hpp
 * @author  Isabelle Muller
 */


# ifndef IMAGE2DTEMPLATE_HPP
# define IMAGE2DTEMPLATE_HPP


template <typename T> Image2D <T>::Image2D () : Image <2 , T> ()
{
}

template <typename T> Image2D <T>::Image2D (const int x , const int y) :
    Image <2 , T> ()
{
    /************************ Mettre a jour la dimension. *************************/
    (* this).I_setDimension1 (x) ;
    (* this).I_setDimension2 (y) ;
    /******************************************************************************/
    if ((x * y) > 0) // S'il y a des pixels dans l'image.
    {
        (* this).m_image = new T [x * y] ; // Allouer la taille de l'image.
    }
    else // Image vide.
    {
        (* this).m_image = NULL ; // Il n'y a pas d'image.
    }
//    std::cout << "Image2D" << std::endl ;
}

template <typename T> Array <2 , int> Image2D <T>::I2D_getDimension () const
{
    return (* this).m_dimension ;
}

template <typename T> T * Image2D <T>::I2D_getImage () const
{
    return (* this).m_image ;
}

template <typename T> void Image2D <T>::I2D_setPixel (int i , int j , T color)
{
    assert (i >= 0) ;
    assert (i <= 1) ;
    assert (j >= 0) ;
    assert (j <= 1) ;
    this -> m_image [(i - 1) * (this -> m_dimension [1]) + j - 1] = color ;
}

template <typename T> T Image2D <T>::I2D_getPixel (int i , int j)
{
    return this -> m_image [(i - 1) * (this -> m_dimension [1]) + j - 1] ;
}


# endif
