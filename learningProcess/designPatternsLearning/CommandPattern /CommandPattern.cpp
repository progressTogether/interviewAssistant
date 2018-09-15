#include "CommandPattern.h"

/**********************************Fruit**************************************/


/********************************BananaCommand*********************************/
BananaCommand::BananaCommand(Vendor *v)
{
  m_pVendor = v;
}

BananaCommand::~BananaCommand()
{
}

Vendor* BananaCommand::getVendor()
{
  return m_pVendor;
}

void BananaCommand::setVendor(Vendor *v)
{
  m_pVendor = v;
}

void BananaCommand::sail()
{
  m_pVendor->sailBanana();
}
/*******************************AppleCommand**********************************/
AppleCommand::AppleCommand(Vendor *v)
{
  m_pVendor = v;
}

AppleCommand::~AppleCommand()
{
}

Vendor* AppleCommand::getVendor()
{
  return m_pVendor;
}

void AppleCommand::setVendor(Vendor *v)
{
  m_pVendor = v;
}

void AppleCommand::sail()
{
  m_pVendor->sailApple();
}
