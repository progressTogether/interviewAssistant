#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-9
 *DISCTIPTION:  prototype pattern demo.
 */

 /*
 Compile command :g++ main.cpp prototypePattern.cpp -o prototypePattern
 */



int main(int argc, char const *argv[])
{
  Person* personA = NULL;
  Person* personB = NULL;

  personA = new CPlusPluseProgramer;
  personA->outputPersonInfo();

  personB = personA->clone();
  personB->outputPersonInfo();
  delete personA;
  delete personB;

  printf("\n");
  char* tmpName = NULL;
  tmpName = new char[ strlen("Excelent c plus plus programer")];
  strcpy(tmpName,"Excelent c plus plus programer");
  personA = new CPlusPluseProgramer("lihua",26,tmpName);
  delete tmpName;
  personA->outputPersonInfo();

  personB = personA->clone();
  personB->outputPersonInfo();
  delete personA;
  delete personB;
  personA = NULL;
  personB = NULL;
  
  return 0;
}
