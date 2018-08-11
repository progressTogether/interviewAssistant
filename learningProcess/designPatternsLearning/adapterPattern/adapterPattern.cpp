#include"adapterPattern.h"

Current18v::~Current18v()
{
  printf("~Current18v！\n");
}

void Current18v::use18vCurrent()
{
  printf("Alternating current using 18V！\n");
}

void Current220v::use220vCurrent()
{
  printf("Alternating current using 220V！\n");
}

Adapter::Adapter(Current220v *p220v)
{
  m_p220v = p220v;
}

Adapter::~Adapter()
{
  printf("~Adapter\n");
}

void Adapter::use18vCurrent()
{
  printf("Using current in adapter！\n");
  m_p220v->use220vCurrent();
}
