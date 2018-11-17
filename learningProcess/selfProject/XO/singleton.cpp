#include "singleton.h"

QMutex mutex;

Singleton::Singleton()
{
    qDebug()<<"Create a singleton success!";
}

Singleton::~Singleton()
{
    qDebug()<<"Create a singleton success!";
}

Singleton* Singleton::m_pSingleton = NULL;

Singleton *Singleton::getInstance()
{
    if( NULL == m_pSingleton )
    {
        mutex.lock();
        if( NULL == m_pSingleton )
        {
            m_pSingleton = new Singleton;
        }
        mutex.unlock();
    }

    return m_pSingleton;
}

void Singleton::deleteInstance()
{

    if( NULL != m_pSingleton )
    {
        mutex.lock();
        if( NULL != m_pSingleton )
        {
            delete m_pSingleton;
            m_pSingleton = NULL;
        }
        mutex.unlock();
    }
}
