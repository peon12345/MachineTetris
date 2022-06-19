#include "car.h"

Car::Car() : m_speed(-1)
{
  m_pix.load(":/resources/mycar.png");
  m_pix = m_pix.scaled(QSize(100,100) , Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
  setPixmap(m_pix);
}

void Car::advance(int phase)
{
 if(phase) {
   moveBy(0,m_speed);
   }
}
