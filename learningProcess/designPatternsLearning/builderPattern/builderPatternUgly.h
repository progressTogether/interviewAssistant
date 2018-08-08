#include "../designPatternLib.h"

class House
{
public:
  House();
  ~House();
  string getHouseWall();
  string getHouseRoof();
  string getHouseFloor();

  void displayDetailHouse();

  void setHouseWall(string wall);
  void setHouseRoof(string roof);
  void setHouseFloor(string floor);

private:
  string m_houseWall;
  string m_houseRoof;
  string m_houseFloor;
};

class UnglyBuilder
{
public:
  UnglyBuilder();
  ~UnglyBuilder();
  void prepareBuilderHouse();
  House* getDetailHouse();
  void destoryDetailHouse();

  void buildDetailHouse();

  void buildDetailWall();
  void buildDetailRoof();
  void buildDetailFloor();
private:
  House* m_myHouse;
};
