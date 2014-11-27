 #include <QApplication>
#include "mainwindow.h"
# include "image2grey.h"
# define DEBUG 1

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG) // Tests.
    {
        Image2Grey i (800 , 600) ;
        i.I2G_loadFromPGM("boat.pgm") ;
    }
    else
    {
        std::cout << "The game is on !" << std::endl ;
    }

//	return a.exec();
}
