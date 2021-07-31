#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include "xlsxdocument.h"

class Config;
class ExcelSheet;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void initTabWidget(); //To delete
    //void readAssetBookFile(); //To delete

private:
    Ui::MainWindow *ui;
    Config *config;
    ExcelSheet* fixedAssetSheet;
    ExcelSheet* invisibleAssetSheet;
    ExcelSheet* thirdSheet {NULL};

private:
    void readShowAssetBook(const QString& file);
    //void initTableWidget(QTableWidget* tableWidget, const QVector<QString>& columnNames); //To delete
    //void readAssetBookSheet(QXlsx::Document& assetBookDocument, const QString& sheetName, QTableWidget* tableWidget); //To delete
    //void test();

};
#endif // MAINWINDOW_H
