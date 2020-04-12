//
// Created by ab on 12/04/2020.
//

#include "Game.h"

Game::Game() {
    running = false;
    window = nullptr;
    renderer = nullptr;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL2 initialisation failed: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("CSnake", 0, 0, 100, 100, 0);
    if (window == NULL) {
        std::printf("Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL){
        std::printf("Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    running = true;
    return true;
}

bool Game::is_running() {
    return running;
}

void Game::run() {
    const int frame_rate{5};
    const int frame_time{1000 / frame_rate}; // amount of ms each frame is to be shown

    Uint32 initial_time;
    Uint32 time_elapsed;

    while (is_running()) {
        initial_time = SDL_GetTicks();

        update();
        render();

        time_elapsed = SDL_GetTicks() - initial_time;

        if (time_elapsed < frame_time) {
            SDL_Delay(frame_time - time_elapsed);
        }
    }
}

void Game::update() {

}

void Game::render() {

}

Game::~Game() = default;
