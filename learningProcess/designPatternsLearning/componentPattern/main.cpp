#include "main.h"

/*AUTHOR:	liuxiaohui
 *DATE:		2018-08-10
 *DISCTIPTION:  decorator pattern demo.
 */

 /*
 Compile command :g++ main.cpp componentPattern.cpp -o componentPattern
 */

void showTree(IFile* root,int leveal);

int main(int argc, char const *argv[])
{
  DirectoryFile *root = new DirectoryFile("C");


  DirectoryFile *dirA = new DirectoryFile("newDir_A");
  LeafFile *newFileA = new LeafFile("text_a.txt");

  //root->displayFileName();
  root->addFile(dirA);
  root->addFile(newFileA);

  DirectoryFile *dirB = new DirectoryFile("newDir_B");
  LeafFile *newFileB = new LeafFile("text_b.txt");
  dirA->addFile(dirB);
  dirA->addFile(newFileB);
  //获取root结点下的　孩子集合
  list<IFile*>* myList = root->getChild();
  std::list<IFile*>::iterator it = myList->begin();
  // for( ; it != myList->end(); it++ )
  // {
  //   (*it)->displayFileName();
  // }
  showTree(root,0);
  return 0;
}
//递归的显示树
void showTree(IFile* root,int leveal)
{
  //1 显示根　结点
  //2 若根节点　有孩子
      //孩子是文件，显示名字
      //若孩子是　目录　继续　showTree
  if( NULL == root)
  {
    return;
  }
  int i = 0;
  for( i = 0; i < leveal; i++)
  {
    printf("\t");
  }
  root->displayFileName();

  list<IFile*>* myList = root->getChild();
  if( NULL != myList )
  {
    std::list<IFile*>::iterator it = myList->begin();
    for( ; it != myList->end(); it++ )
    {
      if( NULL == (*it)->getChild() )
      {
        for( i = 0; i < leveal; i++)
        {
          printf("\t");
        }
        
        (*it)->displayFileName();
      }
      else
      {
        leveal++;
        showTree( *it ,leveal);
      }
    }
  }


}
