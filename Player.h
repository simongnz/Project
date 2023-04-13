//
// Created by Simon Gonzalez on 2/12/23.
//

#ifndef PLATFORMER_PROJECT_PLAYER_H
#define PLATFORMER_PROJECT_PLAYER_H

enum Playeranimationstates{idle,left,right,jump,falling};


class Player { // Class for player
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

    sf::FloatRect getGlobalBounds();
    void resetVelocityY();
    void setPosition(float x,float y);
    void move(float directionx,float directiony);
    void updatePhysics();
    void initVariables();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);

};


#endif //PLATFORMER_PROJECT_PLAYER_H
