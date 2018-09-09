#include"chainOfResponsibility.h"

SoftCompany::SoftCompany()
{

}

SoftCompany::~SoftCompany()
{
  printf("~SoftCompany\n");
}
/******************************CustomerService**********************************/

CustomerService::CustomerService()
{

}
CustomerService::~CustomerService()
{
  if ( NULL != m_pProductManager )
  {
    delete m_pProductManager;
    m_pProductManager = NULL;
  }
  printf("~CustomerService\n");
}

void CustomerService::solveTheProblem(int problemType)
{
  if( LOW_DIFFICULTY == problemType )
  {
    printf("Problem is low difficulty and customer service solve it！\n");
  }
  else
  {
    m_pProductManager = new ProductManager;
    m_pProductManager->solveTheProblem( problemType );
  }
}

/******************************ProductManager**********************************/
ProductManager::ProductManager()
{
}

ProductManager::~ProductManager()
{
  if ( NULL != m_pSoftEngine )
  {
    delete m_pSoftEngine;
    m_pSoftEngine = NULL;
  }
  printf("~ProductManager\n");
}

void ProductManager::solveTheProblem(int problemType)
{
  if( MID_DIFFICULTY == problemType )
  {
    printf("Problem is mid difficulty and product manager solve it！\n");
  }
  else
  {
     m_pSoftEngine = new SoftEngine;
     m_pSoftEngine->solveTheProblem( problemType );
  }
}
/******************************SoftEngine**********************************/
SoftEngine::SoftEngine()
{
}

SoftEngine::~SoftEngine()
{
  printf("~SoftEngine\n");
}

void SoftEngine::solveTheProblem(int problemType)
{
  if( HIGH_DIFFICULTY == problemType )
  {
    printf("Problem is high difficulty and soft engine solve it！\n");
  }
  else
  {
    //nothing to do.
  }
}
