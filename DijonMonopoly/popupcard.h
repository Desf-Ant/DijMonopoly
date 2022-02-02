#ifndef POPUPCARD_H
#define POPUPCARD_H

#include "drawCard.h"

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QString>
#include "drawCard.h"

#include <iostream>
#include <vector>
#include <string>

class PopUpCard : public QMainWindow
{
    Q_OBJECT
private :
    QWidget* centre;
    QFormLayout* formLayout;
    QPushButton* button;
    QLine* phrase;
    QLabel* label;
public:
    PopUpCard(QWidget *parent, typeDrawCard type);
private :
    void initComponent(void);
    void initLayout(void);
    void initSlots(void);

public slots :
    void quit (void);

};

#endif // POPUPCARD_H

