#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QPixmap>
#include <QPalette>
#include <QColor>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsItemGroup>

#include <iostream>
#include <vector>
#include <map>
#include <QGraphicsSceneMouseEvent>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsRectItem* physicPlateau;
    std::vector <QGraphicsPixmapItem*> cases;
    std::vector <std::map <std::string, QGraphicsTextItem>> playersUI;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    void initComponents(void);
    void initLayout(void);
    void initCases(void);
    void initPlayerUI(void);
};
#endif // MAINWINDOW_H
