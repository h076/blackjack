#include <iostream>
#include <random>
#include "Deck.h"

using namespace std;

Deck::Deck() {
    this->deck.reserve(52);
    Card * c;
    for(Card::Suits s=Card::DIAMOND;
        static_cast<int>(s)<4;
        s = static_cast<Card::Suits>((static_cast<int>(s))+1))
    {
        for(Card::Ranks r=Card::TWO;
            static_cast<int>(r)<15;
            r = static_cast<Card::Ranks>((static_cast<int>(r))+1))
        {
            c = new Card(s, r);
            this->deck.push_back(c);
        }
    }
}

Deck::~Deck() {
    for(Card* c : deck) {
        delete c;
    }
}

void Deck::printDeck() {
    for(Card* c : deck) {
        cout << "s: "<< (*c).getSuit() << ", r: "<< (*c).getRank() << "\n";
    }
}

// shuffle implements the Fisher-Yates shuffle
// using the meant to be 'non-deterministic' random library to generate a roll number
void Deck::shuffleDeck() {
    random_device rd;
    vector<Card*> tempDeck;
    vector<Card*>::iterator it;
    int rand;

    cout << "Shuffling ...\n";
    for(int i=deck.size()-1; i>=0; i--) {
        uniform_int_distribution<int> dist(0, i);
        rand = dist(rd);
        tempDeck.push_back(deck[rand]);
        it = deck.begin();
        deck.erase(it+rand);
    }
    deck.swap(tempDeck);
}
