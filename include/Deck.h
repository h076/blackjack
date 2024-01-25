#include "Card.h"
#include <vector>

using namespace std;

class Deck {
    public:
        Deck();
        ~Deck();

        void printDeck();
        void shuffleDeck();

    private:
        vector<Card*> deck;
};
