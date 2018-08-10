#include"componentPattern.h"


/******************************LeafFile**************************************/

LeafFile::LeafFile(string name)
{
  m_fileName = name;
}

LeafFile::~LeafFile()
{
  printf("~LeafFile\n");
}

void LeafFile::displayFileName()
{
  printf("%s.\n",m_fileName.c_str());
}

int LeafFile::addFile( IFile* ifile )
{
  return -1;
}

int LeafFile::removeFile( IFile* ifile )
{
  return -1;
}

list<IFile*>* LeafFile::getChild()
{
  return NULL;
}

/******************************DirectoryFile**********************************/
DirectoryFile::DirectoryFile(string name)
{
  m_fileName = name;
  m_fileList = new list<IFile*>;
  m_fileList->clear();
}

DirectoryFile::~DirectoryFile()
{
  printf("~LeafFile\n");
}

void DirectoryFile::displayFileName()
{
  printf("%s.\n",m_fileName.c_str());
}

int DirectoryFile::addFile( IFile* ifile )
{
  m_fileList->push_back( ifile );
  return 0;
}

int DirectoryFile::removeFile( IFile* ifile )
{
  m_fileList->remove(ifile);
  return 0;
}

list<IFile*>* DirectoryFile::getChild()
{
  return m_fileList;
}

/******************************SwimingCar**************************************/
