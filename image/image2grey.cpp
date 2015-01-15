/**
 * @file    image2grey.cpp
 * @author  Isabelle Muller
 */


# include "image2grey.h"


Image2Grey::Image2Grey () : IMAGE2GREY ()
{
}

Image2Grey::Image2Grey (const int x , const int y) : IMAGE2GREY (x , y)
{
}

void Image2Grey::I2G_loadFromPGM (const std::string & file)
{
   int widthPgm , heightPgm , maxPgm ;
   std::ifstream * f = new std::ifstream ("test.pgm" /*file.c_str ()*/ , std::ifstream::in) ; // Ouvrir le fichier.
//   f -> open ("test.pgm" , std::ifstream::in) ;

   if (f -> is_open()) // Verifier s'il y a une erreur avec le fichier.
   {
       std::cout << "Yahoo" << std::endl ;
       char char1 , char2 , c ;
       std::string c1 = "" , c2 = "" , c3 = "" , cPix = "" ;
       int pixel ;
       f -> get (char1) ;
       f -> get (char2) ;
       f -> get (c) ;

       // Magic number.
       while (c == ' ' || c == '\n')
       {
           f -> get (c) ;
       }
       while (c != ' ' && c != '\n')
       {
           c1 += c ;
           f -> get (c) ;
       }

       widthPgm = atoi (c1.c_str ()) ;
       this -> m_dimension [0] = (widthPgm) ; // Largeur.
       while (c == ' ' || c == '\n')
       {
           f -> get (c) ;
       }

       while (c != ' ' && c != '\n')
       {
           c2 += c ;
           f -> get (c) ;
       }
       heightPgm = atoi (c2.c_str ()) ;
       this -> m_dimension [1] = (heightPgm) ; // Hauteur.
       while (c == ' ' || c == '\n')
       {
           f -> get (c) ;
       }

       // Valeur max.
       while (c != ' ' && c != '\n')
       {
           c3 += c ;
           f -> get (c) ;
       }
       while (c == ' ' || c == '\n')
       {
           f -> get (c) ;
       }
       maxPgm = atoi (c3.c_str ()) ;
       if (maxPgm > 255)
       {
           exit (-1) ;
       }

       // Parcourir les pixels.
       int i = 0 ;
       while (i < this -> m_dimension [0] * this -> m_dimension [1])
       {
           while ((c == ' ' || c == '\n') && (! f->eof ()))
           {
               f -> get (c) ;
           }
           while (c != ' ' && c != '\n' && (! f->eof ()))
           {
               cPix += c ;
               f ->get (c) ;
           }
           pixel = atoi (cPix.c_str ()) ;
           this -> m_image [i] = pixel ;
           cPix = "" ;
           i ++ ;
       }
   }
   else
   {
       std::cerr << "I2G_loadFromPGM -> Le fichier ne s'est pas ouvert correctement." << std::endl ;
   }
}

void Image2Grey::I2G_saveToPGM (const std::string & file) const
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
               out << (int) this -> m_image [cpt] << "  " ;
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

            i ++ ;
        }
        j ++ ;
    }
    return result ;
}

Image2Grey Image2Grey::I2G_smoothing (int n) const
{
    Image2Grey result (this -> m_dimension [0] , this -> m_dimension [0]) ; // Construire l'image resultat.
    int k = 0 , i = 0 , j = 0 ;
    int average , average_t ;
    while (k < this -> m_dimension [0] * this -> m_dimension [1])
    {
        average = m_image [k] ;
        average_t = 0 ;
        i = k - n ;
        while (i < k + n)
        {
            j = k - n ;
            while (j < k + n)
            {
//                if ((j > 0) && (j == k % (i * this -> m_dimension [1])) && (i > 0) &&
//                    (i == k % (j * this -> m_dimension [0])) && (i != k))
                {
                    average += (int) m_image [j * this -> m_dimension [0] + i] ;
                    average_t ++ ;
                }

                j ++ ;
            }

            i ++ ;
        }

        result.m_image [k] = (unsigned char) (average / average_t) ;

        k ++ ;
    }

    return result ;
}

Image2Grey Image2Grey::I2G_thresholding (int threshold) const
{
    Image2Grey result (this -> m_dimension [0] , this -> m_dimension [0]) ; // Construire l'image resultat.

    int i = 0 ;
    while (i < this -> m_dimension [0] * this -> m_dimension [0])
    {
        if (this -> m_image [i] < threshold)
        {
            result.m_image [i] = 0 ; // Rien en-dessous de zero.
        }
        else if (this -> m_image [i] > threshold)
        {
            result.m_image [i] = 255 ; // Rien en-dessous de zero.
        }

        i ++ ;
    }

    return result ;
}
