#include "SDL2/SDL_render.h"
#include "clients.h"
#include "Button.h"

using namespace std;

enum States {START, OPTIONS, OUTCOME, END};

class game {
    public:
        game();
        game(SDL_Renderer *);
        virtual ~game();

        bool joinTable();

        void draw();
        void handleBtnPress();

        void handleGameState();
        void startHand();
        void options();
        void outcomes();
        void endHand();

        void hit(Player *);
        void stand(Player *);

    private:
        SDL_Renderer * renderer;

        States gameState;
        Dealer* dealer;

        vector<Player*> players;
        int currentPlayer;

        Button hitBtn;
        Button standBtn;
};
