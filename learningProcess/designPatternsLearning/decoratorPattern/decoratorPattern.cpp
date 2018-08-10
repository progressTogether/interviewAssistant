#include"decoratorPattern.h"

Car::Car()
{

}

Car::~Car()
{
  printf("~Car\n");
}

/******************************RunableCar**************************************/

RunableCar::RunableCar()
{

}

RunableCar::~RunableCar()
{
  printf("~RunableCar\n");
}

void RunableCar::displayCarTechnique()
{
  printf("The car can run！\n");
}

/******************************FlayingCar**************************************/
FlayingCar::FlayingCar(Car* car)
{
  m_myCar = car;
}

FlayingCar::~FlayingCar()
{
  delete m_myCar;
  printf("~FlayingCar\n");
}

void FlayingCar::displayCarTechnique()
{
  m_myCar->displayCarTechnique();
  printf("The car can flay!\n");
}

/******************************SwimingCar**************************************/

SwimingCar::SwimingCar(Car* car)
{
  m_myCar = car;
}

SwimingCar::~SwimingCar()
{
  delete m_myCar;
  printf("~SwimingCar\n");
}

void SwimingCar::displayCarTechnique()
{
  m_myCar->displayCarTechnique();
  printf("The car can swim!\n");
}
