

/*AUTHOR:	liuxiaohui
 *DATE:		2018-07-07
 *
 *
 *getpid()			获取进程ID
 *pthread_self()	获取县城ID
 *
 *通过  man pthread_create 查看detail
 *int pthread_create(pthread_t *thread,
 *					 const pthread_attr_t *attr,
 *					 void *(*start_routine) (void *),
 *				     void *arg);
 *第一个参数，新线程id，创建成功系统回填
 *第二个参数，新线程到属性，NULL为默认属性
 *第三个参数，新线程到启动函数
 *第四个参数，传递给新线程
 */

/*
Compile command :gcc mutilThreadPrimer.c -o thread_create -lpthread
*/

/*
知识点总结
１、获取ID
  获取线程ID:pthread_t subTid = pthread_self();
  获取进程ID:pid_t subPid = getpid();

２、多个线程有不同的线程ID，但是它们的进程ID相同。

３、pthread_create()

４、给main()函数传参
  int main(int argc, char *argv[])
    argc参数的个数
    *argv[]参数的内容
５、pthread_exit(rval)
	void pthread_exit(void *retval);
			#include <pthread.h>
			 Compile and link with -pthread.

*/

#include "../mutilThreadLib.h"

struct student {
	int age;
	char name[20];
	char id[4];
};

void *thread_fun(void *stu)
{
  pid_t subPid;
  pthread_t subTid;

  subPid = getpid();
  subTid = pthread_self();

  printf("PROCESS ID: %u, SUB THREAD ID: 0x%x\n", subPid, subTid);


	sleep(1);
	printf("student age is %d, name is %s, id is %s\n",((struct student *)stu)->age, ((struct student *)stu)->name, ((struct student *)stu)->id);
	return (void *)0;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int err;
	int *rval;

	struct student stu;
	stu.age = 20;
	memcpy(stu.name, "zhangsan", 20);
	memcpy(stu.id, "007", 5);

	err = pthread_create(&tid, NULL, thread_fun, (void *)(&stu));
	if(err != 0)
	{
		printf(" create new thread failed\n");
		return 0;
	}

  pid_t mainPid;
  pthread_t mainTid;

  mainPid = getpid();
  mainTid = pthread_self();

  printf("PROCESS ID: %u, MAIN THREAD ID: 0x%x\n", mainPid, mainTid);


	int i;
	printf("main thread have %d args\n", argc);
	for(i=0; i<argc; i++)
	{
		printf("main thread args %d is %s\n", i, argv[i]);
	}

	pthread_exit(rval);
}
