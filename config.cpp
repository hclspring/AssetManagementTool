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

int Config::getAssetBookColumnNameRow() {
    return assetBookColumnNameRow;
}

int Config::getAssetBookDataStartRow() {
    return assetBookDataStartRow;
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
