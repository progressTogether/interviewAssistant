#include "../designPatternLib.h"

class Person
{
public:
  Person();
  virtual ~Person();
  virtual Person* clone() = 0;
  virtual void outputPersonInfo() = 0;
private:
};

class CPlusPluseProgramer :public Person
{
public:
  CPlusPluseProgramer();
  CPlusPluseProgramer( string name, short age, char* resume );
  ~CPlusPluseProgramer();
  virtual Person* clone();
  virtual void outputPersonInfo();
private:
  string  m_personName;
  short   m_personAge;
  char*   m_personResume;
};
