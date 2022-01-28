#ifndef POPUPADDPLAYER_H
#define POPUPADDPLAYER_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

#include <iostream>
#include <vector>
#include <string>

class PopUpAddPlayer : public QMainWindow
{
    Q_OBJECT
private :
    QWidget* parent;
private :
    QWidget* centre;
    QFormLayout* formLayout;
    QLineEdit* player1;
    QLineEdit* player2;
    QLineEdit* player3;
    QLineEdit* player4;
    QPushButton* button;
public:
    PopUpAddPlayer(QWidget *parent);
private :
    void initComponent(void);
    void initLayout(void);
    void initSlots(void);
signals :
    void newPlayerSignal(std::vector<std::string>);
public slots:
    void preparePlayer(void);
};

#endif // POPUPADDPLAYER_H
