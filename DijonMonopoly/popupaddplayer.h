#ifndef POPUPADDPLAYER_H
#define POPUPADDPLAYER_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

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
    QGridLayout* gridLayout;
    QLabel* p1;
    QLabel* p2;
    QLabel* p3;
    QLabel* p4;
    QLabel* piece1;
    QLabel* piece2;
    QLabel* piece3;
    QLabel* piece4;
    QLineEdit* player1;
    QLineEdit* player2;
    QLineEdit* player3;
    QLineEdit* player4;
    QComboBox* liste_deroulante1;
    QComboBox* liste_deroulante2;
    QComboBox* liste_deroulante3;
    QComboBox* liste_deroulante4;
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
