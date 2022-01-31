#ifndef POPUPBUYESTATE_H
#define POPUPBUYESTATE_H

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

#include "estate.h"
#include "player.h"

class PopUpBuyEstate: public QMainWindow
{
    Q_OBJECT
private:
    QWidget* parent;
    class Estate* estate;
    Player* p;
private:
    QWidget* centre;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* yesButton;
    QPushButton* noButton;
    QLabel* label;
public:
    PopUpBuyEstate(QWidget *parent, class Estate* e, Player* p);
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

#endif // POPUPBUYESTATE_H
