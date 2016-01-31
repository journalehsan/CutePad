#ifndef MAIN_WIN_H
#define MAIN_WIN_H
#include <QtWidgets/QtWidgets>
#include <QtCore/QDebug>
#include <QtGui/QIcon>
#include <QtCore/QObject>
#include "actions.h"
#include "main_menu.h"
class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QMainWindow *parent = 0);
    ~MainWin();
private:
    //QString strFileName; //for title name
    //TextBox
    QPlainTextEdit *plainTextEditor;
    //Layouts & Toolbar
     QToolBar *mainToolBar;
    //Actions
    QAction *actionOpenFile;
    QAction *actionNewFile;
    QAction *actionSaveFile;
    QAction *actionQuitApp;
    QAction *actionClose;
public:
    virtual QMenu *createPopupMenu();


private slots:
     void slotNewFile();
     void slotOpenFile();
     void slotSaveFile();
     void slotCloseFile();
    void slotQuitApp();
};
#endif //MAIN_WIN_H