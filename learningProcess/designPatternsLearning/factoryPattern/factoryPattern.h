#include "../designPatternLib.h"
/*
    继承类的构造函数
1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。

2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候,首先执行父类无参数的构造方法，然后执行自己的构造方法。

3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。

4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。

5. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。

6. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式.
*/

/*
              父类指针指向子类对象的析构问题
1.如果以一个基础类指针指向一个衍生类对象(派生类对象)，
  那么经由该指针只能访问基础类定义的函数（“实函数”暂且这么叫）
２．如果以一个衍生类指针指向一个基础类对象，必须先做强制转型动作（explicit cast），
    这种做法很危险，也不符合生活习惯，在程序设计上也会给程序员带来困扰。（一般不会这么去定义）
３．如果基础类和衍生类定义了相同名称的成员函数，那么通过对象指针调用成员函数时，
    到底调用那个函数要根据指针的原型来确定，而不是根据指针实际指向的对象类型确定。
４.虚拟函数就是为了对“如果你以一个基础类指针指向一个衍生类对象，那么通过该指针，
    你只能访问基础类定义的成员函数”这条规则反其道而行之的设计。
5.纯虚拟函数：virtual void myfunc ( ) =0;
  纯虚拟函数不许定义其具体动作，它的存在只是为了在衍生类钟被重新定义。
  只要是拥有纯虚拟函数的类，就是抽象类，它们是不能够被实例化的（只能被继承）。
  如果一个继承类没有改写父类中的纯虚函数，那么他也是抽象类，也不能被实例化。

                    得出结论
  析构函数本应该设置成虚函数。否则由上述第1条可知，
  在父类指针指向子类对象做对象销毁时，由于析构函数不是虚函数，则delete时，
  父类指针只能调用父类自己的析构函数，这就造成了上述对象部分销毁的错误状况。
*/

class Fruit
{
private:
public:
  Fruit();
  virtual ~Fruit();
  virtual void sayDetailFruitName() = 0;
};

class Apple : public Fruit
{
private:
public:
  Apple();
  virtual ~Apple();
  virtual void sayDetailFruitName();
};


class Banana : public Fruit
{
private:
public:
  Banana();
  virtual ~Banana();
  virtual void sayDetailFruitName();
};

class Factory
{
private:
public:
  Factory();
  virtual ~Factory();
  virtual Fruit* concreteDetaliFruit() = 0;
};

class ConreteApple:public Factory
{
private:
public:
  ConreteApple();
  virtual ~ConreteApple();
  virtual Fruit* concreteDetaliFruit();
};

class ConreteBanana:public Factory
{
private:
public:
  ConreteBanana();
  virtual ~ConreteBanana();
  virtual Fruit* concreteDetaliFruit();
};
