#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_file_path_pushButton_clicked();

    void on_save_pushButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    QMap<QString, int> paddingMap;
};
#endif // MAINWINDOW_H
