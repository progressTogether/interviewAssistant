#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-19
 *DISCTIPTION:  observe pattern demo.
 */

 /*
 Compile command :g++ main.cpp observePattern.cpp -o observePattern
 */



int main(int argc, char const *argv[])
{
  bool isAntiR = false;
  Monitor *monitor = NULL;

  Student *studentA = NULL;
  Student *studentB = NULL;
  Student *studentC = NULL;

  monitor = new Monitor;

  studentA = new LoveLolPlayer;
  studentB = new LoveNovalReader;
  studentC = new LoveChating;

  monitor->registerNotification( studentA );
  monitor->registerNotification( studentB );
  monitor->registerNotification( studentC );

  printf("The teacher coming!\n");
  monitor->notificationStudent( false );
  printf("\n");
  sleep(3);

  printf("The teacher leaving!\n");
  monitor->notificationStudent( true );
  printf("\n");

  sleep(3);

  isAntiR = monitor->anti_registerNotification( studentB );

  if (isAntiR)
  {
    printf("studentB go home,and anti register success!\n");
  }

  isAntiR = monitor->anti_registerNotification( studentB );
  printf("\n");
  printf("The teacher coming agin!\n");
  monitor->notificationStudent( false );
  printf("\n");

  delete monitor;
  monitor = NULL;

  delete studentA;
  studentA = NULL;

  delete studentB;
  studentB = NULL;

  delete studentC;
  studentC = NULL;

  return 0;
}
