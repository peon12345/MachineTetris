#include <QApplication>
#include <QGraphicsView>
#include "roadScene.h"
#include <QScreen>



int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QGraphicsView view;


 const int height = QApplication::primaryScreen()->geometry().height() / 2; // получаем физические размеры экрана
 const int width = 500;


  CustomScene roadScene(QSize(500,height));

  view.setFixedHeight(height);
  view.setFixedWidth(width);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  view.setScene(&roadScene);
  view.show();

  return a.exec();
}
