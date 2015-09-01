#include <QtCore/QtCore>
#include "main_win.h"

int main(int argc, char *argv[])
{
   //setup application
   QApplication app(argc, argv);
   //execute app
   //show Windows
   MainWin window;
   window.show();
   return app.exec();
}
