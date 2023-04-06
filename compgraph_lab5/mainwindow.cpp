#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->GLwidget->radius = float(value)/10.0f;
    QTextStream out(stdout);

     out <<  ui->GLwidget->radius << endl;
}

void MainWindow::on_leopardButton_clicked()
{
    ui->GLwidget->img.load(":./assets/an.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}

void MainWindow::on_boatButton_clicked()
{
    ui->GLwidget->img.load(":./assets/boat.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}

void MainWindow::on_butterflyButton_clicked()
{
    ui->GLwidget->img.load(":./assets/butterfly.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}

void MainWindow::on_CandleButton_clicked()
{
    ui->GLwidget->img.load(":./assets/candle.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}

void MainWindow::on_fireButton_clicked()
{
    ui->GLwidget->img.load(":./assets/fire.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}

void MainWindow::on_fishButton_clicked()
{
    ui->GLwidget->img.load(":./assets/fish.jpg");
    ui->GLwidget->texture->setData(ui->GLwidget->img);
}
