/**
 * @file    array.h
 * @author  Isabelle Muller
 */


# ifndef ARRAY_H
# define ARRAY_H


/**
 * @class Array : template du nombre et du type d'elements.
 */
template <int N , typename T> class Array
{
    protected :
        /**
         * @brief m_data Donnee de type T.
         */
        T * m_data ;
        /**
         * @brief m_size Nombre d'elements.
         */
        int m_size ;
        /**
         * @brief s_nb Nombre d'objets.
         */
        static int s_nb ;
    public :
        /**
         * @brief Constructeur.
         */
        Array () ;
        /**
         * @brief Constructeur.
         * @param a Un Array.
         */
        Array (const Array <N , T> & a) ;
        /**
          * @brief Destructeur.
          */
        ~Array () ;
        /**
         * @brief  getSize Retourner la taille de l'Array.
         * @return m_size
         */
        int getSize () ;
        /**
         * @brief  getData Retourner l'Array.
         * @return m_data
         */
        T * getData () ;
        /**
         * @brief resize Modifier la taille.
         * @param size Nouvelle taille.
         */
        void resize (int size) ;
} ;


template <int N , typename T> Array <N , T>::Array () :
    m_data(NULL) , m_size (N)
{
    m_data = new T [N] ; // Allouer m_data de la taille N.
    s_nb ++ ; // Creer un objet de plus.
}
template <int N , typename T> Array <N , T>::Array (const Array <N , T> & a)
{
    assert (a.getSize () != 0) ; // Ne pas copier d'Array vide.
    m_size = a.getSize () ; // Nouvelle taille.
    m_data = new T [m_size] ; // Allouer l'Array.
    int i = 0 ;
    while (i < m_size)
    {
        m_data [i] = a.m_data [i] ; // Remplir l'Array avec les donnees.
        i ++ ;
    }
    s_nb ++ ; // Creer un objet de plus.
}
template <int N , typename T> Array <N , T>::~Array ()
{
    if (m_data != NULL) // Si le tableau est alloue.
    {
        delete [] m_data ; // Supprimer le tableau de donnees.
    }
    s_nb -- ; // Supprimer un objet.
}
template <int N , typename T> int Array <N , T>::getSize () const
{
    return m_size ;
}
template <int N , typename T> T * Array <N , T>::getData () const
{
    return m_data ;
}
template <int N , typename T> void Array <N , T>::resize (int size)
{
    assert (sz != 0) ; // La taille ne doit pas etre nulle.
    T * newData = new T [sz] ; // Nouveau tableau de la nouvelle taille.
    if (m_data != NULL) // Le vecteur ne doit pas être nul.
    {
        int minSize = std::min (m_size , sz) ; // Prendre la plus petite taille pour qu'il reste des choses a copier.
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


# endif
