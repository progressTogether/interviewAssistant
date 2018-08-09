#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-9
 *DISCTIPTION:  proxy pattern demo.
 */

 /*
 Compile command :g++ main.cpp proxyPattern.cpp -o proxyPattern
 */



int main(int argc, char const *argv[])
{
  Subject* bookBoss = NULL;
  bookBoss = new NetworkSailProxy;

  int i = 0;
  for( ; i < 11; i++ )
  {
    bookBoss->sailBook();
  }

  delete bookBoss;
  return 0;
}
