#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__ 1
#include <SFML/Graphics.hpp>

const int kScreenWidth = 800;
const int kScreenHeight = 900;

struct hitbox {
  float x1,y1,x2,y2;
};

class EntityClass{
  protected:
  sf::RectangleShape shape;
  int id;
  bool alive;

  public:

  sf::RectangleShape getShape();

  void setShape(sf::RectangleShape shape);

  int getId();

  void setId(int id);

  bool getAlive();

  void setAlive(bool alive = true);
};

#endif
