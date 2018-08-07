#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-7
 *DISCTIPTION:  factory pattern demo.
 */

 /*
 Compile command :g++ main.cpp factoryPattern.cpp -o factory
 */

int main(int argc, char const *argv[])
{
  Fruit* detailFruit;
  Factory* detailFactory;

  detailFactory = new ConreteApple;
  detailFruit = detailFactory->concreteDetaliFruit();
  detailFruit->sayDetailFruitName();

  detailFactory = new ConreteBanana;
  detailFruit = detailFactory->concreteDetaliFruit();
  detailFruit->sayDetailFruitName();

  delete detailFruit;
  delete detailFactory;

  detailFruit = NULL;
  detailFactory = NULL;

  return 0;
}
