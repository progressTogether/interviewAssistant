#include"prototypePattern.h"

Person::Person()
{

}

Person::~Person()
{
  printf("~Person\n");
}

CPlusPluseProgramer::CPlusPluseProgramer()
{
  m_personName = "noName";
  m_personAge = 0;
  m_personResume = new char[ strlen("nothing")];
  strcpy(m_personResume,"nothing");
}

CPlusPluseProgramer::CPlusPluseProgramer( string name, short age, char* resume )
{
  m_personName = name;
  m_personAge = age;
  m_personResume = new char[ strlen(resume) + 1];
  strcpy(m_personResume,resume);
}

CPlusPluseProgramer::~CPlusPluseProgramer()
{
  printf("~CPlusPluseProgramer\n");
}

Person* CPlusPluseProgramer::clone()
{
  CPlusPluseProgramer* tmp = new CPlusPluseProgramer;
  tmp->m_personName = this->m_personName;
  tmp->m_personAge = this->m_personAge;
  tmp->m_personResume = new char[ strlen(this->m_personResume)];
  strcpy(tmp->m_personResume,this->m_personResume);
  return tmp;
}

void CPlusPluseProgramer::outputPersonInfo()
{
  printf("person name is %s\n",m_personName.c_str());
  printf("person age is %d\n",m_personAge);
  printf("person resume is %s\n",m_personResume);
}
