#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create input and ouput folder
    if(!QDir("input").exists())
        QDir().mkdir("input");

    if(!QDir("output").exists())
        QDir().mkdir("output");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox m;

    m.setWindowTitle("Attention");
    m.setText("Are you sure to extract all files ?");
    m.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = m.exec();

    if(ret == QMessageBox::Ok)
    {

    //copy .rcc file from input to rccProj folder
    QString srcPath = QDir::currentPath() + "/input/"+ui->lineEdit->text();
    QString dstPath = QDir::currentPath() + "/rccProj/"+ui->lineEdit->text();

    if(!QFile::exists(srcPath))
    {
        QMessageBox m1;
        m1.setText("File Not Found");
        m1.exec();
        return;
    }
    if (QFile::exists(dstPath))
    {
        QFile::remove(dstPath);
    }

    QFile::copy(srcPath,dstPath);


    //running rcc.exe command
    QString rccDir = QDir::currentPath() + "/rccProj";
    std::cout << rccDir.toStdString()  << endl;;

    strcpy(temp,"cd ");
    strcat(temp,rccDir.toStdString().c_str());

    QString s  = QSysInfo::productType();

    std::cout << s.toStdString()  << endl;;

    if(s.contains("debian"))
        strcat(temp,"&& ./rcc --reverse");
    else if(s.contains("osx"))
        strcat(temp,"&& ./rcc --reverse");
    else if(s.contains("windows"))
        strcat(temp,"&& rcc.exe --reverse");
    else if(s.contains("winrt"))
        strcat(temp,"&& rcc.exe --reverse");




    const char *command1 = temp;
    std::cout << command1 << endl;
        std::system(command1);
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox m;

    m.setWindowTitle("Attention");
    m.setText("Are you sure to recompile all files ?");
    m.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = m.exec();

    QString rccDir = QDir::currentPath() + "/rccProj";

    strcpy(temp,"cd ");
    strcat(temp,rccDir.toStdString().c_str());

    QString s  = QSysInfo::productType();

    if(s.contains("debian"))
        strcat(temp," && ./rcc --format-version 1 --binary ../rccProj/qresource/qrc/PapyrusProRessourcen.qrc -o ../rccProj/qresource/rcc/PapyrusProRessourcen.rcc");
    else if(s.contains("osx"))
        strcat(temp," && ./rcc --format-version 1 --binary ../rccProj/qresource/qrc/PapyrusProRessourcen.qrc -o ../rccProj/qresource/rcc/PapyrusProRessourcen.rcc");
    else if(s.contains("windows"))
        strcat(temp," && rcc.exe --format-version 1 --binary ../rccProj/qresource/qrc/PapyrusProRessourcen.qrc -o ../rccProj/qresource/rcc/PapyrusProRessourcen.rcc");
    else if(s.contains("winrt"))
        strcat(temp," && rcc.exe --format-version 1 --binary ../rccProj/qresource/qrc/PapyrusProRessourcen.qrc -o ../rccProj/qresource/rcc/PapyrusProRessourcen.rcc");



    const char *command = temp;

    qDebug("%s", command);

    if(ret == QMessageBox::Ok)
    {
        std::system(command);
    }

    usleep(2000);

    QString srcPath = QDir::currentPath() + "/rccProj/qresource/rcc/"+ui->lineEdit->text();
    QString dstPath = QDir::currentPath() + "/output/"+ui->lineEdit->text();

    if (QFile::exists(dstPath))
    {
        QFile::remove(dstPath);
    }

    QFile::copy(srcPath,dstPath);

}


