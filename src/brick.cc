#ifndef __BLOCK__
#define __BLOCK__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "definitions.cc"

class Brick : public EntityClass{
  
   protected:
  sf::RectangleShape shape;

   public:
  Brick(sf::RectangleShape shape, int id, bool alive = true) {
    
    this->id = id;
    this->alive = alive;
    this->shape = shape;
  }

  Brick(){}

  sf::RectangleShape getShape() {
    return this->shape;
  }
  void setShape(sf::RectangleShape shape) {
    this->shape = shape;
  }

};

class BrickNode {
  public:
    Brick data;
    BrickNode* next;

    BrickNode(Brick data){
      this->data = data;
      this->next = nullptr;
    }
};

class BrickList{
  private:
  BrickNode* head;



  public:
  BrickList() {
    head = NULL;
  }
  ~BrickList() {};

  BrickNode* getHead() {
    return this->head;
  }
  void setHead(BrickNode* head) {
    this->head = head;
  }

  void addBrick(Brick data) {
    BrickNode* newnode = new BrickNode(data);
    
    // printf("\n%d-> x: %2f",data.getId(), data.getShape().getPosition().x);
    newnode->next = head;
    head = newnode;

  };

  void printBricks(sf::RenderWindow *window){
    static bool x = true;
    for (BrickNode* current = head; current != nullptr; current = current->next) {
      if (x) {
        // printf("\n%d-> x: %2f y: %2f",current->data.getId(), current->data.getShape().getPosition().x, current->data.getShape().getPosition().y);
      }
      
      window->draw(current->data.getShape());
    }
    x = false;
  }
  
  void printBricksAlive(sf::RenderWindow *window){
    for (BrickNode* current = head; current != nullptr; current = current->next) {
      if (current->data.getAlive()){
        window->draw(current->data.getShape());

      }
    }
  }
};

#endif