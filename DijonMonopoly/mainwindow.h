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

#include "popupaddplayer.h"
#include "board.h"
#include "player.h"
#include "popupcard.h"

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    std::time_t t;

private:
    Board* board;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsRectItem* physicPlateau;
    QGraphicsPixmapItem* throwDiceBtn;
    QGraphicsTextItem* scoreDice;
    std::vector <QGraphicsPixmapItem*> cases;
    std::vector <QGraphicsRectItem*> physicalPlayers;
    std::vector <QGraphicsTextItem*> playersNames;
    std::vector <QGraphicsTextItem*> playersMoney;
    std::vector <QGraphicsTextItem*> playersNbProp;
    std::vector <QGraphicsTextItem*> playersPrisonCard;
    PopUpAddPlayer* popPlayer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startMainWindow(void);

private:
    //Ui::MainWindow *ui;
    void initComponents(void);
    void initLayout(void);
    void initSlots(void);
    void initCases(void);
    void initPlayer(void);
    void gameTurn(void);
    void refreshView();
    void refreshDice(void);
public slots :
    void initPlayerUI(std::vector<std::string> names);
    void whichCaseIsSelected(void);
};
#endif // MAINWINDOW_H
