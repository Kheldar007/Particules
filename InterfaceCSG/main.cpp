#include <QApplication>
#include "mainwindow.h"
# include "../csg/boundingbox.h"
# define DEBUG 0

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//     MainWindow w;
//     w.show();

    if (DEBUG) // Tests.
    {
        std::cout << "\nDebug.\n" << std::endl ;
    }
    else
    {
        std::cout << "\nThe game is on !\n" << std::endl ;
    }

//    return a.exec();
}
