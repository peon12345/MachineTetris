#include "usercar.h"
#include <QKeyEvent>

UserCar::UserCar(int widthRoad) :m_widthRoad (widthRoad)
{
  setFlag(QGraphicsItem::ItemIsFocusable, true); //делаем объект выделяемым
  setFocus(); //выделяем объект
  m_speed = 5;//установка скорости
}

void UserCar::initCar()
{
  m_pix.load(":/resources/images.png"); //загрузка изображения
  m_pix = m_pix.scaled(QSize(70,70) , Qt::IgnoreAspectRatio,Qt::SmoothTransformation);//установка размера изображения
  setPixmap(m_pix);//установка изображения
}

void UserCar::advance(int phase)
{
  Q_UNUSED(phase);
  if(collidingItems().size() > 1 ){ // проверка на столкновения,
                                   //метод QGrpahicsItem::collidingItems() возвращает список объектов столкновения
                                   // одно столкновение происходит с объектом класс Road(дорога),
                                   //если есть еще столкновения, значит мы столкнулись с машиной
    hide();                        //скрываем объект, если произошло столкновение
    emit carAccident();            //испускаем сигнал о столкновении
    }
}

void UserCar::keyPressEvent(QKeyEvent *event)
{
  switch (event->key()) {


    case Qt::Key_Left: // если нажата клавиша стрелка влево

      if(x() + m_speed > 0){ //проверка на выход за границы дороги
          moveBy(m_speed*-1,0); //если мы в пределах дороги, перемещаем машину влево по координате Х на значение переменной m_speed

        }
      break;

    case Qt::Key_Right:
      if(x() < m_widthRoad - m_pix.width()) //проверка на выход за границы дороги
       moveBy(m_speed,0); //если мы в пределах дороги, перемещаем машину вправо по координате Х на значение переменной m_speed
      break;
    }

 update();

}
