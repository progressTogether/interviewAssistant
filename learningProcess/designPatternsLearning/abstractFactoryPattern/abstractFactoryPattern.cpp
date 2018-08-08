#include "abstractFactoryPattern.h"

/**********************************Fruit**************************************/
Fruit::Fruit()
{

}

Fruit::~Fruit()
{
  printf("~Fruit\n");
}

/*******************************SouthApple*************************************/
SouthApple::SouthApple():Fruit()
{

}

SouthApple::~SouthApple()
{
  printf("~SouthApple\n");
}

void SouthApple::sayDetailFruitName()
{
  printf("I am an apple,from the south!\n" );
}

/********************************SouthBanana***********************************/
SouthBanana::SouthBanana():Fruit()
{

}

SouthBanana::~SouthBanana()
{
  printf("~SouthBanana\n");
}

void SouthBanana::sayDetailFruitName()
{
  printf("I am an banana,from the south!\n" );
}

/*******************************NorthApple*************************************/
NorthApple::NorthApple():Fruit()
{

}

NorthApple::~NorthApple()
{
  printf("~NorthApple\n");
}

void NorthApple::sayDetailFruitName()
{
  printf("I am an apple,from the North!\n" );
}

/********************************SouthBanana***********************************/
NorthBanana::NorthBanana():Fruit()
{

}

NorthBanana::~NorthBanana()
{
  printf("~NorthBanana\n");
}

void NorthBanana::sayDetailFruitName()
{
  printf("I am an banana,from the North!\n" );
}

/**********************************Factory*************************************/
Factory::Factory()
{

}

Factory::~Factory()
{
  printf("~Factory\n");
}

/*******************************ConreteSouthFruit******************************/
ConreteSouthFruit::ConreteSouthFruit():Factory()
{

}

ConreteSouthFruit::~ConreteSouthFruit()
{
  printf("~ConreteSouthFruit\n");
}

Fruit* ConreteSouthFruit::concreteFruitOfBanana()
{
  return new SouthBanana;
}

Fruit* ConreteSouthFruit::concreteFruitOfApple()
{
  return new SouthApple;
}

/*******************************ConreteNorthFruit******************************/
ConreteNorthFruit::ConreteNorthFruit():Factory()
{

}

ConreteNorthFruit::~ConreteNorthFruit()
{
  printf("~ConreteNorthFruit\n");
}

Fruit* ConreteNorthFruit::concreteFruitOfBanana()
{
  return new NorthBanana;
}

Fruit* ConreteNorthFruit::concreteFruitOfApple()
{
  return new NorthApple;
}
