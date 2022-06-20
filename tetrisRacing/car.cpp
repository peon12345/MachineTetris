#include "car.h"

Car::Car() : m_speed(3)
{


}

void Car::initCar()
{
  m_pix.load(":/resources/mycar.png");
  m_pix = m_pix.scaled(QSize(70,70) , Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
  setPixmap(m_pix);
}

void Car::advance(int phase)
{
 if(phase) {
   moveBy(0,m_speed);
   }
}

void Car::setSpeed(int speed)
{
  m_speed = speed;
}
