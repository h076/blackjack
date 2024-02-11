#include "Button.h"
#include "SDL2/SDL_mouse.h"

Button::Button() {

}

Button::Button(SDL_Renderer * r) {
    renderer = r;
    static SDL_Texture * t = IMG_LoadTexture(renderer, "/include/images/button1.jpg");
    tex = t;

    srect.h = 360;
    srect.w = 450;
    srect.x = 0;
    srect.y = 0;

    drect.h = 80;
    drect.w = 125;
}

Button::~Button() {

}

void Button::update() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    SDL_Rect mPoint;
    mPoint.x = x;
    mPoint.y = y;
    mPoint.w = 10;
    mPoint.h = 10;
    if(SDL_HasIntersection(&drect, &mPoint)) {
        isSelected = true;
        srect.x = 0;
    }else {
        isSelected = false;
        srect.x = 0;
    }
    draw();
}

void Button::draw() {
    SDL_RenderCopy(renderer, tex, &srect, &drect);
}
