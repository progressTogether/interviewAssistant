#ifndef _CLIENT_H
#define _CLIENT_H
#include "../designPatternLib.h"
#include "CommandPattern.h"
#include <list>

class Waiter
{
public:
  Command* getCommand();
  void setCommand(Command *c);
  void sail();

protected:
private:
  Command *m_command;
};

class AdvWaiter
{
public:

  AdvWaiter();
  ~AdvWaiter();

  void addINCommandL(Command *c);
  list<Command *>* getCommandList();
  void sail();

protected:
private:
  list<Command *> *m_pCommandL;
};
#endif
