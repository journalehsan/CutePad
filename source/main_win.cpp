#include "main_win.h"
#include "actions.h"
#include "main_menu.h"
MainWin::MainWin(QMainWindow *parent)
: QMainWindow(parent){
    //setup windows widget
    this->setWindowTitle(qApp->applicationName());
    this->setWindowIcon(QIcon::fromTheme("accessories-text-editor"));
    this->setMinimumSize(820,650);
    //setup main and actions
    //File menu
    MainMenu *menuFile;
    menuFile = new MainMenu(this);
    menuFile->setTitle("File");
    this->menuBar()->addMenu(menuFile);
    //new action
    actionNewFile = new QAction(this);
    actionNewFile->setText("&New");
    actionNewFile->setIcon(QIcon::fromTheme("document-new"));
    menuFile->addAction(actionNewFile);
    //open action
    actionOpenFile = new QAction(this);
    actionOpenFile->setText("&Open");
    actionOpenFile->setIcon(QIcon::fromTheme("document-open"));
    menuFile->addAction(actionOpenFile);
    //save action
    actionSaveFile = new QAction(this);
    actionSaveFile->setText("&Save");
    actionSaveFile->setIcon(QIcon::fromTheme("document-save"));
    menuFile->addAction(actionSaveFile);

    //Text Editor for plain text
    plainTextEditor = new QPlainTextEdit(this);
    //tabs
    this->setDocumentMode(true);
    //centeral widget
    this->setCentralWidget(plainTextEditor);
    //Toolbar & Actions
    mainToolBar = new QToolBar(this);
    mainToolBar->addAction(actionNewFile);
    mainToolBar->addAction(actionOpenFile);
    mainToolBar->addAction(actionSaveFile);
    this->addToolBar(mainToolBar);
}
MainWin::~MainWin()
{

}