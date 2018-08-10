#include "../designPatternLib.h"


class SubSystemA
{
public:
  void doSomething();
};

class SubSystemB
{
public:
  void doSomething();
};

class SubSystemC
{
public:
  void doSomething();
};

class Facade
{
public:
    Facade();
    ~Facade();
    void doSomething();
private:
  SubSystemA* m_subSysA;
  SubSystemB* m_subSysB;
  SubSystemC* m_subSysC;
};
