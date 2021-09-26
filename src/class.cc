#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

class EntityClass{
  protected:
  float id;
  bool alive;

  public:
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


// Hacer class del nodo y de la lista 
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
  sf::Vector2i direction;

  public:
  PlatformClass(sf::Vector2f size, sf::Vector2f position, sf::Vector2i direction, float speed, bool alive, int id){

    this->shape.setPosition(position);
    this->shape.setSize(size);
    this->alive = alive;
    this->speed = speed;
    this->direction = direction;
    this->id = id;
    
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


  sf::Vector2i getDirection() {
    return this->direction;
  }
  void setDirection(sf::Vector2i direction) {
    this->direction = direction;
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