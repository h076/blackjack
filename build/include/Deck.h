#include "Card.h"
#include <vector>

using namespace std;

class Deck {
    public:
        Deck();
        ~Deck();

        void printDeck();
        void shuffleDeck();

        Card* deal();
        void concat();

    private:
        vector<Card*> deck;
        vector<Card*> dealt;
};
