#ifdef SINGLETON_H
#else
/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-7
 *DISCTIPTION:  singleton pattern demo.
 */
 /*
*   单例模式的优点:
*　　　　1. 在内存中只有一个对象,节省内存空间
*　　　　2. 避免频繁的创建销毁对象,可以提高性能
*　　　　3. 避免对共享资源的多重占用
*　　　　4. 可以全局访问
*　　单例模式的适用场景:
*　　　　1. 需要频繁实例化然后销毁的对象
*　　　　2. 创建对象耗时过多或者耗资源过多,但又经常用到的对象
*　　　　3. 有状态的工具类对象
*　　　  4. 频繁访问数据库或文件的对象
*　　　  5. 以及其他要求只有一个对象的场景
*   具体步骤
*       1. 构造函数私有化
*       2. 提供一个全局的静态方法
*       3. 在类中定义一个静态指针，指向本类的变量的静态变量指针
*
*   扩展：http://www.cnblogs.com/qicosmos/p/3145019.html
*/
#include "../designPatternLib.h"
using namespace std;

class singleton
{

public:
  //提供一个全局的静态方法
  static singleton* getInstance();
  //提供析构的接口
  static void deleteInstance();

private:
  //私有化
  singleton();
  ~singleton();
  //把复制构造函数和=操作符也设为私有,防止被复制
	singleton(const singleton& singleton );
	singleton& operator=(const singleton&);

private:
  //在类中定义一个静态指针，指向本类的变量的静态变量指针
  static singleton* singletonConcrete;

};

#endif
