#include "excelsheet.h"
#include "util.h"


ExcelSheet::ExcelSheet()
{
}

ExcelSheet::ExcelSheet(QTableWidget* tableWidget)
{
    this->tableWidget = tableWidget;
}


QVector<QString> ExcelSheet::getColumnNames() {
    return columnNames;
}

int ExcelSheet::getColumnNameRow() {
    return columnNameRow;
}

int ExcelSheet::getDataStartRow() {
    return dataStartRow;
}

int ExcelSheet::getOrdinalColumn() {
    return ordinalColumn;
}


void ExcelSheet::initFileConfig(const int& columnNameRow, const int& dataStartRow, const int& ordinalColumn)
{
    this->columnNameRow = columnNameRow;
    this->dataStartRow = dataStartRow;
    this->ordinalColumn = ordinalColumn;
    this->showUselessRows = false;
}

void ExcelSheet::readSheet(QXlsx::Document& assetDocument, const QString& sheetName)
{
    assetDocument.selectSheet(sheetName);
    QXlsx::AbstractSheet* sheet = assetDocument.sheet(sheetName);
    QXlsx::Worksheet* worksheet = (QXlsx::Worksheet*) sheet;
    readSheet(worksheet);
}

void ExcelSheet::readSheet(QXlsx::Worksheet* worksheet)
{
    worksheet->getFullCells(&maxRow, &maxCol);
    qDebug() << maxRow << "行，" << maxCol << "列";
    QVector<QVariant> row;
    row.resize(maxCol);
    sheetContent.fill(row, maxRow);
    for (int r = 1; r <= maxRow; ++r) {
        for (int c = 1; c <= maxCol; ++c) {
            sheetContent[r-1][c-1] = worksheet->read(r, c);
        }
    }
    readColumnNames(worksheet);
}

void ExcelSheet::showSheet()
{
    tableWidget->setColumnCount(maxCol);
    tableWidget->setRowCount(maxRow);
    initHeader();
    for (int r = 1; r <= maxRow; ++r) {
        for (int c = 1; c <= maxCol; ++c) {
            showCell(r-1, c-1);
        }
    }
    if (!showUselessRows) {
        for (int i = getColumnNameRow()+1; i < getDataStartRow(); ++i) {
            tableWidget->hideRow(i-1);
        }
    }
    tableWidget->hideRow(0);
}


void ExcelSheet::setColumnNames(const QVector<QString>& columnNames) {
    this->columnNames = columnNames;
    initColumnName2IndexMap();
}

void ExcelSheet::initColumnName2IndexMap() {
    columnName2Index.clear();
    for (int i = 0; i < columnNames.size(); ++i) {
        columnName2Index.insert(columnNames[i], i);
    }
}

void ExcelSheet::readColumnNames(QXlsx::Worksheet* worksheet)
{
    QVector<QString> columnNames(maxCol);
    for (int i = 1; i <= maxCol; ++i) {
        columnNames[i-1] = worksheet->read(getColumnNameRow(), i).toString();
    }
    setColumnNames(columnNames);
}

void ExcelSheet::initHeader() {
    if (maxCol <= 0) return;
    for (int i = 0; i< columnNames.size(); ++i) {
        QString headString = "[" + Util::genColumnNumber(i) + "]" + columnNames[i];
        QTableWidgetItem* headerItem = new QTableWidgetItem(headString);
        qDebug() << i << headString;
        QFont headerFont = headerItem->font();
        headerFont.setBold(true);
        tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
}

void ExcelSheet::showCell(int row, int col)
{
    if (row >= 0 && row < sheetContent.size()
            && col >= 0 && col < sheetContent[row].size()) {
        showCell(row, col, sheetContent[row][col]);
    } else {
        qDebug() << "sheetContent[" << row << "][" << col << "]不存在。";
    }
}

void ExcelSheet::showCell(int row, int col, const QVariant& variant)
{
    QTableWidgetItem* item = new QTableWidgetItem(variant.toString());
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //文本对齐格式
    tableWidget->setItem(row, col, item);
}

