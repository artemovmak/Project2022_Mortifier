#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Farmer.h"
#include "Field.h"

class Engine {
private:
  sf::Music music;
  sf::RenderWindow game_window;
  sf::Sprite game_background_sprite;
  sf::Texture game_background_texture;
  Farmer farmer;
  Field field;
  void Music();
  void Input();
  void Update(float x, float y);
  void Draw();
public:
  Engine();
  void Start();
};