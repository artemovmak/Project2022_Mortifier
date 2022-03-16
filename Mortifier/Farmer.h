#pragma once
#include <SFML/Graphics.hpp>

class Farmer {
private:
  const int kFCost = 10;

  sf::Vector2f f_position;
  sf::Sprite f_sprite;
  sf::Texture f_texture;
  bool f_captured;
public:
  Farmer();
  sf::Sprite getSprite();
  void Stop();
  void Capture();
  void Update(float x, float y);
};