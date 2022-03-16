#include "Farmer.h"

Farmer::Farmer() {
<<<<<<< HEAD
  f_texture.loadFromFile("../Farmer.png");
=======
  f_texture.loadFromFile("/home/makarart/CLionProjects/Slay've/Farmer.png");
>>>>>>> f71f946... new directory
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
