#ifndef ROADSCENE_H
#define ROADSCENE_H

#include <QGraphicsScene>
#include "gameplay.h"
#include "usercar.h"
#include <QPushButton>

class CustomScene : public QGraphicsScene
{
public:
  CustomScene(const QSize& size); //конструктор принимающий размер сцены

private:
  void addObjects(); // для добавления машины игрока, дороги и кнопок для старта игры
  void setSize(const QSize& size); //установка размера сцены
private slots:
  void showItem(QGraphicsItem *item); //слот для добавления объекта(машины) на сцену, вызывается когда класс gameplay создает машину
private:

  static constexpr int MSEC_ADVANCE = 200; //частота обновления элементов сцены, для вызыва метода advance у каждого элемента
  QTimer m_timerAdvance; //таймер для вызовa метода advance у объектов сцены
  Gameplay m_gameplay; //класс для добавления машин и изменения их скорости
  UserCar* m_car; //машина игрока
  QPushButton* m_buttonStart; //кнопка старт игры
  QPushButton* m_buttonExit; //кнопка выход
};

#endif // ROADSCENE_H
