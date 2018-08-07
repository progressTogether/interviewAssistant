#include "factoryPattern.h"

/**********************************Fruit**************************************/
Fruit::Fruit()
{

}

Fruit::~Fruit()
{
  printf("~Fruit\n");
}

/**********************************Apple**************************************/
Apple::Apple():Fruit()
{

}

Apple::~Apple()
{
  printf("~Apple\n");
}

void Apple::sayDetailFruitName()
{
  printf("I am an apple!\n" );
}

/**********************************banana*************************************/
Banana::Banana():Fruit()
{

}

Banana::~Banana()
{
  printf("~Banana\n");
}

void Banana::sayDetailFruitName()
{
  printf("I am an banana!\n" );
}

/**********************************Factory*************************************/
Factory::Factory()
{

}

Factory::~Factory()
{
  printf("~Factory\n");
}

/*********************************ConreteApple*********************************/
ConreteApple::ConreteApple():Factory()
{

}

ConreteApple::~ConreteApple()
{
  printf("~ConreteApple\n");
}

Fruit* ConreteApple::concreteDetaliFruit()
{
  return new Apple;
}

/*********************************ConreteBanana********************************/
ConreteBanana::ConreteBanana():Factory()
{

}

ConreteBanana::~ConreteBanana()
{
  printf("~ConreteBanana\n");
}

Fruit* ConreteBanana::concreteDetaliFruit()
{
  return new Banana;
}
