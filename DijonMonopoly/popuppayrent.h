#ifndef POPUPPAYRENT_H
#define POPUPPAYRENT_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

#include "enumHelper.h"
#include "case.h"
#include "player.h"

#include <string>
#include <ostream>

class PopUpPayRent : public QMainWindow
{
    Q_OBJECT
public:
    PopUpPayRent(Case* e, class Player* buyer, int sumDice=0);
private:
    void initComponents(void);
    void initLayout(void);
    void initSlots(void);
private:
    QWidget* centre;
    QPushButton* okBtn;
    QLabel* label;
    QVBoxLayout* vbox;
private:
    std::string ownerName;
    std::string buyerName;
    std::string caseName;
    int price;
    int sumDice;
public slots :
    void closeWindow(void);
};

#endif // POPUPPAYRENT_H
