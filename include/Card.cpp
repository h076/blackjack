#include "Card.h"

Card::Card(Suits suit, Ranks rank) {
    this->suit = suit;
    this->rank = rank;

    switch(rank) {
        case TWO:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D2.jpg";
                case SPADE:
                    this->imgPath = "./images/S2.jpg";
                case HEART:
                    this->imgPath = "./images/H2.jpg";
                case CLUB:
                    this->imgPath = "./images/C2.jpg";
            }
        case THREE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D3.jpg";
                case SPADE:
                    this->imgPath = "./images/S3.jpg";
                case HEART:
                    this->imgPath = "./images/H3.jpg";
                case CLUB:
                    this->imgPath = "./images/C3.jpg";
            }
        case FOUR:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D4.jpg";
                case SPADE:
                    this->imgPath = "./images/S4.jpg";
                case HEART:
                    this->imgPath = "./images/H4.jpg";
                case CLUB:
                    this->imgPath = "./images/C4.jpg";
            }
        case FIVE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D5.jpg";
                case SPADE:
                    this->imgPath = "./images/S5.jpg";
                case HEART:
                    this->imgPath = "./images/H5.jpg";
                case CLUB:
                    this->imgPath = "./images/C5.jpg";
            }
        case SIX:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D6.jpg";
                case SPADE:
                    this->imgPath = "./images/S6.jpg";
                case HEART:
                    this->imgPath = "./images/H6.jpg";
                case CLUB:
                    this->imgPath = "./images/C6.jpg";
            }
        case SEVEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D7.jpg";
                case SPADE:
                    this->imgPath = "./images/S7.jpg";
                case HEART:
                    this->imgPath = "./images/H7.jpg";
                case CLUB:
                    this->imgPath = "./images/C7.jpg";
            }
        case EIGHT:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D8.jpg";
                case SPADE:
                    this->imgPath = "./images/S8.jpg";
                case HEART:
                    this->imgPath = "./images/H8.jpg";
                case CLUB:
                    this->imgPath = "./images/C8.jpg";
            }
        case NINE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D9.jpg";
                case SPADE:
                    this->imgPath = "./images/S9.jpg";
                case HEART:
                    this->imgPath = "./images/H9.jpg";
                case CLUB:
                    this->imgPath = "./images/C9.jpg";
            }
        case TEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D10.jpg";
                case SPADE:
                    this->imgPath = "./images/S10.jpg";
                case HEART:
                    this->imgPath = "./images/H10.jpg";
                case CLUB:
                    this->imgPath = "./images/C10.jpg";
            }
        case JACK:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D11.jpg";
                case SPADE:
                    this->imgPath = "./images/S11.jpg";
                case HEART:
                    this->imgPath = "./images/H11.jpg";
                case CLUB:
                    this->imgPath = "./images/C11.jpg";
            }
        case QUEEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D12.jpg";
                case SPADE:
                    this->imgPath = "./images/S12.jpg";
                case HEART:
                    this->imgPath = "./images/H12.jpg";
                case CLUB:
                    this->imgPath = "./images/C12.jpg";
            }
        case KING:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D13.jpg";
                case SPADE:
                    this->imgPath = "./images/S13.jpg";
                case HEART:
                    this->imgPath = "./images/H13.jpg";
                case CLUB:
                    this->imgPath = "./images/C13.jpg";
            }
        case ACE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = "./images/D1.jpg";
                case SPADE:
                    this->imgPath = "./images/S1.jpg";
                case HEART:
                    this->imgPath = "./images/H1.jpg";
                case CLUB:
                    this->imgPath = "./images/C1.jpg";
            }
    }
}

Card::~Card() {
    // destructor
}

Card::Ranks Card::getRank() {
    return this->rank;
}

Card::Suits Card::getSuit() {
    return this->suit;
}

int Card::getFaceValue() {
    if(this->rank <= TEN) {
        return static_cast<int>(this->rank);
    }else if(this->rank <= KING) {
        return 10;
    }

    return 11;
}

string Card::getImgPath() {
    return this->imgPath;
}
