#pragma once
#include <SFML/Graphics.hpp>

class Field {
private:
  size_t height = 37;
  size_t width = 23;
  sf::CircleShape field[37][23];
public:
  Field();
  sf::CircleShape& GetTile(int x, int y);
  size_t GetHeight() const;
  size_t GetWidth() const;
  bool IsInHex(sf::Vector2i point, sf::CircleShape hex);
};