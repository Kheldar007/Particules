#include <QApplication>
#include "mainwindow.h"
# include "arrayTemplate.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    /* Tests */

    Array <2 , float> b = Array <2 , float> () ;
    b [0] = 3.f ;
    b [1] = 1.f ;
    std::cout << "B = " ;
    b.A_print () ;

    /********/
	
	return a.exec();
}
