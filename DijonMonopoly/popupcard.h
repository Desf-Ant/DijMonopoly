#ifndef POPUPCARD_H
#define POPUPCARD_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QImage>
#include <QLabel>

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
    QLabel* label;
    // QImage* image;
public:
    PopUpCard(QWidget *parent);
private :
    void initComponent(void);
    void initLayout(void);
    void initSlots(void);

};

#endif // POPUPCARD_H
