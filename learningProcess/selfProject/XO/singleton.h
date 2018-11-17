#ifndef SINGLETON_H
#define SINGLETON_H

#include <QXmlStreamReader>
#include <QMutex>
#include <QFile>
#include <QMap>
#include <QString>
#include"commonType.h"
#include"commonMsg.h"

class Singleton
{
private:
    Singleton();
    ~Singleton();
public:
    Singleton* getInstance();
    void deleteInstance();

private:
    static Singleton*               m_pSingleton;
};

#endif // SINGLETON_H
