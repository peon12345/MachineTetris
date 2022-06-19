#ifndef ROADSCENE_H
#define ROADSCENE_H

#include <QGraphicsScene>

class CustomScene : public QGraphicsScene // дорога
{
public:
  CustomScene();
private:
  void initScene();

};

#endif // ROADSCENE_H
