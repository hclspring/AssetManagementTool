#include "excelsheetwidget.h"

ExcelSheetWidget::ExcelSheetWidget(QWidget *parent) : QTableWidget(parent)
{

}


QVector<QString> ExcelSheetWidget::getColumnNames() {
    return columnNames;
}

int ExcelSheetWidget::getColumnNameRow() {
    return columnNameRow;
}

int ExcelSheetWidget::getDataStartRow() {
    return dataStartRow;
}

int ExcelSheetWidget::getOrdinalColumn() {
    return ordinalColumn;
}


void ExcelSheetWidget::initAssetBookConfig(const int& columnNameRow, const int& dataStartRow, const int& ordinalColumn)
{
    this->columnNameRow = columnNameRow;
    this->dataStartRow = dataStartRow;
    this->ordinalColumn = ordinalColumn;
}

void ExcelSheetWidget::readSheet(QXlsx::Document& assetBookDocument, const QString& sheetName)
{
    //TODO
}


void ExcelSheetWidget::setColumnNames(const QVector<QString>& columnNames) {
    this->columnNames = columnNames;
    initColumnName2IndexMap();
}

void ExcelSheetWidget::initColumnName2IndexMap() {
    columnName2Index.clear();
    for (int i = 0; i < columnNames.size(); ++i) {
        columnName2Index.insert(columnNames[i], i);
    }
}

void ExcelSheetWidget::initHeader() {
    this->setColumnCount(columnNames.size());
    for (int i = 0; i< columnNames.size(); ++i) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(columnNames[i]);
        QFont headerFont = headerItem->font();
        headerFont.setBold(true);
        this->setHorizontalHeaderItem(i, headerItem);
    }
}
