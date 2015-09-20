#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QActionGroup>
class MainMenu : public QMenu
{
    Q_OBJECT
public:
    MainMenu(QWidget *parent = 0);
    ~MainMenu();
private:

};
#endif // MAIN_MENU_H