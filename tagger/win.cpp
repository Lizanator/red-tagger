#include "win.h"
#include "ui_win.h"
#include <QFileDialog>
#include<string>
#include "tagger.h"
QString dir;
win::win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
}

win::~win()
{
    delete ui;
}

void win::on_toolButton_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
        ui->foldername->setText(dir);
}

void win::on_commandLinkButton_clicked()
{
    std::string foldername = dir.toStdString();
    std::string tag_value = ui->tag_textedit->text().toStdString();
    tagger myTagger(foldername,tag_value);
    myTagger.start();
}
