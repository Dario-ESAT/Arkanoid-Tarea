#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "definitions.cc"

class PlatformClass : public EntityClass{

   private:
  sf::RectangleShape shape;
  float speed;
  sf::Vector2i direction;

   public:
  PlatformClass(sf::RectangleShape shape, int id, float speed, sf::Vector2i direction = sf::Vector2i(0,0), bool alive = true){

    this->shape = shape;
    this->alive = alive;
    this->speed = speed;
    this->direction = direction;
    this->id = id;
    
  };
  PlatformClass(){};
#pragma region s-getter
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
#pragma endregion


  void MovePlatform(){
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->getShape().getPosition().x > 0) {

      this->direction = sf::Vector2i(-1, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getShape().getPosition().x < kScreenWidth - this->getShape().getSize().x) {

      this->direction = sf::Vector2i(1, 0);
    } else {

      this->direction = sf::Vector2i(0, 0);
    }

    sf::Vector2f offset = sf::Vector2f(this->direction.x * this->speed, 0.0f);
    // printf("\n%f", offset.x);
    this->shape.move(offset);
  }

  void DrawPlatform(sf::RenderWindow *window){
    window->draw(this->shape);

  }

};

