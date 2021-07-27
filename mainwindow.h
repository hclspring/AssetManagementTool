#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include "xlsxdocument.h"

class Config;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTabWidget();
    void readAssetBookFile();

private:
    Ui::MainWindow *ui;
    Config *config;

private:
    void initTableWidget(QTableWidget* tableWidget, const QVector<QString>& columnNames);
    void readAssetBookSheet(QXlsx::Document& assetBookDocument, const QString& sheetName, QTableWidget* tableWidget);

};
#endif // MAINWINDOW_H
