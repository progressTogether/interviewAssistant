#include"bridgePattern.h"

Engine::Engine()
{

}

Engine::~Engine()
{
  printf("~Engine\n");
}

Engine4400c::Engine4400c()
{
}

Engine4400c::~Engine4400c()
{
  printf("~Engine4400c\n");
}

void Engine4400c::InstallEngine()
{
  printf("I am 4400c engine,Install finish！\n");
}

Engine4500c::Engine4500c()
{
}

Engine4500c::~Engine4500c()
{
  printf("~Engine4500c\n");
}

void Engine4500c::InstallEngine()
{
  printf("I am 4500c engine,Install finish for the car！\n");
}

/**********************************Car**************************************/
Car::Car( Engine* engine)
{
  m_myEngine = engine;
}

Car::~Car()
{
  printf("~Car\n");
}
/**********************************BMWCar**************************************/

BMWCar::BMWCar( Engine* engine):Car(engine)
{
  m_myEngine = engine;
}

BMWCar::~BMWCar()
{
  printf("~BMWCar\n");
}

void BMWCar::InstallEngine()
{
  printf("I am BMWCar,Ready install engine！\n");
  m_myEngine->InstallEngine();
}

/********************************RollsRoyce**************************************/

RollsRoyce::RollsRoyce( Engine* engine):Car(engine)
{
}

RollsRoyce::~RollsRoyce()
{
  printf("~RollsRoyce\n");
}

void RollsRoyce::InstallEngine()
{
  printf("I am RollsRoyce,Ready install engine！\n");
  m_myEngine->InstallEngine();
}
