#include "filedialog.h"
#include "ui_filedialog.h"

FileDialog::FileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
    connect(ui->fixedAssetButton, SIGNAL(clicked()), this, SLOT(setAssetTypeOnClick()));
    connect(ui->invisibleAssetButton, SIGNAL(clicked()), this, SLOT(setAssetTypeOnClick()));
    connect(ui->bookTypeButton, SIGNAL(clicked()), this, SLOT(setFormTypeOnClick()));
    connect(ui->cmdbTypeButton, SIGNAL(clicked()), this, SLOT(setFormTypeOnClick()));
    connect(ui->detailTypeButton, SIGNAL(clicked()), this, SLOT(setFormTypeOnClick()));
    connect(ui->assetTypeButton, SIGNAL(clicked()), this, SLOT(setFormTypeOnClick()));
    connect(ui->otherTypeButton, SIGNAL(clicked()), this, SLOT(setFormTypeOnClick()));
    ui->buttonBox->setDisabled(true);
    //ui->buttonBox->setEnabled(true);
}

FileDialog::~FileDialog()
{
    delete ui;
}

const QString &FileDialog::getFilePath() const
{
    return filePath;
}

void FileDialog::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
    hasFilePath = true;
    enableFinishButtonBox();
}

FormType FileDialog::getFormType() const
{
    return formType;
}

void FileDialog::setFormType(FormType newFormType)
{
    formType = newFormType;
    hasFormType = true;
    enableFinishButtonBox();
}


AssetType FileDialog::getAssetType() const
{
    return assetType;
}

void FileDialog::setAssetType(AssetType newAssetType)
{
    assetType = newAssetType;
    hasAssetType = true;
    enableFinishButtonBox();
}

void FileDialog::setAssetTypeOnClick()
{
    if (ui->fixedAssetButton->isChecked()) {
        setAssetType(FIXED);
        //qDebug() << "固定资产";
    } else if (ui->invisibleAssetButton->isChecked()) {
        setAssetType(INVISIBLE);
        //qDebug() << "无形资产";
    }
}

void FileDialog::setFormTypeOnClick()
{
    if (ui->bookTypeButton->isChecked()) {
        setFormType(BOOKFORM);
    } else if (ui->detailTypeButton->isChecked()) {
        setFormType(DETAILFORM);
    } else if (ui->assetTypeButton->isChecked()) {
        setFormType(ASSETFORM);
    } else if (ui->cmdbTypeButton->isChecked()) {
        setFormType(CMDBFORM);
    } else if (ui->otherTypeButton->isChecked()) {
        setFormType(OTHERFORM);
    }
}

void FileDialog::on_browseButton_clicked()
{
    setFilePath(QFileDialog::getOpenFileName(this,"选择单个文件","./"));
    ui->filePathEdit->setText(filePath);
}


void FileDialog::on_buttonBox_rejected()
{
    setFilePath("");
}


void FileDialog::on_buttonBox_accepted()
{
    return;
}


void FileDialog::on_FileDialog_finished(int result)
{
    if (result) {
        return on_buttonBox_accepted();
    } else {
        return on_buttonBox_rejected();
    }
}

void FileDialog::enableFinishButtonBox()
{
    if (hasFilePath && hasAssetType && hasFormType) {
        ui->buttonBox->setEnabled(true);
    }
}

