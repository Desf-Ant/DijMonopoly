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
#include <QOperatingSystemVersion>

#include "popupaddplayer.h"
#include "popupbuy.h"
#include "popuppayrent.h"
#include "board.h"
#include "player.h"
#include "case.h"
#include "popupcard.h"

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

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
    QGraphicsPixmapItem* cardInfo;
    QGraphicsTextItem* cardInfoOwner;
    QGraphicsTextItem* scoreDice;
    std::vector <QGraphicsPixmapItem*> cases;
    std::vector <QGraphicsRectItem*> physicalPlayers;
    std::vector <QGraphicsTextItem*> playersNames;
    std::vector <QGraphicsTextItem*> playersMoney;
    std::vector <QGraphicsTextItem*> playersNbProp;
    std::vector <QGraphicsTextItem*> playersPrisonCard;
    std::vector <QGraphicsRectItem*> playersRectUI;
    PopUpAddPlayer* popPlayer;
    PopUpBuyEstate* popBuyEstate;
    PopUpPayRent* popBuyRent;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startMainWindow(void);
    void refreshView();
    void popUpBuyEstate(Case* e);
    void popUpPayRent(Case* e, class Player* buyer, int sumDice=0);
private:
    //Ui::MainWindow *ui;
    void initComponents(void);
    void initLayout(void);
    void initSlots(void);
    void initCases(void);
    void initPlayer(void);
    void gameTurn(void);
    void setCardInfo(int num);

    void refreshDice(void);
    void refreshPlayerUI(void);
    void refreshPlayerPhysical(void);
public slots :
    void initPlayerUI(std::vector<std::string> names, std::vector<std::string> color);
    void receiveBuyEstate(bool answer);
    void whichCaseIsSelected(void);
};
#endif // MAINWINDOW_H
