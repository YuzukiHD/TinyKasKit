#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "bootPack.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    paddingMap.insert("512 (Block)", 512);
    paddingMap.insert("8192 (8K Flash)", 8192);

    auto paddingMapKeys = paddingMap.keys();
    for (const auto &i: paddingMapKeys)
        ui->padding_comboBox->addItem(i);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_file_path_pushButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image File"), "",
                                                    tr("All files (*.*);;IMAGE (*.img *.IMG);;Binary (*.bin);;ELF (*.elf)"));
    ui->file_path_lineEdit->setText(fileName);
}

void MainWindow::on_save_pushButton_clicked() {
    try {
        bootPack bootPack_(ui->file_path_lineEdit->text(),
                 ui->file_path_lineEdit->text() + "da",
                 paddingMap[ui->padding_comboBox->currentText()]);
        QMessageBox::information(this, "Success", "Success");
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Warning", e.what());
    }
}

