#ifndef MOUSE_H
#define MOUSE_H

#include "SDL2/SDL_mouse.h"
#include <SDL_image.h>
#include <SDL.h>

class Mouse  {
    SDL_Rect rect;
    SDL_Rect point;

    Mouse() {
        rect.w = 25;
        rect.h = 25;
        point.w = 1;
        point.h = 1;
    }

    void update() {
        SDL_GetMouseState(&rect.x, &rect.y);
        point.x = rect.x;
        point.y = rect.y;
    }

    void draw() {
        SDL_
    }
};

#endif /* MOUSE_H */
