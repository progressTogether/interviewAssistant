#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-7
 *DISCTIPTION:  factory pattern demo.
 */

 /*
 Compile command :
 g++ main.cpp CommandPattern.cpp Receiver.cpp Client.cpp -o CommandPattern
 */
int main(int argc, char const *argv[])
{
  int method = 4;

  switch ( method )
  {
    case DIRECTLY_METHOD:
      directSailFruit();
      break;
    case COMMAND_METHOD:
      commandSailFruit();
      break;
    case WAITER_METHOD:
      waiterSailFruit();
      break;
    case ADVANCED_WAITER_METHOD:
      advancedWaiterSailFruit();
    default:
      break;
  }
  return 0;
}

//方式一　直接调用该对象
void directSailFruit()
{
  printf("Vendor sell fruit directly.\n");
  Vendor* pVe = new Vendor;

  pVe->sailBanana();
  pVe->sailApple();

  delete pVe;
}

//方式二　通过命令调用该对象
void commandSailFruit()
{
  printf("Vendor sell fruit by command.\n");
  Vendor* pVe = new Vendor;

  Command* pSailA = new AppleCommand( pVe );
  Command* pSailB = new BananaCommand( pVe );

  pSailA->sail();
  pSailB->sail();

  delete pVe;
  delete pSailA;
  delete pSailB;
}

//方式三　通过waiter 方式调用该对象
void waiterSailFruit()
{
  printf("Vendor sell fruit by waiter.\n");

  Vendor* pVe = new Vendor;

  Command* pSailA = new AppleCommand( pVe );
  Command* pSailB = new BananaCommand( pVe );

  Waiter* pWaiter = new Waiter;

  pWaiter->setCommand( pSailA );
  pWaiter->sail();

  pWaiter->setCommand( pSailB );
  pWaiter->sail();

  delete pVe;
  delete pSailA;
  delete pSailB;
  delete pWaiter;
}

//方式三　通过　advanced waiter 方式批量调用该对象
void advancedWaiterSailFruit()
{
  printf("Vendor sell fruit by advanced waiter.\n");

  Vendor* pVe = new Vendor;
  Command* pSailA = new AppleCommand( pVe );
  Command* pSailB = new BananaCommand( pVe );
  Command* pSailAp = new BananaCommand( pVe );
  Command* pSailBa = new BananaCommand( pVe );

  AdvWaiter* pAdvWaiter = new AdvWaiter;

  pAdvWaiter->addINCommandL(pSailA);
  pAdvWaiter->addINCommandL(pSailB);
  pAdvWaiter->addINCommandL(pSailAp);
  pAdvWaiter->addINCommandL(pSailBa);

  pAdvWaiter->sail();

  delete pVe;
  delete pSailA;
  delete pSailB;
  delete pAdvWaiter;
}
