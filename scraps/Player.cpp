#include "Player.h"
#include "SDL2/SDL_render.h"
#include <iostream>
#include <SDL_image.h>

using namespace std;

Player::Player(SDL_Renderer * r, int h, int w) {
    renderer = r;
    screenHeight = h;
    screenWidth = w;
    handTotal = 0;
    rect.x = (screenWidth/2)-160;
    rect.y = 170;
    rect.w = 80;
    rect.h = 160;
}

Player::~Player() {

}

void Player::draw() {
    if(hand.size() >= 1) {
        for(int i=0; i<hand.size(); i++) {
            SDL_Rect r = rect;
            r.x = rect.x+(i*10);
            SDL_RenderCopy(renderer, getCardTexture((*hand[i]).getImgPath()), NULL, &r);
        }
    }
}

void Player::takeCard(Card * card) {
    hand.push_back(card);
    handTotal += (*hand[hand.size()]).getFaceValue();
}

void Player::clearHand() {
    hand.clear();
    handTotal = 0;
}

int Player::getHandValue() {
    return handTotal;
}

SDL_Texture * Player::getCardTexture(string path) {
    SDL_Texture * temp = IMG_LoadTexture(renderer, path.data());
    if(!temp) {
        cout << "ERROR: can't load card texture: " << SDL_GetError() << "\n";
    }else {
        return temp;
    }
}
