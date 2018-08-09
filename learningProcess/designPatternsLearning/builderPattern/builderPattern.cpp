#include"builderPattern.h"

ExcellentHouse::ExcellentHouse()
{

}

ExcellentHouse::~ExcellentHouse()
{
  printf("~ExcellentHouse\n");
}

string ExcellentHouse::getExcellentHouseWall()
{
  printf("The wall of house is %s!\n",m_houseWall.c_str());
  return m_houseWall;
}

string ExcellentHouse::getExcellentHouseRoof()
{
  printf("The wall of roof is %s!\n",m_houseRoof.c_str());
  return m_houseRoof;
}

string ExcellentHouse::getExcellentHouseFloor()
{
  printf("The floor of house is %s!\n",m_houseFloor.c_str());
  return m_houseFloor;
}

void ExcellentHouse::displayExcellentHouse()
{
  getExcellentHouseWall();
  getExcellentHouseRoof();
  getExcellentHouseFloor();
}

void ExcellentHouse::setExcellentHouseWall(string wall)
{
  m_houseWall = wall;
}

void ExcellentHouse::setExcellentHouseRoof(string roof)
{
  m_houseRoof = roof;
}

void ExcellentHouse::setExcellentHouseFloor(string floor)
{
  m_houseFloor = floor;
}

/******************************Builder*****************************************/

Builder::Builder()
{

}

Builder::~Builder()
{
  printf("~Builder\n");
}


/***************************FlatBuilder****************************************/

FlatBuilder::FlatBuilder():Builder()
{

}

FlatBuilder::~FlatBuilder()
{
  printf("~FlatBuilder\n");
}

void FlatBuilder::prepareBuilderHouse()
{
  m_myHouse = new ExcellentHouse;
}

ExcellentHouse* FlatBuilder::getDetailHouse()
{
  return m_myHouse;
}

void FlatBuilder::buildDetailWall()
{
  m_myHouse->setExcellentHouseWall("the flat wall");
}

void FlatBuilder::buildDetailRoof()
{
  m_myHouse->setExcellentHouseRoof("the flat roof");
}

void FlatBuilder::buildDetailFloor()
{
  m_myHouse->setExcellentHouseFloor("the flat floor");
}

/***************************VillaBuilder****************************************/

VillaBuilder::VillaBuilder():Builder()
{

}

VillaBuilder::~VillaBuilder()
{
  printf("~VillaBuilder\n");
}

void VillaBuilder::prepareBuilderHouse()
{
  m_myHouse = new ExcellentHouse;
}

ExcellentHouse* VillaBuilder::getDetailHouse()
{
  return m_myHouse;
}

void VillaBuilder::buildDetailWall()
{
  m_myHouse->setExcellentHouseWall("the villa wall");
}

void VillaBuilder::buildDetailRoof()
{
  m_myHouse->setExcellentHouseRoof("the villa roof");
}

void VillaBuilder::buildDetailFloor()
{
  m_myHouse->setExcellentHouseFloor("the villa floor");
}

/*****************************Directorr****************************************/

Director::Director(Builder *builder)
{
  m_builder = builder;
}

void Director::construct()
{
  m_builder->prepareBuilderHouse();
  m_builder->buildDetailWall();
  m_builder->buildDetailRoof();
  m_builder->buildDetailFloor();
}
