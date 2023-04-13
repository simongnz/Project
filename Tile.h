//
// Created by Simon Gonzalez on 3/21/23.
//

#ifndef PLATFORMER_PROJECT_TILE_H
#define PLATFORMER_PROJECT_TILE_H

#include "stdafx.h"

class Tile {
private:
    sf::Sprite sprite;
    bool damaging;

public:
    Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);
    sf::FloatRect getGlobalBounds();

    void update();
    void render(sf::RenderTarget& target);
};


#endif //PLATFORMER_PROJECT_TILE_H
