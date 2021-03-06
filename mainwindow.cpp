#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "excelsheet.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = new Config();
    fixedAssetSheet = new ExcelSheet(ui->fixedAssetSheetWidget);
    invisibleAssetSheet = new ExcelSheet(ui->invisibleAssetSheetWidget);
    thirdSheet = NULL;
    //initTabWidget();
    //readAssetBookFile();
    //test();
    readShowAssetBook(config->getAssetBookFilename());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::initTabWidget()
{
    initTableWidget(ui->fixedAssetTableWidget, config->getFixedAssetColumnNames());
    initTableWidget(ui->invisibleAssetTableWidget, config->getInvisibleAssetColumnNames());
}

void MainWindow::readAssetBookFile()
{
    QXlsx::Document assetBookFile(config->getAssetBookFilename());
    if (assetBookFile.load()) {
        int sheetIndex = 0;
        QStringList sheetNames = assetBookFile.sheetNames();
        for (int sheetIndex = 0; sheetIndex < sheetNames.length(); ++sheetIndex) {
            if (sheetNames[sheetIndex].compare(config->getFixedAssetSheetName()) == 0) {
                //读取固定资产表内容，展现到界面上
                readAssetBookSheet(assetBookFile, sheetNames[sheetIndex], ui->fixedAssetTableWidget);
            } else if (sheetNames[sheetIndex].compare(config->getInvisibleAssetSheetName()) == 0) {
                //读取无形资产表内容，展现到界面上
                readAssetBookSheet(assetBookFile, sheetNames[sheetIndex], ui->invisibleAssetTableWidget);
            } else {
                qDebug() << "发现名为" << sheetNames[sheetIndex] << "的未定义sheet，未读取。";
            }
        }
    } else {
        qDebug() << "读取交付物台账文件" << config->getAssetBookFilename() << "失败！";
    }
}

void MainWindow::initTableWidget(QTableWidget* tableWidget, const QVector<QString>& columnNames)
{
    //QStringList headerText;
    //for (int i = 0; i < columnNames.size(); ++i) {
    //    headerText << columnNames[i];
    //}
    tableWidget->setColumnCount(columnNames.size());
    for (int i = 0; i< columnNames.size(); ++i) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(columnNames[i]);
        QFont headerFont = headerItem->font();
        headerFont.setBold(true);
        tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
}

void MainWindow::readAssetBookSheet(QXlsx::Document& assetBookDocument, const QString& sheetName, QTableWidget* tableWidget)
{
    assetBookDocument.selectSheet(sheetName);
    QXlsx::AbstractSheet* sheet = assetBookDocument.sheet(sheetName);
    QXlsx::Worksheet* worksheet = (QXlsx::Worksheet*) sheet;
    int maxRow = 0, maxCol = 0;
    worksheet->getFullCells(&maxRow, &maxCol);
    qDebug() << maxRow << "行，" << maxCol << "列";
    //第一行是列名，获取config中每列名字位于文件的第几列。
    QVector<int> configColumnIndices (config->getFixedAssetColumnNames().size(), -1);//存储config中每列名字位于文件的第几列
    QVector<int> fileColumnIndices (maxCol+1, -1);//存储文件中每列名字位于config的第几列
    for (int col = 1; col <= maxCol; ++col) {
        QString fileColumnName = assetBookDocument.read(config->getAssetBookColumnNameRow(), col).toString();
        int configColumnIndex = config->getFixedAssetColumnIndex(fileColumnName); //这里指定了必须是固定资产表的列名
        if (configColumnIndex >= 0) {
            configColumnIndices[configColumnIndex] = col;
        }
        fileColumnIndices[col] = configColumnIndex;
        //qDebug() << col << assetBookDocument.read(config->getAssetBookColumnNameRow(), col).toString();
    }
    //跳过不是数据的行，方法为判断序号哪一行从1开始。
}

void MainWindow::test()
{
    ui->fixedAssetTableWidget = new ExcelSheetWidget();
    ExcelSheetWidget* sheetWidget = new ExcelSheetWidget;
    sheetWidget->initFileConfig(config->getAssetBookColumnNameRow(), config->getAssetBookDataStartRow(), 1);
    QXlsx::Document assetBookFile(config->getAssetBookFilename());
    if (assetBookFile.load()) {
        sheetWidget->readSheet(assetBookFile, "硬件");
        sheetWidget->showSheet();
        int tabIndex = ui->tabWidget->addTab(sheetWidget, "测试TAB");
        sheetWidget->hideRow(0); //测试如何addTab后再对widget进行控制
    } else {
        qDebug() << "读取交付物台账文件" << config->getAssetBookFilename() << "失败！";
    }
}
*/

void MainWindow::readShowAssetBook(const QString& file)
{
    QXlsx::Document assetBookFile(file);
    if (assetBookFile.load()) {
        QStringList sheetNames = assetBookFile.sheetNames();
        for (int sheetIndex = 0; sheetIndex < sheetNames.length(); ++sheetIndex) {
            QString sheetName = sheetNames[sheetIndex];
            if (sheetName.contains("硬件") || sheetName.contains("固定")) {
                //读取固定资产交付物台账内容，展现到界面上
                fixedAssetSheet->initFileConfig(config->getAssetBookColumnNameRow(),
                                                config->getAssetBookDataStartRow(),
                                                config->getAssetBookOrdinalColumn());
                fixedAssetSheet->readSheet(assetBookFile, sheetName);
                fixedAssetSheet->showSheet();
            } else if (sheetName.contains("软件") || sheetName.contains("无形")) {
                //读取无形资产交付物台账内容，展现到界面上
                invisibleAssetSheet->initFileConfig(config->getAssetBookColumnNameRow(),
                                                config->getAssetBookDataStartRow(),
                                                config->getAssetBookOrdinalColumn());
                invisibleAssetSheet->readSheet(assetBookFile, sheetName);
                invisibleAssetSheet->showSheet();
            } else {
                qDebug() << "发现名为" << sheetNames[sheetIndex] << "的未定义sheet，未读取。";
            }
        }
    } else {
        qDebug() << "读取交付物台账文件" << file << "失败！";
    }
}

