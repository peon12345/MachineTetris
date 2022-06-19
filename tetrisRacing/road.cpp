#include "road.h"

Road::Road(const QSize &size)
{
  m_roadPix.load("://resources/road_0.png");
  m_roadPix = m_roadPix.scaled(size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
  setPixmap(m_roadPix);
}
