#include"observePattern.h"

Student::Student()
{

}

Student::~Student()
{
  printf("~Student\n");
}

/*****************************LoveLolPlayer************************************/

LoveLolPlayer::LoveLolPlayer()
{

}

LoveLolPlayer::~LoveLolPlayer()
{
  printf("~LoveLolPlayer\n");
}

void LoveLolPlayer::doingSomething()
{
  printf("Player is playing LOL！\n");
}

void LoveLolPlayer::stopingDoing()
{
  printf("Player stop playing LOL,and bengin to study！\n");
}


/*****************************LoveNovalReader************************************/

LoveNovalReader::LoveNovalReader()
{

}

LoveNovalReader::~LoveNovalReader()
{
  printf("~LoveNovalReader\n");
}

void LoveNovalReader::doingSomething()
{
  printf("Reader is reading noval！\n");
}

void LoveNovalReader::stopingDoing()
{
  printf("Reader stop reading noval,and bengin to study！\n");
}

/*****************************LoveChating************************************/

LoveChating::LoveChating()
{

}

LoveChating::~LoveChating()
{
  printf("~LoveChating\n");
}

void LoveChating::doingSomething()
{
  printf("Chatting students is Chatting！\n");
}

void LoveChating::stopingDoing()
{
  printf("Chatting students stop Chatting,and bengin to study！\n");
}

/*****************************Monitor************************************/
Monitor::Monitor()
{
  m_pStudentList = new list<Student*>;
  m_pStudentList->clear();
}

Monitor::~Monitor()
{
  m_pStudentList->clear();
  delete m_pStudentList;
  m_pStudentList = NULL;
  printf("~Monitor\n");
}

void Monitor::registerNotification( Student* stu )
{
  m_pStudentList->push_back(stu);
}

bool Monitor::anti_registerNotification( Student* stu )
{
  bool isHave = false;

  std::list<Student*>::iterator it = m_pStudentList->begin();
  for( ; it != m_pStudentList->end(); it++ )
  {
    if( stu == ( *it ) )
    {
        it = m_pStudentList->erase( it );
        isHave = true;
        printf("Anti register success!!\n");
    }
  }
  if( !isHave )
  {
    printf("Anti register failed,maybe list have not this object!\n");
  }
  return isHave;
}

void Monitor::notificationStudent(bool status)
{
  std::list<Student*>::iterator it = m_pStudentList->begin();
  for( ; it != m_pStudentList->end(); it++ )
  {
    if( true == status )
    {
        (*it)->doingSomething();
    }
    else
    {
        (*it)->stopingDoing();
    }

  }
}
