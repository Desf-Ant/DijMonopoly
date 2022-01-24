#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("Dij'Monop");
    this->setGeometry(0,0,1400,840);
    this->setFixedSize(this->size());
    this->initComponents();
    this->initLayout();
    this->initCases();
}

MainWindow::~MainWindow()
{
    delete(this->scene);
    delete(this->view);
}


void MainWindow::initComponents() {
    this->scene = new QGraphicsScene();
    this->view = new QGraphicsView(this->scene);
    this->scene->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
    QPen blackPen(Qt::black);
    QBrush greenBrush(QColor(210,230,210));
    this->physicPlateau = this->scene->addRect(0,0,834,834, blackPen,greenBrush);
    this->physicPlateau->setPos(283,3);
    QGraphicsTextItem* monopolyText = new QGraphicsTextItem("DIJ' MONOP");
    monopolyText->setScale(8);
    monopolyText->setPos(410,575);
    monopolyText->setRotation(-45);
    this->scene->addItem(monopolyText);
}

void MainWindow::initLayout() {
    this->setCentralWidget(this->view);
}

void MainWindow::initCases() {
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/depart.png")));
    this->cases[0]->setPos(997,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/vergy.png")));
    this->cases[1]->setPos(931,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[2]->setPos(865,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/savoirs.png")));
    this->cases[3]->setPos(799,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/impot.png")));
    this->cases[4]->setPos(733,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret1.png")));
    this->cases[5]->setPos(667,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/dubois.png")));
    this->cases[6]->setPos(601,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[7]->setPos(535,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/marmuzots.png")));
    this->cases[8]->setPos(469,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/vannerie.png")));
    this->cases[9]->setPos(403,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prison.png")));
    this->cases[10]->setPos(283,717);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/sully.png")));
    this->cases[11]->setPos(403,651);
    this->cases[11]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/edf.png")));
    this->cases[12]->setPos(403,585);
    this->cases[12]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gabriel.png")));
    this->cases[13]->setPos(403,519);
    this->cases[13]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/auxonne.png")));
    this->cases[14]->setPos(403,453);
    this->cases[14]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret2.png")));
    this->cases[15]->setPos(403,387);
    this->cases[15]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/berbisey.png")));
    this->cases[16]->setPos(403,321);
    this->cases[16]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/charrue.png")));
    this->cases[17]->setPos(403,255);
    this->cases[17]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[18]->setPos(403,189);
    this->cases[18]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/zola.png")));
    this->cases[19]->setPos(403,123);
    this->cases[19]->setRotation(90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/parc.png")));
    this->cases[20]->setPos(283,3);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/cazotte.png")));
    this->cases[21]->setPos(469,123);
    this->cases[21]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[22]->setPos(535,123);
    this->cases[22]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/danton.png")));
    this->cases[23]->setPos(601,123);
    this->cases[23]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/tivoli.png")));
    this->cases[24]->setPos(667,123);
    this->cases[24]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret3.png")));
    this->cases[25]->setPos(733,123);
    this->cases[25]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/thiers.png")));
    this->cases[26]->setPos(799,123);
    this->cases[26]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/carnot.png")));
    this->cases[27]->setPos(865,123);
    this->cases[27]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/suez.png")));
    this->cases[28]->setPos(931,123);
    this->cases[28]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/octobre.png")));
    this->cases[29]->setPos(997,123);
    this->cases[29]->setRotation(180);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prison2.png")));
    this->cases[30]->setPos(997,3);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/prefecture.png")));
    this->cases[31]->setPos(997,189);
    this->cases[31]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/godrans.png")));
    this->cases[32]->setPos(997,255);
    this->cases[32]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/gouv.png")));
    this->cases[33]->setPos(997,321);
    this->cases[33]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/hugo.png")));
    this->cases[34]->setPos(997,387);
    this->cases[34]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/arret4.png")));
    this->cases[35]->setPos(997,453);
    this->cases[35]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/chance.png")));
    this->cases[36]->setPos(997,519);
    this->cases[36]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/tremouille.png")));
    this->cases[37]->setPos(997,585);
    this->cases[37]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/lafayette.png")));
    this->cases[38]->setPos(997,651);
    this->cases[38]->setRotation(-90);
    this->cases.push_back(this->scene->addPixmap(QPixmap("../../../../Cases/liberte.png")));
    this->cases[39]->setPos(997,717);
    this->cases[39]->setRotation(-90);
}
