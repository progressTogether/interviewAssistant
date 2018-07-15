/*AUTHOR:	liuxiaohui
 *DATE:		2018-07-15
 *DISCTIPTION:  线程的连接
 */

/*
Compile command : gcc mutilThreadConnected.c -o thread_connected -lpthread
*/

/*
*   通过这个文件可以看到数字22对应的宏为EINVAL
*   vi /usr/include/asm-generic/errno-base.h
*   通过 man pthread_join 我们可以看到EINVAL,线程时不可连接的，因为线程已经分离
*   #define EINVAL          22      //Invalid argument
*    EINVAL thread is not a joinable thread.
*/
#define DETACH_THREADB
#include "../mutilThreadLib.h"

void *threadConnectedA(void *arg)
{
  printf("I am thread threadConnectedA!\n");
  return (void *)1;
}

void *threadConnectedB(void *arg)
{
  printf("I am thread threadConnectedB!\n");
#ifdef DETACH_THREADB
  pthread_detach( pthread_self() );
#else
#endif
  pthread_exit( (void*)2 );
}

int main(int argc, char const *argv[])
{
  short errorA, errorB;
  pthread_t tidA,tidB;
  void *rvalA,*rvalB;

  errorA = pthread_create( &tidA, NULL, threadConnectedA, NULL);
  errorB = pthread_create( &tidB, NULL, threadConnectedB, NULL);

  if( errorA || errorB )
  {
    printf( "create thread failed!" );
    return 0;
  }

  printf( "I am Main thread!\n" );
  printf("joinA rval is %d\n", pthread_join(tidA,&rvalA));
  printf("joinB rval is %d\n", pthread_join(tidB,&rvalB));

  printf("threadA exit code is %d\n", (int *)rvalA);
  printf("threadA exit code is %d\n", (int *)rvalB);
  printf( "I am Main thread!\n" );

  return 0;
}
