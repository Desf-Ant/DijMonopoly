#ifndef POPUPPAYRENT_H
#define POPUPPAYRENT_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

#include "estate.h"
#include "player.h"

#include <string>

class PopUpPayRent : public QMainWindow
{
    Q_OBJECT
public:
    PopUpPayRent(class Estate* e, class Player* buyer);
private:
    void initComponents(void);
    void initLayout(void);
private:
    QWidget* centre;
    QPushButton* okBtn;
    QLabel* label;
    QVBoxLayout* vbox;
private:
    std::string ownerName;
    std::string buyerName;
    int price;
};

#endif // POPUPPAYRENT_H
