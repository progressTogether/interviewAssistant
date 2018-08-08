#include"builderPatternUgly.h"


House::House()
{

}

House::~House()
{
  printf("~House\n");
}

string House::getHouseWall()
{
  printf("The wall of house is %s!\n",m_houseWall.c_str());
  return m_houseWall;
}

string House::getHouseRoof()
{
  printf("The wall of roof is %s!\n",m_houseRoof.c_str());
  return m_houseRoof;
}

string House::getHouseFloor()
{
  printf("The floor of house is %s!\n",m_houseFloor.c_str());
  return m_houseFloor;
}

void House::displayDetailHouse()
{
  getHouseWall();
  getHouseRoof();
  getHouseFloor();
}

void House::setHouseWall(string wall)
{
  m_houseWall = wall;
}

void House::setHouseRoof(string roof)
{
  m_houseRoof = roof;
}

void House::setHouseFloor(string floor)
{
  m_houseFloor = floor;
}

/******************************UnglyBuilder************************************/

UnglyBuilder::UnglyBuilder()
{

}

UnglyBuilder::~UnglyBuilder()
{
  printf("~UnglyBuilder\n");
}

void UnglyBuilder::prepareBuilderHouse()
{
  m_myHouse = new House;
}

House* UnglyBuilder::getDetailHouse()
{
  return m_myHouse;
}

void UnglyBuilder::destoryDetailHouse()
{
  delete m_myHouse;
}

void UnglyBuilder::buildDetailHouse()
{
  buildDetailWall();
  buildDetailRoof();
  buildDetailFloor();
}

void UnglyBuilder::buildDetailWall()
{
  m_myHouse->setHouseWall("white walls");
}

void UnglyBuilder::buildDetailRoof()
{
  m_myHouse->setHouseRoof("the golden roof");
}

void UnglyBuilder::buildDetailFloor()
{
  m_myHouse->setHouseFloor("color floor");
}
