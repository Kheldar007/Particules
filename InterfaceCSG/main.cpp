#include <QApplication>
#include "mainwindow.h"
# include "matrix33f.h"
# include "imageTemplate.h"
# define DEBUG 1

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG)
    {
//        Matrix33f matrix1 = Matrix33f (5.0f , 2.0f , 3.0f , 4.0f , 5.0f , 6.0f , 7.0f , 8.0f , 9.0f) ;
        Image <3 , float> i = Image <3 , float> () ;
    }
    else
    {
        std::cout << "Yeepyyy !" << std::endl ;
    }

//	return a.exec();
}
