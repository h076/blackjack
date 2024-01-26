#include "SDL2/SDL_rect.h"
#include "build/include/Deck.h"
#include <SDL2/SDL.h>
#include <SDL_image.h>

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
