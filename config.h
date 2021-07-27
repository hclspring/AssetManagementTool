#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QVector>
#include <vector>

class Config
{
    typedef QMap<QString, size_t> MapS2I;
    typedef QMap<QString, size_t>::iterator IteratorS2I;
public:
    Config();

public:
    void saveConfigValues();

    QString getAssetBookFilename();
    QString getFixedAssetSheetName();
    QString getInvisibleAssetSheetName();
    QVector<QString> getFixedAssetColumnNames();
    QVector<QString> getInvisibleAssetColumnNames();
    int getFixedAssetColumnIndex(const QString& columnName);
    int getInvisibleAssetColumnIndex(const QString& columnName);
    int getAssetBookColumnNameRow();
    int getAssetBookDataStartRow();

private:
    QString configFilename {"config.ini"};
    QString assetBookFilename {"D:\\QtProjects\\示例\\第2步.资产台账模板（大表）.xlsx"};
    QString fixedAssetSheetName {"硬件"};
    QString invisibleAssetSheetName {"软件"};
    QVector<QString> fixedAssetColumnNames {"卡片编号","实物资产编号","序列号","资产名称","使用人"};
    QVector<QString> invisibleAssetColumnNames {"卡片编号","实物资产编号","资产名称","使用人"};
    MapS2I fixedAssetColumnName2Index;
    MapS2I invisibleAssetColumnName2Index;
    int assetBookColumnNameRow {1};
    int assetBookDataStartRow {5};

private:
    void setDefaultValues();
    void initDefaultFixedAssetMap();
    void initDefaultInvisibleAssetMap();
};

#endif // CONFIG_H
