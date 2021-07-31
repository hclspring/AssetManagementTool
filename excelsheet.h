#ifndef EXCELSHEET_H
#define EXCELSHEET_H

#include <QWidget>
#include <QTableWidget>
#include <QDebug>

#include "xlsxdocument.h"

class Util;

class ExcelSheet
{
    typedef QMap<QString, size_t> MapS2I;
    typedef QMap<QString, size_t>::iterator IteratorS2I;
public:
    ExcelSheet();
    ExcelSheet(QTableWidget* tableWidget);

private:
    QTableWidget* tableWidget {NULL};

    //关于从0开始还是从1开始的问题：
    //如果是excel文件，则从1开始
    //如果是widget或vector，则从0开始
    QVector<QVector<QVariant>> sheetContent;//从0,0开始填
    QVector<QString> columnNames;//从0开始填
    MapS2I columnName2Index;
    //QVector<QString> columnNumbers;//A,...,Z,AA,...AZ,BA,...,BZ,...
    int columnNameRow; //列名所在行，一般为1
    int dataStartRow; //数据起始行，一般为2
    int ordinalColumn; //序号所在列，一般为1
    int maxRow; //最大行数（从1开始算）
    int maxCol; //最大列数（从1开始算）
    bool showUselessRows; //是否展示无用列

public:
    QVector<QString> getColumnNames();
    int getColumnNameRow();
    int getDataStartRow();
    int getOrdinalColumn();

    void initFileConfig(const int& columnNameRow, const int& dataStartRow, const int& ordinalColumn);
    void readSheet(QXlsx::Document& assetDocument, const QString& sheetName);
    void readSheet(QXlsx::Worksheet* worksheet);
    void showSheet();

private:
    void setColumnNames(const QVector<QString>& columnNames);
    void initColumnName2IndexMap();

    void readColumnNames(QXlsx::Worksheet* worksheet);//根据第columnNameRow，确定widget的列名，展示到widget
    void initHeader();//初始化widget的头部各列内容

    void showCell(int row, int col);
    void showCell(int row, int col, const QVariant& variant);

//signals:

};

#endif // EXCELSHEET_H
