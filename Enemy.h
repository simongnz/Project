//
// Created by Simon Gonzalez on 5/1/23.
//

#ifndef PLATFORMER_PROJECT_ENEMY_H
#define PLATFORMER_PROJECT_ENEMY_H
#include "Abstract_entity.h"

class Enemy : public Entity{
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::IntRect currentFrame;
    sf::Vector2f velocity;

    float maxvelocity;
    float minvelocity;
    float acceleration;
    float deceleration;
    float gravity;
    float maxgravity;
public:

    Enemy();

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



#endif //PLATFORMER_PROJECT_ENEMY_H
