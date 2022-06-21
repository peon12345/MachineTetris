#include "car.h"

Car::Car() : m_speed(3) //установка начального значения скорости
{

}

void Car::initCar()
{
  m_pix.load(":/resources/mycar.png"); //загружаем изображение
  m_pix = m_pix.scaled(QSize(70,70) , Qt::IgnoreAspectRatio,Qt::SmoothTransformation); //изменяем размер изображения
  setPixmap(m_pix); //устанавливаем изображение
}

void Car::advance(int phase)
{

//на первом этапе все элементы уведомляются о том,
//что сцена вот-вот изменится, а на втором этапе все элементы уведомляются о том, что они могут двигаться
//На первом этапе advance () вызывается, передавая в качестве аргумента значение 0
 if(phase) {
   moveBy(0,m_speed);
   }
}

void Car::setSpeed(int speed) //установка скорости
{
  m_speed = speed;
}
