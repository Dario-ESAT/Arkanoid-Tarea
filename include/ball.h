#ifndef __BALL_H__
#define __BALL_H__ 1
#include <SFML/Graphics.hpp>

#include "..\include\definitions.h"

class BallClass : public EntityClass{
  private:
  sf::RectangleShape shape;
  sf::Vector2i direction;
  float speed;

  public:
  BallClass(int id, sf::RectangleShape shape, sf::Vector2i direction = sf::Vector2i(0, 0), float speed = 0, bool alive = true);
  
  BallClass();

  sf::RectangleShape getShape() {
  	return this->shape;
  }

  void setShape(sf::RectangleShape shape);

  sf::Vector2i getDirection() {
    return this->direction;
  }

  void setDirection(sf::Vector2i direction);
  
  float getSpeed() {
  	return this->speed;
  }

  void setSpeed(float speed);

  void CheckBoundaries();

  void Bounce(char direction);

  void MoveBall();

  void DrawBall(sf::RenderWindow *window);
};

#endif