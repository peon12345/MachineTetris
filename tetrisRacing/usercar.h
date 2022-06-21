#ifndef USERCAR_H
#define USERCAR_H

#include <QGraphicsPixmapItem>
#include "car.h"

class UserCar : public QObject, public Car
{
  Q_OBJECT
public:
  UserCar(int widthRoad); // конструктор принимающий ширину  дороги, чтобы не выходить за границы
  ~UserCar() override = default;

  void initCar() override; //переопределение метода, меняем цвет машины на зеленый
protected:
  void advance(int phase) override; // переопределение метода, проверяем на столкновения с объектами
  void keyPressEvent(QKeyEvent *event) override; //для обработки нажатия клавиши
signals:
  void carAccident(); //сигнал о столкновении
private:
  int m_widthRoad; //ширина дороги
};

#endif // USERCAR_H
