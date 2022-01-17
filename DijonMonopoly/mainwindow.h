#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget* centre;
    QRect* board;
    QVBoxLayout* vbox;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    void initComponents(void);
    void initLayout(void);
};
#endif // MAINWINDOW_H
