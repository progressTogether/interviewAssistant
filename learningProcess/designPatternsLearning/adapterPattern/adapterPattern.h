#include "../designPatternLib.h"

/*
角色定义：

Current18v === target    这是客户所期待的接口。目标可以是具体的或抽象的类，也可以是接口。

Adapter ====== Adapter   通过在内部包装（Wrap）一个Adaptee对象，把源接口转换成目标接口。

Current220v == Adaptee   需要适配的类。

案例 Detail:
用户只接受18V的电压
现在只可以提供220V的电压
所以需要将 只可以提供220V的电压　　转换成   用户只接受18V的电压

具体实现 Detail
Adapter  继承于　　target　并拥有　　Adaptee的对象


Adapter模式也叫适配器模式，
  是构造型模式之一，通过Adapter模式可以改变已有类（或外部类）的接口形式。

适用于：
	是将一个类的接口转换成客户希望的另外一个接口。
  使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

*/
class Current18v
{
public:
  virtual ~Current18v();
	virtual void use18vCurrent();
protected:
private:
};

class Current220v
{
public:
	void use220vCurrent();
protected:
private:
};

class Adapter : public Current18v
{
public:
	Adapter(Current220v *p220v);
  ~Adapter();
	virtual void use18vCurrent();
protected:
private:
	Current220v *m_p220v;
};
