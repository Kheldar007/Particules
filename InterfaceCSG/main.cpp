#include <QApplication>
#include "mainwindow.h"
# include "image2grey.h"
# define DEBUG 1

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//     MainWindow w;
//     w.show();

    if (DEBUG) // Tests.
    {
        Image2Grey i (10 , 10) ;
        i.I2G_subsampling () ;
//        i.I2G_loadFromPGM ("test.pgm");
//        i.I2G_saveToPGM ("out.pgm") ;

        std::cerr << "\nDebug.\n" << std::endl ;
    }
    else
    {
        std::cerr << "\nThe game is on !\n" << std::endl ;
    }

//    return a.exec();
}
