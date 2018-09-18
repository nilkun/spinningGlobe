#include <SDL2/SDL.h>
#include "SpinningEarth.h"
#include "../gameEngine/window/window.h"
#include "Factory.h"
#include <iostream>

int main() {

    Screen screen("Spinning Earth!", 1024, 768);
    SDL_Renderer* renderer = screen.getRenderer();
    Factory* factory = Factory::getInstance();
    factory -> setRenderer(renderer);
    SpinningEarth earth;

    earth.init(renderer);
//    earth.changeColor(renderer);
    while(true) {

    SDL_RenderClear(renderer);
    earth.update(renderer);
    earth.draw(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 128, 0, 0);
    SDL_RenderPresent(renderer);
    }
}
