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
//  EntityClass(sf::Vector2i, sf::Vector2i, float, bool);
  
};

class BrickClass : public EntityClass{

  public:

//  EntityClass brick_entity( (0, 0), (72, 30), 3, true);

  BrickClass(sf::Vector2i, sf::Vector2i, float, bool);
  sf::RectangleShape shape(sf::Vector2i dimensions);
  
};

class BrickListClass : public BrickClass{

  public:
  BrickClass brick;

  BrickListClass *next_brick = NULL;

};
BrickListClass *brick_list = NULL;

class BallClass : public EntityClass{
  public:
  float radius;
  sf::CircleShape shape(float radius);
  sf::Vector2f speed;

};
BallClass ball;

class PlatformClass : public EntityClass{
  public:
  sf::RectangleShape shape(sf::Vector2i dimensions);
  float horizontal_speed;
//  void InitPlatform
//  PlatformClass(sf::Vector2i, sf::Vector2i, float, bool, float);

};
PlatformClass platform;

struct GameInfo{
  int lives, score;
};
GameInfo game;