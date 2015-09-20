#ifndef ACTIONS_H
#define ACTIONS_H
#include <QtCore/QString>
#include <QTextStream>
#include <QFile>
class Actions{
    friend class MainWin;
public:
    QString actionOenFile(QString strFileName,const char strFileCodec[] = "UTF-8");
    bool actionSaveFile(QString strFileName,QString strFileCodec = "UTF-8");
    Actions();
    ~Actions();
private:
    QString globalFileName;
};

#endif //ACTIONS_H