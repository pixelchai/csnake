//
// Created by ab on 12/04/2020.
//

#ifndef CSNAKE_GAME_H
#define CSNAKE_GAME_H
#include <SDL2/SDL.h>
#include <iostream>
#include "Field.h"

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
    const int frame_rate{120}; // how many frames should be shown per second
    const Uint32 frame_time{static_cast<Uint32>(1000 / frame_rate)}; // amount of ms each frame is to be shown for
    const double time_step{1.0 / frame_rate}; // number of seconds each frame is shown for

    const int cell_width{30};

    bool running;
    int bruh{0};

    SDL_Window *window;
    SDL_Renderer *renderer;

    Field *field;

    void draw_background();

    void clear();
};


#endif //CSNAKE_GAME_H
