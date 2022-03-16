#include "Field.h"
Field::Field() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      field[i][j] = sf::CircleShape(25, 6);
      field[i][j].setOutlineColor(sf::Color::Black);
      field[i][j].setOutlineThickness(5);
      field[i][j].setOrigin(25, 25);
      field[i][j].setPosition(static_cast<float>(j % 2 == 1 ? 75 : 50) + static_cast<float>(i)  * 50.f, 50 + static_cast<float>(j) * 40.f);
      field[i][j].setFillColor(sf::Color(128, 128, 128));
    }
  }
}
sf::CircleShape& Field::GetTile(int x, int y) {
  return field[x][y];
}
size_t Field::GetHeight() const {
  return height;
}
size_t Field::GetWidth() const {
  return width;
}

bool Field::IsInHex(sf::Vector2i point, sf::CircleShape hex) {
  sf::Vector2f pointf = {float(point.x), float(point.y)};
  sf::Vector2f point_v = pointf - hex.getPosition();
  if (point_v.x * point_v.x + point_v.y * point_v.y < hex.getRadius() * hex.getRadius()) {
    return true;
  }
  return false;
}
