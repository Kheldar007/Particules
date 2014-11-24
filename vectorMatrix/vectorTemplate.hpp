/**
 * @file    vectorTemplate.hpp
 * @author  Isabelle Muller
 */


# ifndef VECTORTEMPLATE_HPP
# define VECTORTEMPLATE_HPP


template <int N , typename T> Vector <N , T>::Vector () : Array <N , T> ()
{
//    std::cout << "Vector." << std::endl ;
}

template <int N , typename T>
    Vector <N , T>::Vector (const Vector <N , T> & v) : Array <N , T> (v)
{
//    std::cout << "Vector par copie." << std::endl ;
}

template <int N , typename T> Vector <N , T>::~Vector ()
{
//    std::cout << "Destructeur Vector." << std::endl ;
}

template <int N , typename T> Vector <N , T>
    Vector <N , T>::operator + (const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de l'addition.
    int i = 0 ;
    while (i < N)
    {
        result [i] = (* this) [i] + v [i] ; // Effectuer l'addition.
        i ++ ;
    }
    return result ;
}

template <int N , typename T> Vector <N , T>
    Vector <N , T>::operator - (const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la soustraction.
    int i = 0 ;
    while (i < N)
    {
        result [i] = (* this) [i] - v [i] ; // Effectuer la soustraction.
        i ++ ;
    }
    return result ;
}

template <int N , typename T> Vector <N , T> &
    Vector <N , T>::operator += (const Vector <N , T> & v)
{
    int i = 0 ;
    while (i < N)
    {
        (* this) [i] += v [i] ; // Effectuer l'addition.
        i ++ ;
    }
    return * this ; // Retourner le resultat de l'addition.
}

template <int N , typename T> Vector <N , T> &
    Vector <N , T>::operator -= (const Vector <N , T> & v)
{
    int i = 0 ;
    while (i < N)
    {
        (* this) [i] -= v [i] ; // Effectuer l'addition.
        i ++ ;
    }
    return * this ; // Retourner le resultat de l'addition.
}

template <int N , typename T> Vector <N , T>
    Vector <N , T>::operator * (const T scalar)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la soustraction.
    int i = 0 ;
    while (i < N)
    {
        result [i] = (* this) [i] * scalar ; // Effectuer la soustraction.
        i ++ ;
    }
    return result ;
}

template <int N , typename T> Vector <N , T>
    Vector <N , T>::operator / (const T scalar)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la soustraction.
    int i = 0 ;
    while (i < N)
    {
        result [i] = (* this) [i] / scalar ; // Effectuer la soustraction.
        i ++ ;
    }
    return result ;
}

template <int N , typename T> Vector <N , T> &
    Vector <N , T>::operator *= (const T scalar)
{
    int i = 0 ;
    while (i < N)
    {
        (* this) [i] *= scalar ; // Effectuer l'addition.
        i ++ ;
    }
    return * this ; // Retourner le resultat de l'addition.
}

template <int N , typename T> Vector <N , T> &
    Vector <N , T>::operator /= (const T scalar)
{
    int i = 0 ;
    while (i < N)
    {
        (* this) [i] /= scalar ; // Effectuer l'addition.
        i ++ ;
    }
    return * this ; // Retourner le resultat de l'addition.
}

template <int N , typename T> Vector <N , T>
    operator + (const T & t  , const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de l'addition.
    int i = 0 ;
    while (i < N)
    {
        result [i] = t + v [i] ; // Effectuer l'addition.
        i ++ ;
    }
    return result ; // Retourner le resultat de l'addition.
}

template <int N , typename T> Vector <N , T>
    operator - (const T & t  , const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la soustraction.
    int i = 0 ;
    while (i < N)
    {
        result [i] = t - v [i] ; // Effectuer la soustraction.
        i ++ ;
    }
    return result ; // Retourner le resultat de la soustraction.
}

template <int N , typename T> Vector <N , T>
    operator * (const T & t  , const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la multiplication.
    int i = 0 ;
    while (i < N)
    {
        result [i] = t * v [i] ; // Effectuer la multiplication.
        i ++ ;
    }
    return result ; // Retourner le resultat de la multiplication.
}

template <int N , typename T> Vector <N , T>
    operator / (const T & t  , const Vector <N , T> & v)
{
    Vector <N , T> result = Vector <N , T> () ; // Resultat de la division.
    int i = 0 ;
    while (i < N)
    {
        result [i] = t / v [i] ; // Effectuer la division.
        i ++ ;
    }
    return result ; // Retourner le resultat de la division.
}


# endif
