#include "config.h"

Config::Config()
{
    QFileInfo fileinfo(configFilename);
    if (!fileinfo.exists()) {
        qDebug() << "Config file " << configFilename << "NOT exists.";
        setDefaultValues();
    }
}


void Config::saveConfigValues()
{

}

QString Config::getAssetBookFilename()
{
    return assetBookFilename;
}

QString Config::getFixedAssetSheetName()
{
    return fixedAssetSheetName;
}

QString Config::getInvisibleAssetSheetName()
{
    return invisibleAssetSheetName;
}

QVector<QString> Config::getFixedAssetColumnNames()
{
    return fixedAssetColumnNames;
}

QVector<QString> Config::getInvisibleAssetColumnNames()
{
    return invisibleAssetColumnNames;
}


int Config::getFixedAssetColumnIndex(const QString& columnName)
{
    IteratorS2I iter = fixedAssetColumnName2Index.find(columnName);
    if (iter == fixedAssetColumnName2Index.end()) {
        return -1;
    } else {
        return iter.value();
    }
}

int Config::getInvisibleAssetColumnIndex(const QString& columnName)
{
    IteratorS2I iter = invisibleAssetColumnName2Index.find(columnName);
    if (iter == invisibleAssetColumnName2Index.end()) {
        return -1;
    } else {
        return iter.value();
    }
}

int Config::getBookTableColumnNameRow() {
    return bookTableColumnNameRow;
}

int Config::getBookTableDataStartRow() {
    return bookTableDataStartRow;
}

int Config::getBookTableOrdinalColumn() {
    return bookTableOrdinalColumn;
}

int Config::getDetailTableColumnNameRow() const
{
    return detailTableColumnNameRow;
}

int Config::getDetailTableDataStartRow() const
{
    return detailTableDataStartRow;
}

int Config::getDetailTableOrdinalColumn() const
{
    return detailTableOrdinalColumn;
}

int Config::getAssetTableColumnNameRow() const
{
    return assetTableColumnNameRow;
}

int Config::getAssetTableDataStartRow() const
{
    return assetTableDataStartRow;
}

int Config::getAssetTableOrdinalColumn() const
{
    return assetTableOrdinalColumn;
}

int Config::getCmdbTableColumnNameRow() const
{
    return cmdbTableColumnNameRow;
}

int Config::getCmdbTableDataStartRow() const
{
    return cmdbTableDataStartRow;
}

int Config::getCmdbTableOrdinalColumn() const
{
    return cmdbTableOrdinalColumn;
}

void Config::setDefaultValues()
{

}

void Config::initDefaultFixedAssetMap()
{
    for (int i = 0; i < fixedAssetColumnNames.size(); ++i)
    {
        fixedAssetColumnName2Index.insert(fixedAssetColumnNames[i], i);
    }
}

void Config::initDefaultInvisibleAssetMap()
{
    for (int i = 0; i < invisibleAssetColumnNames.size(); ++i)
    {
        invisibleAssetColumnName2Index.insert(invisibleAssetColumnNames[i], i);
    }
}
