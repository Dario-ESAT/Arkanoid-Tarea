#ifndef __PLATFORM_H__
#define __PLATFORM_H__ 1
#include <SFML/Graphics.hpp>
#include "..\include\definitions.h"


class PlatformClass : public EntityClass{

   private:
  sf::RectangleShape shape;
  float speed;
  sf::Vector2i direction;

   public:
  PlatformClass(sf::RectangleShape shape, int id, float speed, sf::Vector2i direction = sf::Vector2i(0,0), bool alive = true);

  PlatformClass();
#pragma region s-getter
  sf::RectangleShape getShape() {
    return this->shape;
  }
 
  void setShape(sf::RectangleShape shape);

  float getSpeed() {
    return this->speed;
  }
  
  void setSpeed(float speed);

  sf::Vector2i getDirection() {
    return this->direction;
  }
  
  void setDirection(sf::Vector2i direction);

#pragma endregion


  void MovePlatform();

  void DrawPlatform(sf::RenderWindow *window);
};
#endif