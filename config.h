#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QVector>
#include <vector>

class Config
{
    typedef QMap<QString, size_t> MapS2I;//没用，待删
    typedef QMap<QString, size_t>::iterator IteratorS2I;//没用，待删
public:
    Config();

public:
    void saveConfigValues();

    QString getAssetBookFilename();
    QString getFixedAssetSheetName();//没用，待删
    QString getInvisibleAssetSheetName();//没用，待删
    QVector<QString> getFixedAssetColumnNames();//没用，待删
    QVector<QString> getInvisibleAssetColumnNames();//没用，待删
    int getFixedAssetColumnIndex(const QString& columnName); //没用，待删
    int getInvisibleAssetColumnIndex(const QString& columnName);//没用，待删
    int getAssetBookColumnNameRow();
    int getAssetBookDataStartRow();
    int getAssetBookOrdinalColumn();

private:
    QString configFilename {"config.ini"};
    QString assetBookFilename {"D:\\QtProjects\\示例\\第2步.资产台账模板（大表）.xlsx"};
    QString fixedAssetSheetName {"硬件"}; //没用，待删
    QString invisibleAssetSheetName {"软件"}; //没用，待删
    QVector<QString> fixedAssetColumnNames {"卡片编号","实物资产编号","序列号","资产名称","使用人"}; //没用，待删
    QVector<QString> invisibleAssetColumnNames {"卡片编号","实物资产编号","资产名称","使用人"}; //没用，待删
    MapS2I fixedAssetColumnName2Index; //没用，待删
    MapS2I invisibleAssetColumnName2Index; //没用，待删
    int assetBookColumnNameRow {1};
    int assetBookDataStartRow {5};
    int assetBookOrdinalColumn {1};

private:
    void setDefaultValues();
    void initDefaultFixedAssetMap();//没用，待删
    void initDefaultInvisibleAssetMap();//没用，待删
};

#endif // CONFIG_H
