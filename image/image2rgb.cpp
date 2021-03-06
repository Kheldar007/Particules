/**
 * @file    image2rgb.cpp
 * @author  Isabelle Muller
 */


# include "image2rgb.h"


Image2RGB::Image2RGB ()
{
}

void Image2RGB::I2RGB_loadFromPGM (const std::string & file) const
{
//    int widthPgm , heightPgm , maxPgm ;
//    std::ifstream * f = new std::ifstream ("test.pgm" /*file.c_str ()*/ , std::ifstream::in) ; // Ouvrir le fichier.
 //   f -> open ("test.pgm" , std::ifstream::in) ;

//    if (f -> is_open()) // Veririer s'il y a une erreur avec le fichier.
//    {
//        std::cout << "Yahoo" << std::endl ;
//        char char1 , char2 , c ;
//        std::string c1 = "" , c2 = "" , c3 = "" , cPix = "" ;
//        int pixel ;
//        f -> get (char1) ;
//        f -> get (char2) ;
//        f -> get (c) ;

//        // Magic number.
//        while (c == ' ' || c == '\n')
//        {
//            f -> get (c) ;
//        }
//        while (c != ' ' && c != '\n')
//        {
//            c1 += c ;
//            f -> get (c) ;
//        }

//        widthPgm = atoi (c1.c_str ()) ;
//        this -> m_dimension [0] = (widthPgm) ; // Largeur.
//        while (c == ' ' || c == '\n')
//        {
//            f -> get (c) ;
//        }

//        while (c != ' ' && c != '\n')
//        {
//            c2 += c ;
//            f -> get (c) ;
//        }
//        heightPgm = atoi (c2.c_str ()) ;
//        this -> m_dimension [1] = (heightPgm) ; // Hauteur.
//        while (c == ' ' || c == '\n')
//        {
//            f -> get (c) ;
//        }

//        // Valeur max.
//        while (c != ' ' && c != '\n')
//        {
//            c3 += c ;
//            f -> get (c) ;
//        }
//        while (c == ' ' || c == '\n')
//        {
//            f -> get (c) ;
//        }
//        maxPgm = atoi (c3.c_str ()) ;
//        if (maxPgm > 255)
//        {
//            exit (-1) ;
//        }

//        // Parcourir les pixels.
//        unsigned int red , green , blue ;
//        int i = 0 ;
//        while (i < this -> m_dimension [0] * this -> m_dimension [1])
//        {
//            while (c == ' ' || c == '\n' && (! f->eof ()))
//            {
//                f -> get (c) ;
//            }
//            while (c != ' ' && c != '\n' && (! f->eof ()))
//            {
//                cPix += c ;
//                f -> get (c) ;
//            }
//            pixel = atoi (cPix.c_str ()) ;
//            this -> m_image [i].r = red ;
//            this -> m_image [i].g = green ;
//            this -> m_image [i].b = blue ;
//            cPix = "" ;
//            i ++ ;
//        }
//    }
//    else
    {
        std::cerr << "I2G_loadFromPGM -> Le fichier ne s'est pas ouvert correctement." << std::endl ;
    }
}

void Image2RGB::I2RGB_saveToPGM (const std::string & file)
{
    std::ofstream out ;
    int cpt = 0 ;
    out.open ("out.pgm" /*file.c_str ()*/ , std::ofstream::out) ;
    if (out.is_open ())
    {
        out << "P2\n" ;
        out << this -> m_dimension [0] << " " << this -> m_dimension [1] << "\n" ;
        out << 255 << "\n" ;
        int i = 0 , j = 0 ;
        while (i < this -> m_dimension [1])
        {
            j = 0 ;
            while (j < this -> m_dimension [0])
            {
                out << (int) this -> m_image [cpt].r << " " << (int) this -> m_image [cpt].g
                    << " " << (int) this -> m_image [cpt].b << "  " ;
                cpt ++ ;
                j ++ ;
            }
            out << "\n" ;
            i ++ ;
        }
        out.close () ;
    }
    else
    {
        std::cerr << "I2G_saveToPGM -> Le fichier ne s'est pas ouvert correctement." << std::endl ;
    }
}

