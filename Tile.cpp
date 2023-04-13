//
// Created by Simon Gonzalez on 3/21/23.
//

#include "Tile.h"
#include "stdafx.h"

Tile::Tile(sf::Texture &texture_sheet, sf::IntRect texture_rect, bool damaging) {
    sprite.setTexture(texture_sheet);
    sprite.setTextureRect(texture_rect);
    damaging = false;
}

sf::FloatRect Tile::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &target) {
    target.draw(sprite);
}
