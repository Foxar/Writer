#include <vector>
#include <SFML/Graphics.hpp>
#ifndef SPRITECONTAINER_H
#define SPRITECONTAINER_H


class SpriteContainer
{
    public:
        SpriteContainer();
        std::vector<sf::Sprite>SpriteList;
        std::vector<sf::Sprite>SpriteListLayer2;
        std::vector<sf::RectangleShape>ShapeList;
        std::vector<sf::Text>TextList;
        std::vector<sf::Text>TextList2;
};

#endif // SPRITECONTAINER_H
