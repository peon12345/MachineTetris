#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>



class Car : public QGraphicsPixmapItem
{
public:
  Car(); //конструктор по умолчанию
  virtual ~Car() = default; //виртуальный декструктор,для корректного освобождения памяти
public:
  virtual void initCar(); //инициализация машины( устанавливаем изображение\размеры)
  void advance(int phase) override; //перемещает машину на один шаг
  void setSpeed(int speed); // установка скорости (какое расстояние машина проходит за один шаг)
protected:
  int m_speed; //cкорость
  QPixmap m_pix; // изображение машины
};

#endif // CAR_H
