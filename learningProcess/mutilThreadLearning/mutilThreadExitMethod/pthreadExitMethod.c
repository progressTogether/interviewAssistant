/*AUTHOR:	liuxiaohui
 *DATE:		2018-07-15
 *DISCTIPTION:  线程的退出方式
 */
 
/*
Compile command :gcc pthreadExitMethod.c -o thread_exit -lpthread
OPERATION command:  ./thread_exit 1
                    ./thread_exit 2
                    ./thread_exit 3
*/

#include "../mutilThreadLib.h"

void *pthreadExitMethod(void * exitMethod)
{
    if( 0 == strcmp("1", (char*)exitMethod ) )
    {
      printf("New thread return!\n");
      return (void *)1;
    }

    if( 0 == strcmp("2", (char*)exitMethod ) )
    {
      printf("New thread call pthread_exit!\n");
      pthread_exit( (void *)2 );
    }

    if( 0 == strcmp("3", (char*)exitMethod ) )
    {
      printf("New thread exit!\n");
      exit(0);
    }
}

int main(int argc,char* argv[])
{
  int error;
  pthread_t tid;

  error = pthread_create(&tid, NULL, pthreadExitMethod, (void*)argv[1]);
  if(0 != error)
  {
    printf( "create thread failed! \n" );
  }
  sleep(1);
  printf(" main thread exit!\n" );
  return 0;
}
