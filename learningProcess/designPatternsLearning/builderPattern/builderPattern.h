#include "../designPatternLib.h"

class ExcellentHouse//ExcellentHouse
{
public:
  ExcellentHouse();
  ~ExcellentHouse();
  string getExcellentHouseWall();
  string getExcellentHouseRoof();
  string getExcellentHouseFloor();

  void displayExcellentHouse();

  void setExcellentHouseWall(string wall);
  void setExcellentHouseRoof(string roof);
  void setExcellentHouseFloor(string floor);

private:
  string m_houseWall;
  string m_houseRoof;
  string m_houseFloor;
};

class Builder
{
public:
  Builder();
  virtual ~Builder();
  virtual void prepareBuilderHouse() =  0;
  virtual ExcellentHouse* getDetailHouse() = 0;

  virtual void buildDetailWall() = 0;
  virtual void buildDetailRoof() = 0;
  virtual void buildDetailFloor() = 0;
};

class FlatBuilder: public Builder
{
public:
  FlatBuilder();
  virtual ~FlatBuilder();
  virtual void prepareBuilderHouse();
  virtual ExcellentHouse* getDetailHouse();

  virtual void buildDetailWall();
  virtual void buildDetailRoof();
  virtual void buildDetailFloor();
private:
  ExcellentHouse* m_myHouse;
};

class VillaBuilder: public Builder
{
public:
  VillaBuilder();
  virtual ~VillaBuilder();
  virtual void prepareBuilderHouse();
  virtual ExcellentHouse* getDetailHouse();

  virtual void buildDetailWall();
  virtual void buildDetailRoof();
  virtual void buildDetailFloor();
private:
  ExcellentHouse* m_myHouse;
};

class Director
{
public:
  Director(Builder *builder);
  void construct();
private:
  Builder* m_builder;
};
