//
// Created by Simon Gonzalez on 3/21/23.
//

#ifndef PLATFORMER_PROJECT_TILE_H
#define PLATFORMER_PROJECT_TILE_H

#include "stdafx.h"

class Tile {
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::IntRect currentFrame;

    void initTexture();
    void initSprite();

public:
    Tile();
    sf::FloatRect getGlobalBounds();

    void update();
    void render(sf::RenderTarget& target);
};


#endif //PLATFORMER_PROJECT_TILE_H
