#include <QApplication>
#include "mainwindow.h"
# include "image2grey.h"
# define DEBUG 0

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG) // Tests.
    {
        Image2Grey i ;
        i.I2G_loadFromPGM ("test.pgm");
        i.I2G_saveToPGM ("out.pgm") ;
    }
    else
    {
        std::cout << "\nThe game is on !\n" << std::endl ;
    }

//	return a.exec();
}
