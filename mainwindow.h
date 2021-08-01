#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include "xlsxdocument.h"

#include "constant.h"

class Config;
class ExcelSheet;
class FileDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_imporFileButton_clicked();

private:
    Ui::MainWindow *ui;
    Config *config;
    ExcelSheet* fixedAssetSheet;
    ExcelSheet* invisibleAssetSheet;
    ExcelSheet* thirdSheet {NULL};
    FileDialog* importFileDialog;
    FileDialog* exportFileDialog;

private:
    void readShowAssetBook(const QString& file);
    void readShowThirdFile(const QString& file, const AssetType assetType, const FormType formType);

};
#endif // MAINWINDOW_H
