#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "definitions.cc"

class BallClass : public EntityClass{
  private:
  sf::RectangleShape shape;
  sf::Vector2i direction;
  float speed;

  public:
  BallClass(int id, float radius, sf::RectangleShape shape, sf::Vector2i direction = sf::Vector2i(0, 0), float speed = 0, bool alive = true){
    this->shape = shape;
    this->alive = alive;
    this->speed = speed;
    this->direction = direction;
    this->id = id;
  }

  sf::RectangleShape getShape() {
  	return this->shape;
  }
  void setShape(sf::RectangleShape shape) {
  	this->shape = shape;
  }

  sf::Vector2i getDirection() {
    return this->direction;
  }
  void setDirection(sf::Vector2i direction) {
    this->direction = direction;
  }

  float getSpeed() {
  	return this->speed;
  }

  void setSpeed(float speed) {
  	this->speed = speed;
  }

  void bounce(){

  //  if()


    sf::Vector2f offset = sf::Vector2f(this->direction.x * this->speed, 0.0f);
    this->shape.move(offset);
  }

  void DrawBall(sf::RenderWindow *window){
    window->draw(this->shape);
  }

};

