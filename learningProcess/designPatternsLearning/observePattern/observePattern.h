#include "../designPatternLib.h"
#include <list>
/*
角色定义：

Student             抽象主体角色，所有对通知感兴趣的类都需要继承该类

LoveLolPlayer、LoveNovalReader 、LoveChating
具体角色，收到消息执行动作

Monitor             观察者，负责将消息通知给每个感兴趣的　对象

优势：

观察者模式最大的好处
  １、可以将消息打包发给所有人，实现了消息发送者和接受者的解绑
  ２、可以动态的决定是否对消息感兴趣

具体的业务场景
  班长（Monitor）时刻在观察　　老师是否　来了（或者走了），一旦收到消息，班长马上通知给所有学生
  学生收到给消息决定做相应的事情。
  所有的学生都可以动态的决定是否接受班长发的消息。
*/
class Student
{
public:
  Student();
  virtual ~Student();
  virtual void  doingSomething() = 0;
  virtual void  stopingDoing() = 0;
private:
};

class LoveLolPlayer :public Student
{
public:
  LoveLolPlayer();
  virtual ~LoveLolPlayer();
  virtual void  doingSomething();
  virtual void  stopingDoing();
private:
};

class LoveNovalReader:public Student
{
public:
  LoveNovalReader();
  virtual ~LoveNovalReader();
  virtual void  doingSomething();
  virtual void  stopingDoing();
private:
};

class LoveChating:public Student
{
public:
  LoveChating();
  virtual ~LoveChating();
  virtual void  doingSomething();
  virtual void  stopingDoing();
private:
};

class Monitor
{
public:
  Monitor();
  ~Monitor();
  //将消息通知给大家
  void notificationStudent(bool status);
  //提供对该消息感兴趣的注册接口
  void registerNotification( Student* stu);
  //提供对该消息不该感兴趣的反注册接口
  bool anti_registerNotification( Student* stu );
private:
  list<Student*> *m_pStudentList;
};
