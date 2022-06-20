#include "usercar.h"
#include <QKeyEvent>

UserCar::UserCar(int widthRoad) :m_widthRoad (widthRoad)
{
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFocus();
  m_speed = 5;
}

void UserCar::initCar()
{
  m_pix.load(":/resources/images.png");
  m_pix = m_pix.scaled(QSize(70,70) , Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
  setPixmap(m_pix);
}

void UserCar::advance(int phase)
{

  if(collidingItems().size() > 1 ){
    hide();
    emit carAccident();
    }
}

void UserCar::keyPressEvent(QKeyEvent *event)
{
  switch (event->key()) {


    case Qt::Key_Left:

      if(x() + m_speed > 0){
          moveBy(m_speed*-1,0);

        }
      break;

    case Qt::Key_Right:
      if(x() < m_widthRoad - m_pix.width())
       moveBy(m_speed,0);
      break;
    }

 update();

}
