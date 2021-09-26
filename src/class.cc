#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

class EntityClass{
  private:
  sf::Vector2i position;
  sf::Vector2i dimensions;
  float id;
  bool alive;

  public:
  sf::Vector2i getPosition() {
  return this->position;
  }
  void setPosition(sf::Vector2i position) {
  this->position = position;
  }

  sf::Vector2i getDimensions() {
  	return this->dimensions;
  }
  void setDimensions(sf::Vector2i dimensions) {
  	this->dimensions = dimensions;
  }

  float getId() {
  	return this->id;
  }
  void setId(float id) {
  	this->id = id;
  }

  bool getAlive() {
  	return this->alive;
  }
  void setAlive(bool alive) {
  	this->alive = alive;
  }

//  EntityClass(sf::Vector2i, sf::Vector2i, float, bool);
  
};

class BrickClass : public EntityClass{

  public:

//  EntityClass brick_entity( (0, 0), (72, 30), 3, true);

  BrickClass(sf::Vector2i, sf::Vector2i, float, bool);

  sf::RectangleShape shape;
  
};

class BrickListClass : public BrickClass{

  public:
  BrickClass brick;
  BrickListClass *next_brick = NULL;

};

class BallClass : public EntityClass{
  public:
  float radius;
  sf::CircleShape shape(float radius);
  sf::Vector2f speed;

};

class PlatformClass : public EntityClass{

  private:
  sf::RectangleShape shape;
  float speed;

  public:
  PlatformClass(sf::Vector2i dimensions, sf::Vector2i position, float speed, bool alive, int id){

    this->setPosition(position);
    this->setDimensions(dimensions);
    this->setAlive(alive);
    this->setSpeed(speed);
    this->setId(id);
    
  };

  sf::RectangleShape getShape() {
  	return this->shape;
  }
  void setShape(sf::RectangleShape shape) {
  	this->shape = shape;
  }

  float getSpeed() {
  	return this->speed;
  }
  void setSpeed(float speed) {
  	this->speed = speed;
  }



  void MovePlatform(){


  //  platform.shape.setPosition(sf::Vector2i (platform.position));
  }

  void DrawPlatform(){
    // window.draw(platform.shape);
  }

};

struct GameInfo{
  int lives, score;
};