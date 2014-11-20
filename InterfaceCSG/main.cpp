#include <QApplication>
#include "mainwindow.h"
# include "arrayTemplate.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    /* Test */

    Array <2 , float> * b = new Array <2 , float> () ;

    /********/
	
	return a.exec();
}
