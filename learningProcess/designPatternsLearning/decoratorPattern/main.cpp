#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-10
 *DISCTIPTION:  decorator pattern demo.
 */

 /*
 Compile command :g++ main.cpp decoratorPattern.cpp -o decoratorPattern
 */



int main(int argc, char const *argv[])
{
  Car* myCar = NULL;
  myCar =  new RunableCar();
  myCar->displayCarTechnique();

  printf("------------------------------------------\n");
  myCar = new FlayingCar( myCar );
  myCar->displayCarTechnique();

  printf("------------------------------------------\n");
  myCar = new SwimingCar( myCar );
  myCar->displayCarTechnique();
  printf("------------------------------------------\n");
  delete myCar;
  return 0;
}
