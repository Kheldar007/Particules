#include <QApplication>
#include "mainwindow.h"
# include "matrix33f.h"
# define DEBUG 0

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG)
    {
        Vec2f v1 = Vec2f (2, 3) ;
        Vec3f v2 = Vec3f (1 , 2, 3) ;
        Matrix33f m1 = Matrix33f (5.0f , 2.0f , 3.0f , 4.0f , 5.0f , 6.0f , 7.0f , 8.0f , 9.0f) ;
        m1.M_getColumn1().A_print();
        m1.M_getColumn2().A_print();
        m1.M_getColumn3().A_print();
        Vec3f v3 = m1 * v2 ;
        v3.A_print();
    }
    else
    {
        std::cout << "Yeepyyy !" << std::endl ;
    }

//	return a.exec();
}
