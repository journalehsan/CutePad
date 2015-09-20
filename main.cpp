#include <QtCore/QtCore>
#include "main_win.h"

int main(int argc, char *argv[])
{
   //setup application
   QApplication app(argc, argv);
   //execute app
   //show Windows
   MainWin *window;
   window = new MainWin();
   window->show();
   return app.exec();
}
