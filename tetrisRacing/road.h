#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Road : public QGraphicsPixmapItem
{
public:
  Road(const QSize& size);
private:
  QPixmap m_roadPix;
};

#endif // ROAD_H
