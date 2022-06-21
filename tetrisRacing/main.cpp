#include <QApplication>
#include <QGraphicsView>
#include "roadScene.h"
#include <QScreen>



int main(int argc, char *argv[])
{
  QApplication a(argc, argv);




  const int height = QApplication::primaryScreen()->geometry().height() / 2; // получаем высоту экрана
  const int width = 500; //ширина окна


  CustomScene customScene(QSize(width,height)); //сцена для управления 2D элементами

  QGraphicsView view; // виджет для отображения содержимого сцены
  view.setFixedHeight(height); // устанавливаем фиксированную высоту виджета
  view.setFixedWidth(width);// устанавливаем фиксированную ширину виджета
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключем скролл у виджета
  view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  view.setScene(&customScene); //устанавливаем виджету сцену для отображения
  view.show(); // показываем виджет

  return a.exec();
}
