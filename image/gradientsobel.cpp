/**
 * @file    gradientsobel.cpp
 * @author  Isabelle Muller
 */


# include "gradientsobel.h"


GradientSobel::GradientSobel (Image2Grey & image)
{
//    this -> m_dimension [0] = image.I2D_getDimension() [0] ;
//    this -> m_dimension [1] = image.I2D_getDimension() [1] ;

//    int gX [5][5] ;
//    int gY [5][5] ;

//    /****************************** Matrices Sobel. *******************************/

//    gX [0][0] = 1 ;
//    gX [0][1] = 2 ;
//    gX [0][2] = 0 ;
//    gX [0][3] = -2 ;
//    gX [0][4] = -1 ;

//    gX [1][0] = 4 ;
//    gX [1][1] = 8 ;
//    gX [1][2] = 0 ;
//    gX [1][3] = -8 ;
//    gX [1][4] = -4 ;

//    gX [2][0] = 6 ;
//    gX [2][1] = 12 ;
//    gX [2][2] = 0 ;
//    gX [2][3] = -12 ;
//    gX [2][4] = -6 ;

//    gX [3][0] = 4 ;
//    gX [3][1] = 8 ;
//    gX [3][2] = 0 ;
//    gX [3][3] = -8 ;
//    gX [3][4] = -4 ;

//    gX [4][0] = 1 ;
//    gX [4][1] = 2 ;
//    gX [4][2] = 0 ;
//    gX [4][3] = -2 ;
//    gX [4][4] = -1 ;

//    gY [0][0] = 1 ;
//    gY [0][1] = 4 ;
//    gY [0][2] = 6 ;
//    gY [0][3] = 4 ;
//    gY [0][4] = 1 ;

//    gY [1][0] = 2 ;
//    gY [1][1] = 8 ;
//    gY [1][2] = 12 ;
//    gY [1][3] = 8 ;
//    gY [1][4] = 2 ;
     
//    gY [2][0] = 0 ;
//    gY [2][1] = 0 ;
//    gY [2][2] = 0 ;
//    gY [2][3] = 0 ;
//    gY [2][4] = 0 ;
     
//    gY [3][0] = -2 ;
//    gY [3][1] = -8 ;
//    gY [3][2] = -12 ;
//    gY [3][3] = -8 ;
//    gY [3][4] = -2 ;
     
//    gY [4][0] = -1 ;
//    gY [4][1] = -4 ;
//    gY [4][2] = -6 ;
//    gY [4][3] = -4 ;
//    gY [4][4] = -1 ;

//    /******************************************************************************/

//    int k = 0 , i = 0 , j = 0 ;
//    float gI = 0.0 , gJ = 0.0 ;
//    int i_t = 0 , j_t = 0 ;
//    int count = 0 ;
//    while (k < this -> m_dimension [0] * m_dimension [1])
//    {
//        i = k - 2 ;
//        while (i < k + 2)
//        {
//            j = k - 2 ;
//            while (j < k + 2)
//            {
//                if ((j > 0) && (j == k % (i * this -> m_dimension [1])) && (i > 0) &&
//                    (i == k % (j * this -> m_dimension [0])))
//                {
//                    gI += (gX [i_t][j_t]) * (this -> m_image [j * (this -> m_dimension [0] + i)]) ;
//                    gJ += (gY [i_t][j_t]) * (this -> m_image [j * (this -> m_dimension [0] + j)]) ;
//                    count ++ ;
//                    j_t ++ ;
//                }
//                i_t ++ ;

//                j ++ ;
//            }

//            this -> m_image [k] = Vec2f (gI , gJ)) ;
//            gI = 0 ;
//            gJ = 0 ;
//            i_t = 0 ;
//            j_t = 0 ;
//            i ++ ;
//        }

//        k ++ ;
//    }
}
