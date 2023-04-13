#include "stdafx.h"
#include "Player.h"


void Player::initTexture() { // Loads the player sprite otherwise sends error

    if(!textureSheet.loadFromFile("/Users/simongonzalez/CLionProjects/Platformer_project/Textures/MarioSprite.png")){
        std::cout << "Error Image could not be loaded for player";

    }

}

void Player::initSprite() { // Modifies the sprite to the screen so only one character shows

    sprite.setTexture(textureSheet);
    currentFrame = sf::IntRect(210,0,14,16); // 270 for idle moves by 30
    sprite.setTextureRect(currentFrame);
    sprite.setScale(2.f,2.f);

}

Player::Player() { // Constructor for player that initiates the functions
    initVariables();
    initTexture();
    initSprite();
    initAnimations();
    initPhysics();
}

void Player::update() { // Updates the players movement and animations

    updateMovement();
    updateAnimations();
    updatePhysics();

}

void Player::render(sf::RenderTarget &target) { // Function that is later called on Game.cpp which allows to illustrate the sprite on window

    target.draw(sprite);

}

void Player::updateMovement() { // Sets keys for movement for the player

    animationState= idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        move(-1.f,0.f);
        animationState= left;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        move(1.f,0.f);
        animationState= right;
    }

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
       move(0.f,-2.f);
       animationState= jump;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
       move(0.f,2.f);
       animationState= falling;
    }
}

void Player::initAnimations() { // For animations... still working on it
    animationTimer.restart();
}

void Player::updateAnimations() { //Updates the animatiosn...  still working on it

    if(animationState== idle){
        if(animationTimer.getElapsedTime().asSeconds() >= 0.5f){

            currentFrame.left += 60.f;
            if(currentFrame.left >= 300){
                currentFrame.left= 210;
            }

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }else if(animationState == right){
        if(animationTimer.getElapsedTime().asSeconds() >= 0.1f) {

            currentFrame.left += 30.f;
            if (currentFrame.left >= 330) {
                currentFrame.left = 210;
            }

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }else if(animationState == left){
        if(animationTimer.getElapsedTime().asSeconds() >= 0.1f) {

            currentFrame.left -= 30.f;
            if (currentFrame.left <= 60) {
                currentFrame.left = 180;
            }

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }



}
void Player::initVariables() { // Varaibles for player as of now for movement
    animationState= idle;

}

void Player::updatePhysics() {


    velocity *= deceleration;

    if (std::abs(velocity.x) < minvelocity){
        velocity.x= 0.f;
    }
    if (std::abs(velocity.y) < minvelocity){
        velocity.y= 0.f;
    }
    if(std::abs(velocity.y) == maxgravity) {
        velocity.y += 1;
    }


        sprite.move(velocity);
}

void Player::initPhysics() {
    maxvelocity= 5.f;
    acceleration= 2.f;
    deceleration = 0.92f;
    minvelocity = 1.f;
    gravity = 2.f;
    maxgravity= 6.f;
}

void Player::move(float directionx, float directiony) {


    velocity.x += directionx * acceleration;

    if(std::abs(velocity.x) > maxvelocity){
        velocity.x = maxvelocity * ((velocity.x < 0.f) ? -1.f:1.f);
    }

    velocity.y += directiony * gravity;

    if(std::abs(velocity.y) > maxvelocity){
        velocity.y = maxgravity * ((velocity.y < 0.f) ? -1.f:1.f);
    }


}

sf::FloatRect Player::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Player::resetVelocityY() {
    velocity.y= 0.f;
}

void Player::setPosition(float x, float y) {
    sprite.setPosition(x,y);
}

