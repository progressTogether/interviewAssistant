#ifndef _CommandPATTERN_H
#define _CommandPATTERN_H
#include "../designPatternLib.h"
#include "Receiver.h"
/*
命令模式
背景：在面向对象的程序设计中,一个对象调用另一个对象,
    一般情况下的调用过程是:创建目标对象实例;设置调用参数;调用目标对象的方法

定义：但在有些情况下有必要使用一个专门的类　对这种调用过程加以封装　,我们把这种专门的
    类称作 command 类　调用过程的封装

适用场景：调用过程比较繁杂、存在多处这种调用　
        使用 Command 类对该调用加以封装,便于功能的再利用
*/

class Command
{
public:
virtual void sail() = 0;
};

class BananaCommand: public Command
{
public:
  BananaCommand(Vendor *v);
  virtual ~BananaCommand();
  Vendor* getVendor();
  void setVendor(Vendor *v);
  virtual void sail();

protected:
private:
  Vendor *m_pVendor;
};

class AppleCommand: public Command
{
public:
  AppleCommand(Vendor *v);
  ~AppleCommand();
  Vendor* getVendor();
  void setVendor(Vendor *v);
  virtual void sail();

protected:
private:
  Vendor *m_pVendor;
};
#endif
