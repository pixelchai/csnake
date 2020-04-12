//
// Created by ab on 12/04/2020.
//

#ifndef CSNAKE_GAME_H
#define CSNAKE_GAME_H
#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    bool init();
    void update();
    void render();
    void run();
    bool is_running();

private:
    bool running;

    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif //CSNAKE_GAME_H
