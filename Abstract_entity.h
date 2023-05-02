//
// Created by Simon Gonzalez on 5/1/23.
//

#ifndef PLATFORMER_PROJECT_ABSTRACT_ENTITY_H
#define PLATFORMER_PROJECT_ABSTRACT_ENTITY_H
#include "stdafx.h"

class Entity{
public:
    virtual sf::FloatRect getGlobalBounds()=0;
    virtual void resetVelocityY()=0;
    virtual void setPosition(float x,float y)=0;
    virtual void move(float directionx,float directiony)=0;
    virtual void updatePhysics()=0;
    virtual void initVariables()=0;
    virtual void updateMovement()=0;
    virtual void updateAnimations()=0;
    virtual void update()=0;
    virtual void render(sf::RenderTarget& target)=0;
};

#endif //PLATFORMER_PROJECT_ABSTRACT_ENTITY_H
