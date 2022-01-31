#ifndef POPUPBUYGARE_H
#define POPUPBUYGARE_H

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

#include "gare.h"
#include "player.h"

class PopUpBuyGare: public QMainWindow
{
    Q_OBJECT
private:
    QWidget* parent;
    class Gare* gare;
    Player* p;
private:
    QWidget* centre;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* yesButton;
    QPushButton* noButton;
    QLabel* label;
public:
    PopUpBuyGare(QWidget *parent, class Gare* g, Player* p);
private:
    void initComponent(void);
    void initLayout(void);
    void initSlot(void);
signals :
    void answerBuyGare(bool);
public slots:
    void falseReturn(void);
    void trueReturn(void);
};

#endif // POPUPBUYGARE_H
