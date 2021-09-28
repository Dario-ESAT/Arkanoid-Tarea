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
  BallClass(int id, sf::RectangleShape shape, sf::Vector2i direction = sf::Vector2i(0, 0), float speed = 0, bool alive = true){
    this->shape = shape;
    this->alive = alive;
    this->speed = speed;
    this->direction = direction;
    this->id = id;
  }
  BallClass(){};

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
  void CheckBoundaries(){
    if(this->shape.getPosition().x <= 0 || this->shape.getPosition().x >= kScreenWidth - this->shape.getSize().x){
      Bounce('S');
    }

    if(this->shape.getPosition().y <= 0){
      Bounce('T');
    }
    
  }
  void Bounce(char direction){

    /*
    T = Top/Bottom
    S = Sides
    */
    switch (direction) {
    case 'T':
      this->direction.x =  this->direction.x * -1;
      this->direction.y = this->direction.y * -1;
    case 'S':
      this->direction.x =  this->direction.x * -1;
      break;
    default:
      break;
    }

  }

  void MoveBall(){
    
    sf::Vector2f offset = sf::Vector2f(this->direction.x * this->speed, this->direction.y * this->speed);
    this->shape.move(offset);
    
  }

  void DrawBall(sf::RenderWindow *window){
    window->draw(this->shape);
  }

};

