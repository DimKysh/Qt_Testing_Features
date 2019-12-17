#include "MainWindow.hpp"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QDialog(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);

    ui->listWidget->addItem(new QListWidgetItem(QIcon(":/rec/images/calculator.ico"),"Calculator"));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(":/rec/images/control_panel.ico"),"Control Panel"));

    ui->listWidget->setIconSize(QSize(64,64));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonReturn_clicked()
{
    close();
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    auto flag = item->flags();
    position_right_now = ui->listWidget->currentRow();

    flag.setFlag(Qt::ItemIsEditable, true).setFlag(Qt::ItemIsEnabled, true);

    item->setFlags(flag);

    if(position_right_now != position_prev)
    {
        flag.setFlag(Qt::ItemIsEditable, false);
        item->setFlags(flag);
        position_prev = position_right_now;
    }
}

void MainWindow::on_pushButtonAddLang_clicked()
{
    position_right_now = ui->listWidget->currentRow();

    if(QSysInfo::productType() == "windows")
    {
        if(position_right_now == 0)
        {
            system("calc");
        }
        if(position_right_now == 1)
        {
            system("control panel");
        }
    }
}
