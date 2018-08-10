#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-10
 *DISCTIPTION:  facade pattern demo.
 */

 /*
 Compile command :g++ main.cpp facadePattern.cpp -o facadePattern
 */


#define oldVersion
int main(int argc, char const *argv[])
{
#ifdef oldVersion
  printf("Not facade!\n");
  SubSystemA* subSysA = new SubSystemA;
  SubSystemB* subSysB = new SubSystemB;
  SubSystemC* subSysC = new SubSystemC;

  subSysA->doSomething();
  subSysB->doSomething();
  subSysC->doSomething();

  delete subSysA;
  delete subSysB;
  delete subSysC;
#else
  printf("Facade!\n");
  Facade* facade = NULL;

  facade = new Facade;
  facade->doSomething();

#endif

  return 0;
}
