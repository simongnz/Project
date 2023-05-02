//
// Created by Simon Gonzalez on 3/21/23.
//

#include "Tile.h"
#include "stdafx.h"

Tile::Tile() {
    initTexture();
    initSprite();

}

sf::FloatRect Tile::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

void Tile::initTexture() {
    if(!textureSheet.loadFromFile("/Users/simongonzalez/CLionProjects/Platformer_project/Textures/pngegg.png")){
        std::cout << "Error Image could not be loaded for tiles";
    }

}

void Tile::initSprite() {
    sprite.setTexture(textureSheet);
    currentFrame = sf::IntRect(210,0,14,16); // 270 for idle moves by 30
    sprite.setTextureRect(currentFrame);
    sprite.setScale(2.f,2.f);
}
