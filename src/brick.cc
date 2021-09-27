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

class BrickListClass{
  private:
  BrickNode* head;

  public:
  BrickListClass() {
    head = NULL;
  }
  ~BrickListClass() {};

  void addBrick(Brick data) {
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

#endif