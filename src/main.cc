#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "definitions.cc"
#include "brick.cc"
#include "platform.cc"
#include "ball.cc"

#include <SFML/Graphics.hpp>

class Game{
  public:
  int lives, score;
  
  BrickList brick_list;

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

        // printf("\n%d-> x: %2f",building_brick.getId(), building_brick.getShape().getPosition().x);
        brick_list.addBrick(building_brick);
        // printf("\n%d-> x: %2f y: %2f",brick_list.getHead()->data.getId(), brick_list.getHead()->data.getShape().getPosition().x, brick_list.getHead()->data.getShape().getPosition().y);

        id++;
      }
      position.x = 10;
      position.y += size.y + 5;
    }
    
  }
};

int main(){
  sf::RenderWindow window(sf::VideoMode(kScreenWith, kScreenHeight), "SFML works!");
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
  
  PlatformClass player(player_shape,1,5);
  BallClass ball(2, 6.0f, ball_shape);
  while (window.isOpen()){

    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
      }
    }
    player.MovePlatform();

    window.clear();
    // ---- Draw ------------------------

    player.DrawPlatform(&window);
    game.brick_list.printBricks(&window);
    // ----------------------------------
    window.display();

  }

  return 0;
}

