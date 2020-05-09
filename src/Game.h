#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Window.h"
#include "EventManager.h"
#include "StateManager.h"

class Game{

public: // Conctructor / Destructor

    Game();

    ~Game();

public: // Functions

    void run();

private: // Functions

    void processEvent();

    void update();

    void render();

    sf::Time getElapsedTime();

    void restartClock();

    void moveBlacksmith(EventDetails *details);

    void lateUpdate();

private: // Variable

    Window window;

    sf::Clock clock;

    sf::Time elapsedTime;

    StateManager stateManager;
};

#endif