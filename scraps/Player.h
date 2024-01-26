#include "build/include/Deck.h"
#include <SDL.h>
#include <string.h>

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
