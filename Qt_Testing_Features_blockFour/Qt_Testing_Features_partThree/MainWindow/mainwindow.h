#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonReturn_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButtonAddLang_clicked();
    void on_pushButtonDropLang_clicked();
    void on_checkBoxForIcons_clicked();

private:
    int position_right_now , position_prev;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
