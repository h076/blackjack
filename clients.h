#include <SDL2/SDL.h>
#include "build/include/Deck.h"

enum Options {WAITING, PLAYING, STAND, BUST};

class Dealer {
    public:
        Dealer();
        Dealer(SDL_Renderer *, int, int);
        virtual ~Dealer();

        void draw();
        Card * dealPlayer();
        void dealHand();
        void clearHand();
        int getHandValue();

        SDL_Texture * getCardTexture(string);

        Options getHandState();
        void setHandState(Options);

        void win();
        void loss();

    private:
        SDL_Renderer * renderer;
        SDL_Texture * cardBack;
        SDL_Rect rect;
        Deck* deck;
        vector<Card*> hand;
        Options handState;
        int handTotal;
        int screenWidth;
        int screenHeight;
        int games;
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

        Options getHandState();
        void setHandState(Options);

        void win();
        void loss();

    private:
        SDL_Renderer * renderer;
        SDL_Rect rect;
        vector<Card*> hand;
        Options handState;
        int handTotal;
        int screenWidth;
        int screenHeight;
        int games;
};
