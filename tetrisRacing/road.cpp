#include "road.h"

Road::Road(const QSize &size)
{
  m_roadPix.load("://resources/road_0.png"); //загрузка изображения дороги
  m_roadPix = m_roadPix.scaled(size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation); //установка размера изображения
  setPixmap(m_roadPix); //установка изображения
}
