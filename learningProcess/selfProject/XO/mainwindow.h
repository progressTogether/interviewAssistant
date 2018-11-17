#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"singleton.h"
#include"WriteInfoToFile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow*     ui;
    Singleton*          m_pSingleton;
    WriteInfoToFile*    m_pWriteInfoToFile;
};

#endif // MAINWINDOW_H
