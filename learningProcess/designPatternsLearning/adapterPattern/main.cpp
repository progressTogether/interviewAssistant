#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-11
 *DISCTIPTION:  adapter pattern demo.
 */

 /*
 Compile command :g++ main.cpp adapterPattern.cpp -o adapterPattern
 */



int main(int argc, char const *argv[])
{
  // Current220v *p220v = new Current220v;
  // Adapter *padapter = new Adapter(p220v);
  // padapter->use18vCurrent();
  //
  // delete p220v;
  // delete padapter;

  Current220v *p220v = new Current220v;
  Current18v *pAdapter = new Adapter(p220v);
  pAdapter->use18vCurrent();

  delete p220v;
  delete pAdapter;

  return 0;
}
