#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

class EntityClass{
  public:
  sf::Vector2i position, dimensions;
  float id;
  bool alive;
};

class BrickClass : public EntityClass{

  public:
  sf::RectangleShape shape(dimensions);

}

class BrickListClass : public BrickClass{

  public:
  BrickClass brick;
  BrickListClass *next_brick = NULL;
 
};
BrickListClass *brick_list = NULL;

class BallClass : public EntityClass{
  public:
  float radius;
  sf::CircleShape shape(radius);
  sf::Vector2f speed;

};
BallClass ball;

class PlatformClass : public EntityClass{
  public:
  sf::RectangleShape shape(dimensions);
  float horizontal_speed;
};
PlatformClass platform;

struct GameInfo{
  int lives, score;
};
GameInfo game;