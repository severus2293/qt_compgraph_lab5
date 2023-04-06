#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_leopardButton_clicked();

    void on_boatButton_clicked();

    void on_butterflyButton_clicked();

    void on_CandleButton_clicked();

    void on_fireButton_clicked();

    void on_fishButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
