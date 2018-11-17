#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pSingleton->getInstance();

    m_pWriteInfoToFile = new WriteInfoToFile;
    m_pWriteInfoToFile->writeInfoToXml();
}

MainWindow::~MainWindow()
{
    m_pSingleton->deleteInstance();
    delete ui;
}
