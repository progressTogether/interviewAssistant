#include "../designPatternLib.h"
#include <list>

class IFile
{
public:
  virtual void displayFileName() = 0;
  virtual int addFile( IFile* ifile) = 0;
  virtual int removeFile( IFile* ifile) = 0;
  virtual list<IFile*>* getChild() = 0;
};

class LeafFile: public IFile
{
public:
  LeafFile( string name);
  ~LeafFile();
  virtual void displayFileName();
  virtual int addFile( IFile* ifile);
  virtual int removeFile( IFile* ifile);
  virtual list<IFile*>* getChild();
private:
  string m_fileName;
};

class DirectoryFile: public IFile
{
public:
  DirectoryFile( string name);
  ~DirectoryFile();
  virtual void displayFileName();
  virtual int addFile( IFile* ifile);
  virtual int removeFile( IFile* ifile);
  virtual list<IFile*>* getChild();
private:
  string m_fileName;
  list<IFile*>* m_fileList;
};
