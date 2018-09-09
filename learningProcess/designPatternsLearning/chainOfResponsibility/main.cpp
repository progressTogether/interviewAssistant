#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-09-9
 *DISCTIPTION:  chainOfResponsibility pattern demo.
 */

 /*
 Compile command :g++ main.cpp chainOfResponsibility.cpp -o chainOfResponsibility
 */



int main(int argc, char const *argv[])
{
  CustomerService* ladeyService = new CustomerService;
  printf("用户发现软件使用问题，向客户投诉，进而客户解决。\n");
  int problemType = 3;
  ladeyService->solveTheProblem(problemType);

  printf("\n");
  printf("\n");
  delete ladeyService;
  return 0;
}
