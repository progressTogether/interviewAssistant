#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"commonMethod.h"
#include"commonType.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pSingleton->getInstance();

    m_pWriteInfoToFile = new WriteInfoToFile;
    //m_pWriteInfoToFile->writeInfoToXml();
    m_pWriteInfoToFile->readInfoFromXml();

    TestPacket tmpTest;
    tmpTest.isOk = "hope ok!";
    tmpTest.testID = 1;
    std::string msg = PackProStruct( tmpTest );
    m_pWriteInfoToFile->testPacket( msg );
}

MainWindow::~MainWindow()
{
    m_pSingleton->deleteInstance();
    delete ui;
}
