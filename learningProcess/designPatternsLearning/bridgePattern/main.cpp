#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-9
 *DISCTIPTION:  proxy pattern demo.
 */

 /*
 Compile command :g++ main.cpp bridgePattern.cpp -o bridgePattern
 */



int main(int argc, char const *argv[])
{
  Engine* myEngine = NULL;
  Car*    myCar = NULL;

  myEngine = new Engine4400c;
  myCar = new BMWCar(myEngine);
  myCar->InstallEngine();
  printf("---------------------\n");
  delete myEngine;
  delete myCar;
  printf("---------------------\n");
  myEngine = new Engine4500c;
  myCar = new RollsRoyce(myEngine);
  myCar->InstallEngine();
  printf("---------------------\n");
  delete myEngine;
  delete myCar;

  myEngine = NULL;
  myCar = NULL;
  return 0;
}
