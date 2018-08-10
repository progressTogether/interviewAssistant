#include "../designPatternLib.h"

/*
为类A进行功能性增强的方法
１、直接修改类A的代码－－－不符合开闭原则
２、让类Ｂ继承类Ａ，给子类Ｂ添加函数，这样也可以扩充类Ａ的功能。
３、让类Ｃ包含类Ａ的对象（组合，关联）
４、

优势：

动态的给一个对象添加一些额外的职责。就增加功能来说，此模式比生成子类更为灵活。

装饰（ Decorator ）模式又叫做包装模式。
通过一种对客户端透明的方式来扩展对象的功能，是继承关系的一个替换方案。
	装饰模式就是把要添加的附加功能分别放在单独的类中，并让这个类包含它要装饰的对象，
  当需要执行时，客户端就可以有选择地、按顺序地使用装饰功能包装对象。

*/
class Car
{
public:
  Car();
  virtual ~Car();
  virtual void  displayCarTechnique() = 0;
private:
};

class RunableCar :public Car
{
public:
  RunableCar();
  ~RunableCar();
  virtual void  displayCarTechnique();
private:
};

class FlayingCar:public Car
{
public:
  FlayingCar(Car* car);
  ~FlayingCar();
  virtual void  displayCarTechnique();
private:
  Car* m_myCar;
};

class SwimingCar:public Car
{
public:
  SwimingCar(Car* car);
  ~SwimingCar();
  virtual void  displayCarTechnique();
private:
  Car* m_myCar;
};
