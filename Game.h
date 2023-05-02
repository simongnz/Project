//
// Created by Simon Gonzalez on 2/11/23.
//
#include "stdafx.h"
#include "Player.h"
#include "TileMap.h"

class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
    Player* player;
    TileMap* map;
    void initWindow();
    void initPlayer();
public:
    Game();
    ~Game();

    // Functions
    const sf::RenderWindow& getWindow();
    void updatePlayer();
    void update();
    void renderPlayer();
    void renderTileMap();
    void render();
    void updateCollision();

};


