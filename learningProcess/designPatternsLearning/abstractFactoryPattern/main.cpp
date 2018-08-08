#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-8
 *DISCTIPTION:  abstract factory pattern demo.
 */

 /*
 Compile command :g++ main.cpp abstractFactoryPattern.cpp -o abstractFactory
 */

/*
  工厂模式：生产苹果、香蕉、梨，但是不能同时生产一个产品组
  抽象工厂：能同时生产一个产品组＝＝＝＝》》抽象工厂存在的原因

  具体案例解释
  工厂模式：　在开闭原则下　能生产　香蕉/梨/苹果
  抽象工厂：　在开闭原则下　能生产　南方　香蕉/梨/苹果
                        能生产　北方　香蕉/梨/苹果

  工厂模式只能生产一个产品
  抽象工厂可以生产一个产品族
*/
int main(int argc, char const *argv[])
{
  Fruit* detailFruit;
  Factory* detailFactory;

  detailFactory = new ConreteSouthFruit;
  detailFruit = detailFactory->concreteFruitOfBanana();
  detailFruit->sayDetailFruitName();
  delete detailFruit;

  detailFruit = detailFactory->concreteFruitOfApple();
  detailFruit->sayDetailFruitName();

  delete detailFruit;
  delete detailFactory;

  printf("\n");

  detailFactory = new ConreteNorthFruit;
  detailFruit = detailFactory->concreteFruitOfBanana();
  detailFruit->sayDetailFruitName();
  delete detailFruit;

  detailFruit = detailFactory->concreteFruitOfApple();
  detailFruit->sayDetailFruitName();

  delete detailFruit;
  delete detailFactory;

  detailFruit = NULL;
  detailFactory = NULL;

  return 0;
}
