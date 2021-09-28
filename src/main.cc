#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "definitions.cc"
#include "brick.cc"
#include "platform.cc"
#include "ball.cc"

#include <SFML/Graphics.hpp>
struct hitbox {
  float x1,y1,x2,y2;
};

class Game{
  public:
  int lives, score;
  
  BrickList brick_list;
  
  BallClass ball;
  Game(){}
  bool IsInsideHitbox(hitbox item, float x, float y){
    return x>item.x1 && x<item.x2 && y>item.y1 && y<item.y2;
  }
  //Revisa la colisión con todos los puntos
  bool Collision(hitbox first_item, hitbox second_item){
    return IsInsideHitbox(first_item,second_item.x1,second_item.y1)||IsInsideHitbox(first_item,second_item.x2,second_item.y1)||
        IsInsideHitbox(first_item,second_item.x1,second_item.y2)||IsInsideHitbox(first_item,second_item.x2,second_item.y2);
  }

  void buildBricks(){

    sf::Vector2f position = sf::Vector2f(10,50);
    sf::Vector2f size = sf::Vector2f(50,30);
    sf::RectangleShape shape(size);
    int id = 0;
    for (int i = 0; i < 5; i++) {
      for (int f = 0; f < 5; f++) {
        position.x += size.x + 5;

        shape.setPosition(position);
        Brick building_brick(shape,id);

        brick_list.addBrick(building_brick);
        
        id++;
      }
      position.x = 10;
      position.y += size.y + 5;
    }
    
  }

  void initBall(){
    sf::RectangleShape shape(sf::Vector2f(20,20));
    shape.setPosition(sf::Vector2f(10,10));
    ball = BallClass(1,shape,sf::Vector2i(0,0));
  }

  void BallBricksCollision(){
    hitbox h_ball = {ball.getShape().getPosition().x,ball.getShape().getPosition().y,
      ball.getShape().getPosition().x + ball.getShape().getSize().x,ball.getShape().getPosition().y + ball.getShape().getSize().y};
    
    for (BrickNode* current = brick_list.getHead(); current != nullptr; current = current->next) {
      hitbox h_brick = {current->data.getShape().getPosition().x,current->data.getShape().getPosition().y,
        current->data.getShape().getPosition().x + current->data.getShape().getSize().x,current->data.getShape().getPosition().y + current->data.getShape().getSize().y};

      if (Collision(h_brick,h_ball)) {
        
      }
      
    }
  }
};

int main(){
  sf::RenderWindow window(sf::VideoMode(kScreenWidth, kScreenHeight), "SFML works!");
  window.setFramerateLimit(30);
  Game game;
  game.buildBricks();

// BallClass ball;
// BrickListClass *brick_list = NULL;
  sf::RectangleShape player_shape(sf::Vector2f(80,20));
  sf::RectangleShape ball_shape(sf::Vector2f(20,20));
  player_shape.setPosition(360,860);
  player_shape.setFillColor(sf::Color::Green);

  ball_shape.setPosition(380,840);
//  ball_shape.getFillColor(sf::Color::Red);
  game.initBall();

  PlatformClass player(player_shape,1,5);
  while (window.isOpen()){

    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
      }
    }
    // -------- Input ------------

    player.MovePlatform();
    game.ball.MoveBall(&window);
    game.BallBricksCollision();

    // ---------------------------

    window.clear();

    // ---- Draw ------------------------

    player.DrawPlatform(&window);
    game.brick_list.printBricks(&window);
    game.ball.DrawBall(&window);
    
    // ----------------------------------

    window.display();

  }

  return 0;
}

