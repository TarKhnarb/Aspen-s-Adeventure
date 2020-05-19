#ifndef GAME_HATCH_H
#define GAME_HATCH_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Color.hpp>

#include <string>

#include "Entity.h"

class Hatch: public Entity{

public:

    Hatch() = delete;
    Hatch(TextureManager*, sf::Color = sf::Color::White);
    ~Hatch();

public:

    void openHatch();

    bool getIsOpen() const;

private:

    void selectHatch();

    void draw(sf::RenderTarget&, sf::RenderStates) const override;

private:

    bool isOpen;

    sf::Sprite sprite;
    sf::Color color;
    std::string textureName;
};

#endif
