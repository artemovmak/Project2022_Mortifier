#include "Farmer.h"

Farmer::Farmer() {
  f_texture.loadFromFile("../Farmer.png");
  f_sprite.setTexture(f_texture);

  f_position.x = 10;
  f_position.y = 10;
  f_captured = false;
}

sf::Sprite Farmer::getSprite() {
  return f_sprite;
}
void Farmer::Capture() {
  f_captured = true;
}
void Farmer::Stop() {
  f_captured = false;
}
void Farmer::Update(float x, float y) {
  if (f_captured) {
    f_sprite.setPosition(x, y);
  }
}
