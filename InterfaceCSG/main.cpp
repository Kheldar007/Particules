 #include <QApplication>
#include "mainwindow.h"
# include "image2dTemplate.h"
# define DEBUG 0

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG) // Tests.
    {
        Image2D <int> image (2 , 3) ;
        int * array = image.I2D_getImage();
    }
    else
    {
        std::cout << "The game is on !" << std::endl ;
    }

//	return a.exec();
}
