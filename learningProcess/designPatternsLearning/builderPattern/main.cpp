#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-8
 *DISCTIPTION:  builder  pattern demo.
 */

 /*
 Compile command :g++ main.cpp builderPatternUgly.cpp builderPattern.cpp \
  -o builderFactory
 */

#define UGLY_BUILDER_VETSION_THREE

int main(int argc, char const *argv[])
{

//客户直接造房子，耦合度太高，当房子的需求改变时，客户端需要重写代码
#ifdef UGLY_BUILDER_VETSION_ONE
  House *myHouse = new House;
  myHouse->setHouseWall("white walls");
  myHouse->setHouseRoof("the golden roof");
  myHouse->setHouseFloor("color floor");

  myHouse->displayDetailHouse();

  delete myHouse;
#else
#endif

#ifdef UGLY_BUILDER_VETSION_TWO
  House *myHouse = NULL;
  UnglyBuilder *harderBuider = new UnglyBuilder;
  harderBuider->prepareBuilderHouse();
  harderBuider->buildDetailHouse();

  myHouse = harderBuider->getDetailHouse();
  myHouse->displayDetailHouse();

  delete harderBuider;
  delete myHouse;

  harderBuider = NULL;
  myHouse = NULL;

#else
#endif

#ifdef UGLY_BUILDER_VETSION_THREE

  ExcellentHouse*   myExHouse = NULL;
  Director*         myExDirector = NULL;
  Builder*          myBuilder = NULL;

  //建造别墅
  myBuilder = new VillaBuilder;
  myExDirector = new Director( myBuilder );
  myExDirector->construct();
  myExHouse = myBuilder->getDetailHouse();
  myExHouse->displayExcellentHouse();
  delete myBuilder;
  delete myExDirector;
  delete myExHouse;

  printf("\n");
  //建造公寓
  myBuilder = new FlatBuilder;
  myExDirector = new Director( myBuilder );
  myExDirector->construct();
  myExHouse = myBuilder->getDetailHouse();
  myExHouse->displayExcellentHouse();
  delete myBuilder;
  delete myExDirector;
  delete myExHouse;

  myBuilder = NULL;
  myExDirector = NULL;
  myExHouse = NULL;
#else
#endif

  return 0;
}
