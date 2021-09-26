#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>

#include "class.cc"

void InitPlatform(){
  platform.horizontal_speed = 20.0f;
  platform.position = sf::Vector2i(375, 750);
  platform.dimensions = sf::Vector2i(50, 2);
  platform.id = 1;
  platform.alive = true;
}

void MovePlatform(){

  sf::RectangleShape shape(sf::Vector2i (platform.position));

//  platform.shape.setPosition(sf::Vector2i (platform.position));
}

void DrawPlatform(){
  window.draw(platform.shape);
}