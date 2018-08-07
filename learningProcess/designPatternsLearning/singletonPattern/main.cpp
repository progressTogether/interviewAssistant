#include"main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-7
 *DISCTIPTION:  singleton pattern demo.
 */

 /*
 Compile command :g++ main.cpp singleton.cpp -o singleton -lpthread
 */

int main(int argc,char *argv[])
{
  pthread_t tidA,tidB;
  int err;
  void *rvalA,*rvalB;
  //
  // singleton * singletonConcreteA = singleton::getInstance();
  // singleton * singletonConcreteB = singleton::getInstance();
  //
  // if(  singletonConcreteA == singletonConcreteB )
  // {
  //   std::cout << "Hello, singleton pattern!" << std::endl;
  // }

  err = pthread_create(&tidA, NULL, threadFunA, NULL );
  if(err != 0)
  {
    printf(" create new thread failed\n");
    return 0;
  }

  err = pthread_create(&tidB, NULL, threadFunB, NULL );
  if(err != 0)
  {
    printf(" create new thread failed\n");
    return 0;
  }

//pthread_join()等待具体线程ID的函数结束
  printf("joinA rval is %d\n", pthread_join(tidA,&rvalA));
  printf("joinB rval is %d\n", pthread_join(tidB,&rvalB));

  singleton::deleteInstance();

  return(0);
}


void *threadFunA(void *)
{
  singleton * singletonConcreteC = singleton::getInstance();
}
void *threadFunB(void *)
{
  singleton * singletonConcreteD = singleton::getInstance();
}
