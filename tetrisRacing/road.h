#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Road : public QGraphicsPixmapItem
{
public:
  Road(const QSize& size); //конструктор принимающий размер дороги
private:
  QPixmap m_roadPix; //изображение дороги
};

#endif // ROAD_H
