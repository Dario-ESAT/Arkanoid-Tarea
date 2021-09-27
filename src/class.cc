#ifndef __COLLISIONS__
#define __COLLISIONS__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

class EntityClass{
  protected:
  int id;
  bool alive;

  public:
  int getId() {
  	return this->id;
  }
  void setId(int id) {
  	this->id = id;
  }

  bool getAlive() {
  	return this->alive;
  }
  void setAlive(bool alive) {
  	this->alive = alive;
  }
};

class BrickClass : public EntityClass{
  
   protected:
  sf::RectangleShape shape;

   public:
  BrickClass(sf::RectangleShape shape, int id, bool alive = true) {
    
    this->id = id;
    this->alive = alive;
    this->shape = shape;
  }
  BrickClass(){}

  sf::RectangleShape getShape() {
    return this->shape;
  }
  void setShape(sf::RectangleShape shape) {
    this->shape = shape;
  }

  
};

class BrickNode {
  public:
    BrickClass data;
    BrickNode* next;

    BrickNode(BrickClass data){
      this->data = data;
      this->next = nullptr;
    }
};

class BrickListClass{
  private:
  BrickNode* head;

  public:
  BrickListClass() {
    head = NULL;
  }
  ~BrickListClass() {};

  void addBrick(BrickClass data) {
    BrickNode* newnode = (BrickNode*) malloc(sizeof(BrickNode));
    
    newnode->data = data;
    newnode->next = head;

    head = newnode;

  };

  void printBricks(sf::RenderWindow *window){
    for (BrickNode* current = head; current != nullptr; current = current->next) {
      
      window->draw(current->data.getShape());
    }
  }
  
  void printBricksAlive(sf::RenderWindow *window){
    for (BrickNode* current = head; current != nullptr; current = current->next) {
      if (current->data.getAlive()){
        window->draw(current->data.getShape());

      }
    }
  }
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
  PlatformClass(sf::RectangleShape shape, int id, float speed, sf::Vector2i direction = sf::Vector2i(0,0), bool alive = true){

    this->shape = shape;
    this->alive = alive;
    this->speed = speed;
    this->direction = direction;
    this->id = id;
    
  };
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
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

      this->direction = sf::Vector2i(0, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getShape().getPosition().x < 820) {

      this->direction = sf::Vector2i(1, 0);
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      
      this->direction = sf::Vector2i(0, 0);
    }

    sf::Vector2f offset = sf::Vector2f(this->direction.x * this->speed, 0.0f);
    this->shape.move(offset);
  }

  void DrawPlatform(sf::RenderWindow *window){
    window->draw(this->shape);

  }

};

class GameInfo{
  int lives, score;
};

#endif