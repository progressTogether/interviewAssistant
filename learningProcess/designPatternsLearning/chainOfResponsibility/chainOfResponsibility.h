#include "../designPatternLib.h"

/*
  某用户购买了一款软件，用了几天就crash，重要在数据丢失。用户很生气，后果很严重。
  于是打电话给软件公司客服投诉。
  客服如果不能解决，会问经理，
  若经理也不能解决或者认为不规他解决，会转给工程师解决，
  这样客服、经理、工程师就构成了一条责任链。
*/
enum PROBLEM_TYPE { LOW_DIFFICULTY = 1, MID_DIFFICULTY, HIGH_DIFFICULTY };

class SoftCompany
{
public:
  SoftCompany();
  virtual ~SoftCompany();
  virtual void  solveTheProblem(int problemType) = 0;
  //virtual void outputPersonInfo() = 0;
private:
};

class CustomerService :public SoftCompany
{
public:
  CustomerService();
  ~CustomerService();
  virtual void  solveTheProblem(int problemType);
private:
  SoftCompany*    m_pProductManager;
};

class ProductManager:public SoftCompany
{
public:
  ProductManager();
  ~ProductManager();
  virtual void  solveTheProblem(int problemType);
private:
  SoftCompany*    m_pSoftEngine;
};

class SoftEngine:public SoftCompany
{
public:
  SoftEngine();
  ~SoftEngine();
  virtual void  solveTheProblem(int problemType);
private:
  SoftCompany*    m_pProductManager;
};
