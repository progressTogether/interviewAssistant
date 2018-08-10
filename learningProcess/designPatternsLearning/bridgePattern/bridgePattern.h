#include "../designPatternLib.h"

class Engine
{
public:
  Engine();
  virtual ~Engine();
  virtual void  InstallEngine() = 0;
private:
};

class Engine4400c:public Engine
{
public:
  Engine4400c();
  virtual ~Engine4400c();
  virtual void  InstallEngine();
private:
};

class Engine4500c:public Engine
{
public:
  Engine4500c();
  virtual ~Engine4500c();
  virtual void  InstallEngine();
private:
};

class Car
{
public:
  Car( Engine* engine);
  virtual ~Car();
  virtual void InstallEngine() = 0;
protected:
  Engine* m_myEngine;
};

class BMWCar :public Car
{
public:
  BMWCar(Engine* engine);
  ~BMWCar();
  virtual void InstallEngine();
private:
  Engine* m_myEngine;
};

class RollsRoyce :public Car
{
public:
  RollsRoyce(Engine* engine);
  ~RollsRoyce();
  virtual void InstallEngine();
private:
};
