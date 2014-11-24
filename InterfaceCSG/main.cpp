#include <QApplication>
#include "mainwindow.h"
# include "vectorTemplate.h"

# define DEBUG 1

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if (DEBUG)
    {
        Vector <2 , float> b = Vector <2 , float> () ;
        b [0] = 9 ;
        b [1] = 5 ;
        b.A_print () ;

        Vector <2 , float> c = Vector <2 , float> () ;
        c [0] = 4 ;
        c [1] = 1 ;
        c.A_print () ;

        b -= c ;
        b.A_print () ;
    }

//	return a.exec();
}
