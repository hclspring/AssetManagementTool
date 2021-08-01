#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QFileDialog>

#include "constant.h"

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();

private:
    Ui::FileDialog *ui;
    QString filePath;
    AssetType assetType;
    FormType formType;
    bool hasFilePath {false};
    bool hasAssetType {false};
    bool hasFormType {false};

public:
    AssetType getAssetType() const;
    void setAssetType(AssetType newAssetType);

    FormType getFormType() const;
    void setFormType(FormType newFormType);

    const QString &getFilePath() const;
    void setFilePath(const QString &newFilePath);

private slots:
    void setAssetTypeOnClick();
    void setFormTypeOnClick();
    void on_browseButton_clicked();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_FileDialog_finished(int result);

private:
    void enableFinishButtonBox();
};

#endif // FILEDIALOG_H
