#include <SDL2/SDL.h>
#include "build/include/Deck.h"

class Dealer {
    public:
        Dealer(SDL_Renderer *, int, int);
        virtual ~Dealer();

        void draw();
        Card * dealPlayer();
        void dealHand();
        void clearHand();
        int getHandValue();

        SDL_Texture * getCardTexture(string);

    private:
        SDL_Renderer * renderer;
        SDL_Texture * cardBack;
        SDL_Rect rect;
        Deck deck;
        vector<Card*> hand;
        int handTotal;
        int screenWidth;
        int screenHeight;
};

class Player {
    public:
        Player(SDL_Renderer *, int , int);
        virtual ~Player();

        void draw();
        void takeCard(Card *);
        void clearHand();
        int getHandValue();

        SDL_Texture * getCardTexture(string);

    private:
        SDL_Renderer * renderer;
        SDL_Rect rect;
        vector<Card*> hand;
        int handTotal;
        int screenWidth;
        int screenHeight;
};
