#include "../designPatternLib.h"

/*
角色定义：

Subject             抽象主体角色，抽象类或者接口，是一个普通的业务类型定义

RealSubject         具体主体角色，也叫作被委托角色，被代理角色。业务逻辑的具体执行者

NetworkSailProxy    代理主体角色，委托类，代理类。

优势：

代理模式最大的好处便是逻辑与实现的彻底解耦

*/
class Subject
{
public:
  Subject();
  virtual ~Subject();
  virtual void  sailBook() = 0;
  //virtual void outputPersonInfo() = 0;
private:
};

class RealSubject :public Subject
{
public:
  RealSubject();
  ~RealSubject();
  virtual void  sailBook();
private:
};

class NetworkSailProxy:public Subject
{
public:
  NetworkSailProxy();
  ~NetworkSailProxy();
  virtual void  sailBook();
  void talkSailBooksN();
private:
  RealSubject*  m_realStore;
  int           m_hadSailBooksN;
};
