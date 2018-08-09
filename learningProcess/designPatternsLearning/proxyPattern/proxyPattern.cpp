#include"proxyPattern.h"

Subject::Subject()
{

}

Subject::~Subject()
{
  printf("~Subject\n");
}

RealSubject::RealSubject()
{

}

RealSubject::~RealSubject()
{
  printf("~RealSubject\n");
}

void RealSubject::sailBook()
{
  printf("Selling books through a store！\n");
}

NetworkSailProxy::NetworkSailProxy()
{
  m_realStore = NULL;
  m_hadSailBooksN = 0;
}

NetworkSailProxy::~NetworkSailProxy()
{

}

void NetworkSailProxy::sailBook()
{
  if( NULL == m_realStore )
  {
    m_realStore = new RealSubject;
  }

  m_realStore->sailBook();
  m_hadSailBooksN += 1;
  talkSailBooksN();
}

void NetworkSailProxy::talkSailBooksN()
{
  printf("Good news, %d books have been sold.\n",m_hadSailBooksN);
}
