#include <QApplication>
#include <QGraphicsView>
#include "roadScene.h"
#include <QScreen>

#include <road.h>
#include "car.h"


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QGraphicsView view;
  CustomScene roadScene;

  QRect screenSize = QApplication::primaryScreen()->geometry(); // получаем физические размеры экрана
  screenSize.setHeight(screenSize.height()/2);


  view.setFixedHeight(screenSize.height());
  view.setFixedWidth(500);
  view.setSceneRect(0,0,500,screenSize.height());

  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  Road* r = new Road(QSize(500,screenSize.height()));
  r->setPos(0,0);
  roadScene.addItem(r);

  Car* car = new Car;
  car->init();
  car->setPos(20,100);
 roadScene.addItem(car);


  view.setScene(&roadScene);
  view.show();

  return a.exec();
}
