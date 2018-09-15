#ifndef _MAIN_H
#define _MAIN_H

#include"CommandPattern.h"
#include "Client.h"

/*
命令模式
背景：在面向对象的程序设计中,一个对象调用另一个对象,
    一般情况下的调用过程是:创建目标对象实例;设置调用参数;调用目标对象的方法

定义：但在有些情况下有必要使用一个专门的类　对这种调用过程加以封装　,我们把这种专门的
    类称作 command 类　调用过程的封装

适用场景：调用过程比较繁杂、存在多处这种调用　
        使用 Command 类对该调用加以封装,便于功能的再利用
*/

/*

*/
enum SailMethod
{
  DIRECTLY_METHOD = 1,
  COMMAND_METHOD,
  WAITER_METHOD,
  ADVANCED_WAITER_METHOD
 };

void directSailFruit();
void commandSailFruit();
void waiterSailFruit();
void advancedWaiterSailFruit();

#endif
