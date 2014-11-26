/**
 * @file    imageTemplate.hpp
 * @author  Isabelle Muller
 */


# ifndef IMAGETEMPLATE_HPP
# define IMAGETEMPLATE_HPP


template <int D , typename T> Image <D , T>::Image ()
{
    m_dimension = Array <D , int> () ; // Par defaut.
    m_image = NULL ; // Image vide.
}

template <int D , typename T>
    Image <D , T>::Image (const Array <D , int> dimension)
{
//    std::cout << "Image" << std::endl ;
    m_dimension = dimension ;
    int pixels = 1 ;
    int i = 0 ;
    while (i < D)
    {
        pixels *= dimension [i] ;
        i ++ ;
    }
    m_image = new T [pixels] ;
}

template <int D , typename T> Image <D , T>::~Image ()
{
    if (m_image != NULL) // Si le tableau est alloue.
    {
        delete [] m_image ; // Supprimer le tableau de donnees.
    }
}

template <int D , typename T> Array <D , int> Image <D , T>::I_getDimension () const
{
    return m_dimension ;
}

template <int D , typename T> T * Image <D , T>::I_getImage () const
{
    return m_image ;
}

template <int D , typename T>
    void I_swap (Image <D , T> & image1 , Image <D , T> & image2)
{
    std::swap (image1 , image2) ; // Echanger les pointeurs.
}


# endif
