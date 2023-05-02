#include "Game.h"
#include "stdafx.h"
void Game::initWindow() {
    window.create(sf::VideoMode(800,600), "Platformer Game", sf::Style::Close | sf::Style::Titlebar); // Creates window 800x600 pixels with close tab and title
    window.setFramerateLimit(60); // Sets a frame limit to allow better frame rate
}

Game::Game(){ // Constructor for the window and player function
    initWindow();
    initPlayer();
}
Game::~Game() { // Descructor which deletes the object player
    delete player;
}

const sf::RenderWindow &Game::getWindow() { // Returns window object to allow rendering
    return window;
}

void Game::update() { // Use to catch keys and events done by the player

    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) // allows to close window with x or esc key
            window.close();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();
    }

    updatePlayer(); // Updates the player movements
    updateCollision();

}

void Game::render() { // renders the game clears previous one, displays the character
    window.clear();

    renderPlayer();
    renderTileMap();
    window.display();

}

void Game::updatePlayer() { // Update the state of the player movement with a pointer

    player -> update();

}

void Game::initPlayer() { // Creates a new player object

    player= new Player();

}

void Game::renderPlayer() { // Renders the player image on the window with pointer

    player ->render(window);
}

void Game::renderTileMap() { // Renders the player image on the window with pointer

}

void Game::updateCollision() {
    if(player->getGlobalBounds().top + player->getGlobalBounds().height > window.getSize().y){
        player->resetVelocityY();
        player->setPosition(player->getGlobalBounds().left,window.getSize().y-player->getGlobalBounds().height);
    }
}


