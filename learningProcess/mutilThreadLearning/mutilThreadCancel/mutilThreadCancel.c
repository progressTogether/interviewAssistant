/*AUTHOR:	liuxiaohui
 *DATE:		2018-07-15
 *DISCTIPTION:  线程的取消
 */

/*
Compile command :gcc mutilThreadCancel.c -o thread_cancel -lpthread
OPERATION command:
*/

#include "../mutilThreadLib.h"

//是否可以被取消
#define DISABLE_CANCEL_STATE
//immediately 是否立即取消
//#define SETTING_IMMEDIATELY


void *pthreadCancelDemo(void * exitMethod)
{
  int stateval,typeval;
  stateval = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
  if( 0 != stateval)
  {
    printf("set cancle state failed!\n" );
  }
  printf("I am pthreadCancelDemo\n");
  sleep(4);
  printf("About to cancel!\n");

#ifdef DISABLE_CANCEL_STATE
  stateval = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
  if( 0 != stateval)
  {
    printf("set cancle state failed!\n" );
  }
#else
#endif

#ifdef SETTING_IMMEDIATELY
  typeval = pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
  if( 0 != typeval)
  {
    printf( "set cancel type failed!\n" );
  }
#else
#endif

  printf("first cancel point!\n" );
  printf("seccond cancel point!\n" );
  return (void*)20;
}

int main(int argc,char* argv[])
{
  int error,cval,jval;
  pthread_t tid;
  void *rval;
  error = pthread_create(&tid, NULL, pthreadCancelDemo, (void*)argv[1]);
  if(0 != error)
  {
    printf( "create thread failed! \n" );
  }
  sleep(2);

  //发送取消信号
  cval = pthread_cancel(tid);
  if( 0 != cval)
  {
    printf("cancel thread failed!\n");
  }
  //连接线程，如果线程已经被取消
  jval = pthread_join(tid,&rval);
  if( 0 != jval)
  {
    printf("pthread cancel failed,and return error code is %d!\n", jval);
  }
  printf("New thread exit code is %d\n",(int *)rval );

  return 0;
}
