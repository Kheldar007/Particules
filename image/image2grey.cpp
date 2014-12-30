/**
 * @file    image2grey.cpp
 * @author  Isabelle Muller
 */


# include "image2grey.h"
#include <iostream>
#include <fstream>

Image2Grey::Image2Grey () : IMAGE2GREY ()
{
}

Image2Grey::Image2Grey (const int x , const int y) : IMAGE2GREY (x , y)
{
    std::cout << "Image2Grey" << std::endl ;
}

void Image2Grey::I2G_loadFromPGM (const std::string & file)
{
//    int widthPgm , heightPgm , maxPgm ;
//    std::ifstream f (file.c_str () , std::ios::in) ; // Ouvrir le fichier.
//    char char1 , char2 , c ;
//    std::string c1 = "" , c2 = "" , c3 = "" , cPix = "" ;
//    int pixel ;
//    f.get (char1) ;
//    f.get (char2) ;
//    f.get (c) ;

//    // Magic number.
//    while (c == ' ' || c == '\n')
//    {
//        f.get (c) ;
//    }
//    while (c != ' ' && c != '\n')
//    {
//        c1 += c ;
//        f.get (c) ;
//    }

//    // Longueur.
//    widthPgm = atoi (c1.c_str ()) ;
//    this -> m_dimension [0] = (widthPgm) ;
//    while (c == ' ' || c == '\n')
//    {
//        f.get (c) ;
//    }

//    // Hauteur.
//    while (c != ' ' && c != '\n')
//    {
//        c2 += c ;
//        f.get (c) ;
//    }
//    heightPgm = atoi (c2.c_str ()) ;
//    this -> m_dimension [1] = (heightPgm) ;
//    while (c == ' ' || c == '\n')
//    {
//        f.get (c) ;
//    }

//    // Valeur max.
//    while (c != ' ' && c != '\n')
//    {
//        c3 += c ;
//        f.get (c) ;
//    }
//    while (c == ' ' || c == '\n')
//    {
//        f.get (c) ;
//    }
//    maxPgm = atoi (c3.c_str ()) ;
//    if (maxPgm > 255)
//    {
//        exit (-1) ;
//    }

//    // Parcourir les pixels.
//    int i = 0 ;
//    while (i < this -> m_dimension [0] * this -> m_dimension [1])
//    {
//        while (c == ' ' || c == '\n' && (! f.eof ()))
//        {
//            f.get (c) ;
//        }
//        while (c != ' ' && c != '\n' && (! f.eof ()))
//        {
//            cPix += c ;
//            f.get (c) ;
//        }
//        pixel = atoi (cPix.c_str ()) ;
//        this -> m_image [i] = pixel ;
//        cPix = "" ;
//        i ++ ;
//    }


    std::ifstream f (file.c_str () , std::ios::in) ; // Ouvrir le fichier.
    if (! f) // Erreur a l'ouverture.
    {
        std::cerr << "Erreur lors de l'ouverture de \"" << file << "\"." << std::endl ;
    }
    else // L'ouverture a fonctionne.
    {
        std::string magic , line ;
        getline (f , magic) ;
        while ((f.peek () == '#') && (! f.eof ()))
        {
            getline (f , line) ;
        }
        unsigned int width , height ;
        f >> width >> height ;
        (* this).I_setDimension1 (width) ;
        (* this).I_setDimension2 (height) ;
        if ((width * height) > 0) // Si l'image n'est pas vide.
        {
            (* this).m_image = new unsigned char [width * height] ; // Allouer la taille de l'image.
        }
        else // Image vide.
        {
            (* this).m_image = NULL ; // Il n'y a pas d'image.
        }
        unsigned int maxValue ;
        f >> maxValue ;
        int i = 0 , j = 0 ;
        while (j < (* this).m_dimension [1])
        {
            i = 0 ;
            while (i < (* this).m_dimension [0])
            {
                unsigned int pixel ;
                f >> pixel ;
                (* this).m_image [i + (j * (* this).m_dimension [0])] =
                    (pixel * 255) / maxValue ;
                i ++ ;
            }
            j ++ ;
        }
        f.close () ; // Fermer le fichier.
    }
}

void Image2Grey::I2G_saveToPGM (const std::string & file) const
{
//    std::ofstream out ;
//    int cpt = 0 ;
//    out.open ("out.pgm") ;
//    out << "P2\n" ;
//    out << this -> m_dimension [0] << " " << this -> m_dimension [1] << "\n" ;
//    out << 255 << "\n" ;
//    int i = 0 , j = 0 ;
//    while (i < this -> m_dimension [1])
//    {
//        j = 0 ;
//        while (j < this -> m_dimension [0])
//        {
//            out << (int) this -> m_image [cpt] << "  " ;
//            cpt ++ ;
//            j ++ ;
//        }
//        out << "\n" ;
//        i ++ ;
//    }
//    out.close () ;

    std::ofstream f (file.c_str() , std::ios::out | std::ios::trunc) ; // Fichier en sortie.
    if (! f) // Si le fichier ne s'est pas bien ouvert.
    {
        std::cerr << "Erreur lors de la creation du fichier \"" << "\"." << std::endl ;
    }
    else
    {
        f << "P2" << std::endl ; // Inscrire le type.
        f << (* this).m_dimension [0] << " " << (* this).m_dimension [1] << std::endl ; // Inscrire les dimensions.
        f << "255" << std::endl ; // Inscrire la valeur maximale.
        int i = 0 , j = 0 ;
        while (j < (* this).m_dimension [1])
        {
            i = 0 ;
            while (i < (* this).m_dimension [0])
            {
                if (i)
                {
                    f << " " ;
                }
                f << " " << (unsigned) m_image [i] ;
                i ++ ;
            }
            j ++ ;
        }
    }
    f.close () ;
}

Image2Grey Image2Grey::I2G_subsampling () const
{
    int width = (* this).m_dimension [0] / 2 ;
    int height = (* this).m_dimension [1] / 2 ;
    Image2Grey result (width , height) ; // Construire l'image resultat.
    int i = 0 , j = 0 ;
    int oldPixel1 , oldPixel2 , oldPixel3 , oldPixel4 ;
    while (j < height)
    {
        i = 0 ;
        while (i < width)
        {
            oldPixel1 = (* this).m_image [(i * 2) + (j * (* this).m_dimension [0])] ;
        }
        j ++ ;
    }
}
