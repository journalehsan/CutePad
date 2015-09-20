#include "actions.h"
#include "main_win.h"
#include <QObject>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
QString Actions::actionOenFile(QString strFileName, const char strFileCodec[])
{
    qDebug("Open Action Called!");
   //define qfile
    QFile flOpenedFileName(strFileName);
    //check read only
    if (!flOpenedFileName.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug("Read Only");
    }
    //Open from text stream
    QTextStream txtStreamOpen(&flOpenedFileName);
    txtStreamOpen.setCodec(strFileCodec);
    QString fileData = txtStreamOpen.readAll();
    //flush
    flOpenedFileName.flush();
    flOpenedFileName.close();
    return fileData; //return data to output
}

bool Actions::actionSaveFile(QString strFileName, QString strFileCodec)
{
    qDebug("Save Action Called!");
}

Actions::Actions(){
    qDebug("Actions started!");
}
Actions::~Actions(){
    qDebug("Actions gone!");
}
