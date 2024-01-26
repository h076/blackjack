#include "clients.h"
#include <iostream>
#include <SDL_image.h>

using namespace std;

Dealer::Dealer(SDL_Renderer * ren, int h, int w) {
    deck.shuffleDeck();
    renderer = ren;
    screenWidth = w;
    screenHeight = h;
    handTotal = 0;
    cardBack = IMG_LoadTexture(renderer, "/include/images/H14.jpg");
    rect.x = (screenWidth/2)-160;
    rect.y = 10;
    rect.w = 80;
    rect.h = 160;
}

Dealer::~Dealer() {

}

void Dealer::draw() {
    if(hand.size() <= 2) {
        SDL_RenderCopy(renderer, cardBack, NULL, &rect);
        for(int i=1; i<hand.size(); i++) {
            SDL_Rect r;
            r.x = rect.x+(i*10);
            SDL_RenderCopy(renderer, getCardTexture((*hand[i]).getImgPath()), NULL, &r);
        }
    }else if(hand.size() >= 3) {
        for(int i=0; i<hand.size(); i++) {
            SDL_Rect r = rect;
            r.x = rect.x+(i*10);
            SDL_RenderCopy(renderer, getCardTexture((*hand[i]).getImgPath()), NULL, &r);
        }
    }
}

Card * Dealer::dealPlayer() {
    return deck.deal();
}

void Dealer::dealHand() {
    hand.push_back(deck.deal());
    handTotal += (*hand[hand.size()-1]).getFaceValue();
}

void Dealer::clearHand() {
    hand.clear();
    deck.concat();
    deck.shuffleDeck();
    handTotal = 0;
}

int Dealer::getHandValue() {
    return handTotal;
}

SDL_Texture * Dealer::getCardTexture(string path) {
    SDL_Texture * temp = IMG_LoadTexture(renderer, path.data());
    if(!temp) {
        cout << "ERROR: can't load card texture: " << SDL_GetError() << "\n";
        return nullptr;
    }else {
        return temp;
    }
}

Player::Player(SDL_Renderer * r, int h, int w) {
    renderer = r;
    screenHeight = h;
    screenWidth = w;
    handTotal = 0;
    rect.x = (screenWidth/2)-160;
    rect.y = (screenHeight)-170;
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
            r.x = rect.y+(i*10);
            SDL_RenderCopy(renderer, getCardTexture((*hand[i]).getImgPath()), NULL, &r);
        }
    }
}

void Player::takeCard(Card * card) {
    hand.push_back(card);
    handTotal += (*hand[hand.size()-1]).getFaceValue();
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
        return nullptr;
    }else {
        return temp;
    }
}
