#include"facadePattern.h"

void SubSystemA::doSomething()
{
  printf("SubSystemA is runing!\n");
}

void SubSystemB::doSomething()
{
  printf("SubSystemB is runing!\n");
}

void SubSystemC::doSomething()
{
  printf("SubSystemC is runing!\n");
}

Facade::Facade()
{
   m_subSysA = new SubSystemA;
   m_subSysB = new SubSystemB;
   m_subSysC = new SubSystemC;
}

Facade::~Facade()
{
  delete m_subSysA;
  delete m_subSysB;
  delete m_subSysC;
}

void Facade::doSomething()
{
  m_subSysA->doSomething();
  m_subSysB->doSomething();
  m_subSysC->doSomething();
}
