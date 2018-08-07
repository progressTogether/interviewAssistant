#include "singleton.h"

pthread_mutex_t m_mutex;

singleton::singleton()
{
  printf("Create a singleton success!\n" );
  sleep(3);
}

singleton::~singleton()
{
  printf("Delete a singleton success!\n" );
}

singleton::singleton(const singleton& singleton)
{

}

singleton& singleton::operator=(const singleton&)
{

}

singleton* singleton::singletonConcrete = NULL;

/*饿汉模式
*优点，多线程安全
*缺点，资源浪费
*/
//singleton* singleton::singletonConcrete = new singleton;

//Double check
//first check :normal check.
//second check :thread safe,to avoid mutil thread creating mutil singleton.
singleton* singleton::getInstance()
{
  printf("懒汉模式的多线程!\n" );
  if( NULL == singletonConcrete )
  {
    pthread_mutex_lock( &m_mutex );
    if( NULL == singletonConcrete )
    {
      singletonConcrete = new singleton;
    }
    pthread_mutex_unlock( &m_mutex );
  }
  return singletonConcrete;
}
//deleteInstance
void singleton::deleteInstance()
{
  if( NULL != singletonConcrete )
  {
    delete singletonConcrete;
    singletonConcrete = NULL;
  }
}
