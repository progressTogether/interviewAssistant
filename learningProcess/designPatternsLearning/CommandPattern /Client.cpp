#include "Client.h"

Command* Waiter::getCommand()
{
  return m_command;
}

void Waiter::setCommand(Command *c)
{
  m_command = c;
}

void Waiter::sail()
{
  m_command->sail();
}

AdvWaiter::AdvWaiter()
{
  m_pCommandL = new list<Command *>;
  m_pCommandL->resize(0);
}

AdvWaiter::~AdvWaiter()
{
  delete m_pCommandL;
}

void AdvWaiter::addINCommandL(Command *c)
{
  m_pCommandL->push_back(c);
}

list<Command *>* AdvWaiter::getCommandList()
{
  return m_pCommandL;
}

void AdvWaiter::sail()
{
  list<Command *>::iterator it = m_pCommandL->begin();
  for( ; it != m_pCommandL->end(); it++ )
  {
    (*it)->sail();
  }
}
