//
// Created by Simon Gonzalez on 2/12/23.
//

#ifndef PLATFORMER_PROJECT_PLAYER_H
#define PLATFORMER_PROJECT_PLAYER_H
#include "Abstract_entity.h"

enum Playeranimationstates{idle,left,right,jump,falling};


class Player : public Entity { // Class for player
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;

    short animationState;
    sf::IntRect currentFrame;

    sf::Vector2f velocity;
    float maxvelocity;
    float minvelocity;
    float acceleration;
    float deceleration;
    float gravity;
    float maxgravity;


    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Player();

    sf::FloatRect getGlobalBounds()override;
    void resetVelocityY()override;
    void setPosition(float x,float y)override;
    void move(float directionx,float directiony)override;
    void updatePhysics()override;
    void initVariables()override;
    void updateMovement()override;
    void updateAnimations()override;
    void update()override;
    void render(sf::RenderTarget& target)override;

};


#endif //PLATFORMER_PROJECT_PLAYER_H
