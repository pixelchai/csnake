//
// Created by ab on 12/04/2020.
//

#include "Game.h"

Game::Game() {
    running = false;
    window = nullptr;
    renderer = nullptr;
    field = nullptr;
}

bool Game::init() {
    // model set up
    field = new Field();

    // SDL setup
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL2 initialisation failed: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("CSnake",
            0,
            0,
            field->get_width() * cell_width,
            field->get_height() * cell_width,
            0);
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
    clear();
    draw_background();
    SDL_RenderPresent(renderer);
}

void Game::draw_background() {
    SDL_Rect r {50, 50, 50, 50};

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &r);
}

void Game::clear() {
    // clear everything
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

Game::~Game() = default;
