/**
 * @file    arrayTemplate.hpp
 * @author  Isabelle Muller
 */


# ifndef ARRAYTEMPLATE_HPP
# define ARRAYTEMPLATE_HPP


template <int N , typename T> int Array <N , T>::s_nb = 0 ; // Aucun objet cree pour le moment.


template <int N , typename T> Array <N , T>::Array () :
    m_data(new T [N]) , m_size (N)
{
    s_nb ++ ; // Creer un objet de plus.
//    std::cout << "Array." << std::endl ;
}

template <int N , typename T> Array <N , T>::Array (const Array <N , T> & a)
{
    assert (a.A_getSize () != 0) ; // Ne pas copier d'Array vide.
    m_size = a.A_getSize () ; // Nouvelle taille.
    m_data = new T [m_size] ; // Allouer l'Array.
    int i = 0 ;
    while (i < m_size)
    {
        m_data [i] = a [i] ; // Remplir l'Array avec les donnees.
        i ++ ;
    }
    s_nb ++ ; // Creer un objet de plus.
//    std::cout << "Array par copie." << std::endl ;
}

template <int N , typename T> Array <N , T>::~Array ()
{
    if (m_data != NULL) // Si le tableau est alloue.
    {
        delete [] m_data ; // Supprimer le tableau de donnees.
    }
    s_nb -- ; // Supprimer un objet.
//    std::cout << "Destructeur Array." << std::endl ;
}

template <int N , typename T> int Array <N , T>::A_getSize () const
{
    return m_size ;
}

template <int N , typename T> void Array <N , T>::A_resize (int size)
{
    assert (size != 0) ; // La taille ne doit pas etre nulle.
    T * newData = new T [size] ; // Nouveau tableau de la nouvelle taille.
    if (m_data != NULL) // Le vecteur ne doit pas être nul.
    {
        int minSize = std::min (m_size , size) ; // Prendre la plus petite taille pour qu'il reste des choses a copier.
        int i = 0 ;
        while (i < minSize)
        {
            newData [i] = m_data [i] ; // Copier les donnees dans le tableau de la bonne taille.
            i ++ ;
        }
        delete [] m_data ; // Supprimer les donnees.
    }
    m_data = newData ; // Copier les donnees dans le tableau.
    m_size = size ; // Conserver la nouvelle taille.
}

template <int N , typename T> T & Array <N , T>::operator [] (int i)
{
    return m_data [i] ; // Retourner la i-eme case.
}

template <int N , typename T> T const & Array <N , T>::operator [] (int i) const
{
    return m_data [i] ; // Retourner la i-eme case.
}

template <int N , typename T> Array <N , T> & Array <N , T>::operator = (const Array <N , T> & a)
{
    assert (m_size == a.A_getSize ()) ; // La taille du nouvel objet doit etre la meme que l'objet courant.
    int i = 0 ;
    while (i < m_size)
    {
        m_data [i] = a [i] ; // Copier les donnees de a dans l'objet courant.
        i ++ ;
    }
    return * this ;
}

template <int N , typename T> bool Array <N , T>::operator == (const Array <N , T> & a) const
{
    assert (m_size == a.A_getSize ()) ; // Si la taille est differente c'est faux.
    int i = 0 ;
    while (i < m_size) // Parcourir tous les elements du tableau.
    {
        if (m_data [i] != a [i]) // Si un element est different.
        {
            return false ;
        }
        i ++ ;
    }
    return true ; // Aucune erreur rencontree.
}

template <int N , typename T>
    void Array <N , T>::A_swap (Array <N , T> & a , Array <N , T> & b)
{
    std::swap (a , b) ; // Echanger les pointeurs.
}

template <int N , typename T> void Array <N , T>::A_print ()
{
    int i = 0 ;
    std::cout << "( " ;
    while (i < m_size) // Parcourir les elements du tableau.
    {
        std::cout << m_data [i] << " " ;
        i ++ ;
    }
    std::cout << ")" << std::endl ;
}


# endif
