#include <string>

using namespace std;

class Card {
    public:
        enum Suits {
        DIAMOND,
        SPADE,
        HEART,
        CLUB,
    };

        enum Ranks {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
    };

        Card(Suits suit, Ranks rank);
        ~Card();

        Ranks getRank();
        Suits getSuit();

        int getFaceValue();
        string getImgPath();

    private:
        Suits suit;
        Ranks rank;
        string imgPath;
};
