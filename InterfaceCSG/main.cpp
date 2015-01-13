#include <QApplication>
#include "mainwindow.h"
# include "boundingbox.h"
# define DEBUG 1

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//     MainWindow w;
//     w.show();

    if (DEBUG) // Tests.
    {
        BoundingBox bb ;
        if (bb.BB_isEmpty())
        {
            std::cerr << "test" << std::endl ;
        }
        std::cout << "\nDebug.\n" << std::endl ;
    }
    else
    {
        std::cout << "\nThe game is on !\n" << std::endl ;
    }

//    return a.exec();
}
