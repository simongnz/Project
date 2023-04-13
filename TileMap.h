//
// Created by Simon Gonzalez on 3/21/23.
//

#ifndef PLATFORMER_PROJECT_TILEMAP_H
#define PLATFORMER_PROJECT_TILEMAP_H
#include "stdafx.h"
#include "Tile.h"

class TileMap {
private:
    std::vector<std::vector<Tile*>> tiles;

public:
    TileMap();
    ~TileMap();

    void addTile(int x, int y);
    void removeTile(int x, int y);

    void update();
    void render();

};


#endif //PLATFORMER_PROJECT_TILEMAP_H
