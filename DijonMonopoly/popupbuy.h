#ifndef POPUPBUY_H
#define POPUPBUY_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QString>

#include <ostream>
#include <string>

#include "case.h"
#include "player.h"

class PopUpBuyEstate: public QMainWindow
{
    Q_OBJECT
private:
    QWidget* parent;
    Case* estate;
    Player* p;
    std::string pathImage;
private:
    QWidget* centre;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* yesButton;
    QPushButton* noButton;
    QLabel* label;
    QLabel* labelCard;
public:
    PopUpBuyEstate(QWidget *parent, Case* e, Player* p);
private:
    void initComponent(void);
    void initLayout(void);
    void initSlot(void);
signals :
    void answerBuyEstate(bool);
public slots:
    void falseReturn(void);
    void trueReturn(void);
};

#endif // POPUPBUY_H
