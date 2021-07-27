#ifndef EXCELSHEETWIDGET_H
#define EXCELSHEETWIDGET_H

#include <QWidget>
#include <QTableWidget>

#include "xlsxdocument.h"

class ExcelSheetWidget : public QTableWidget
{
    typedef QMap<QString, size_t> MapS2I;
    typedef QMap<QString, size_t>::iterator IteratorS2I;
public:
    explicit ExcelSheetWidget(QWidget *parent = nullptr);

private:
    QVector<QString> columnNames;
    MapS2I columnName2Index;
    int columnNameRow; //列名所在行，一般为1
    int dataStartRow; //数据起始行，一般为2
    int ordinalColumn; //序号所在列，一般为1

public:
    QVector<QString> getColumnNames();
    int getColumnNameRow();
    int getDataStartRow();
    int getOrdinalColumn();

    void initAssetBookConfig(const int& columnNameRow, const int& dataStartRow, const int& ordinalColumn);
    void readSheet(QXlsx::Document& assetBookDocument, const QString& sheetName);

private:
    void setColumnNames(const QVector<QString>& columnNames);
    void initColumnName2IndexMap();
    void initHeader();

//signals:

};

#endif // EXCELSHEETWIDGET_H
