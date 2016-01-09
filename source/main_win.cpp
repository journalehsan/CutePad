#include "main_win.h"
//Define Actions ad a instance
Actions *actionsInstance;
//Global Variables
//QString urlGlobalFilePath;
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
    //Tabs
    this->setDocumentMode(true);
    //connect actions to Actions Class's Functions
    QObject::connect(actionNewFile, SIGNAL(triggered(bool)), this, SLOT(slotNewFile()));
    QObject::connect(actionOpenFile, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()));
    QObject::connect(actionSaveFile, SIGNAL(triggered(bool)), this, SLOT(slotSaveFile()));
}
MainWin::~MainWin()
{

}

void MainWin::slotNewFile()
{
    //exec new option
    plainTextEditor->setPlainText("");
    plainTextEditor->setPlainText("New");
}

void MainWin::slotOpenFile()
{
    //exec open fuction
    actionsInstance = new Actions; //action define
    qDebug("Openning File.....");
    QString urlHomePath =  QDir::homePath(); //Home Folder
    //Open File Dialog
    QString filePath;
    filePath = QFileDialog::getOpenFileName(this,"Open Text File:",urlHomePath,"TXT Files(*.txt);;All Files(*.*)");
    //call open action
    if (filePath !="" || QFile::exists(filePath) ){
        QString strPlainData = actionsInstance->actionOenFile(filePath,"utf-8");
        plainTextEditor->setPlainText(strPlainData);
        //change title
        QFileInfo fileInfo(filePath);
        QString fileName(fileInfo.fileName());
        this->setWindowTitle(fileName);
        strFileName = fileName;
    }
    else{
        //cancel open file
        qDebug("Open File Canceled!");
        this->setWindowTitle(qApp->applicationName());
    }
}

void MainWin::slotSaveFile()
{
    //exec save function
    actionsInstance = new Actions;
    //define variables
    if (actionsInstance->actionSaveFile("strSFileName","strSFileCodec")){
        qDebug("File Saved!");
    }
}