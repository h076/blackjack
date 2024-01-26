#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(Suits suit, Ranks rank) {
    this->suit = suit;
    this->rank = rank;
    string subPath = "./include/images/";
    switch(rank) {
        case TWO:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D2.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S2.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H2.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C2.jpg";
                    break;
            }
            break;
        case THREE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D3.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S3.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H3.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C3.jpg";
                    break;
            }
            break;
        case FOUR:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D4.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S4.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H4.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C4.jpg";
                    break;
            }
            break;
        case FIVE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D5.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S5.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H5.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C5.jpg";
                    break;
            }
            break;
        case SIX:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D6.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S6.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H6.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C6.jpg";
                    break;
            }
            break;
        case SEVEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D7.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S7.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H7.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C7.jpg";
                    break;
            }
            break;
        case EIGHT:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D8.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S8.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H8.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C8.jpg";
                    break;
            }
            break;
        case NINE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D9.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S9.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H9.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C9.jpg";
                    break;
            }
            break;
        case TEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D10.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S10.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H10.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C10.jpg";
                    break;
            }
            break;
        case JACK:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D11.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S11.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H11.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C11.jpg";
                    break;
            }
            break;
        case QUEEN:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D12.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S12.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H12.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C12.jpg";
                    break;
            }
            break;
        case KING:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D13.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S13.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H13.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C13.jpg";
                    break;
            }
            break;
        case ACE:
            switch(suit) {
                case DIAMOND:
                    this->imgPath = subPath+"D1.jpg";
                    break;
                case SPADE:
                    this->imgPath = subPath+"S1.jpg";
                    break;
                case HEART:
                    this->imgPath = subPath+"H1.jpg";
                    break;
                case CLUB:
                    this->imgPath = subPath+"C1.jpg";
                    break;
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
