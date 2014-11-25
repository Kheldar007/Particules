#include <QApplication>
#include "mainwindow.h"
# include "vec2f.h"
# include "vec3f.h"
# define DEBUG 0

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG)
    {
        Vec2f v1 = Vec2f (1 , 2) ;
        Vec2f v2 = Vec2f (3 , 4) ;
    }
    else
    {
        std::cout << "Yeepyyy !" << std::endl ;
    }

//	return a.exec();
}
