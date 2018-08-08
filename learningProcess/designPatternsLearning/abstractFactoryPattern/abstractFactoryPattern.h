#include "../designPatternLib.h"

class Fruit
{
private:
public:
  Fruit();
  virtual ~Fruit();
  virtual void sayDetailFruitName() = 0;
};

class SouthApple : public Fruit
{
private:
public:
  SouthApple();
  virtual ~SouthApple();
  virtual void sayDetailFruitName();
};


class SouthBanana : public Fruit
{
private:
public:
  SouthBanana();
  virtual ~SouthBanana();
  virtual void sayDetailFruitName();
};

class NorthApple : public Fruit
{
private:
public:
  NorthApple();
  virtual ~NorthApple();
  virtual void sayDetailFruitName();
};


class NorthBanana : public Fruit
{
private:
public:
  NorthBanana();
  virtual ~NorthBanana();
  virtual void sayDetailFruitName();
};


class Factory
{
private:
public:
  Factory();
  virtual ~Factory();
  virtual Fruit* concreteFruitOfBanana() = 0;
  virtual Fruit* concreteFruitOfApple() = 0;
};

class ConreteSouthFruit:public Factory
{
private:
public:
  ConreteSouthFruit();
  virtual ~ConreteSouthFruit();
  virtual Fruit* concreteFruitOfBanana();
  virtual Fruit* concreteFruitOfApple();
};

class ConreteNorthFruit:public Factory
{
private:
public:
  ConreteNorthFruit();
  virtual ~ConreteNorthFruit();
  virtual Fruit* concreteFruitOfBanana();
  virtual Fruit* concreteFruitOfApple();
};
