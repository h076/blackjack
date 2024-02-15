#include "game.h"
#include "SDL2/SDL_render.h"
#include <iostream>

game::game() {

}

game::game(SDL_Renderer * ren) {
    this->renderer = ren;
    dealer = new Dealer(this->renderer, 600, 800);
    gameState = START;
    currentPlayer = -1;

    hitBtn = Button(renderer);
    hitBtn.drect.x = 550;
    hitBtn.drect.y = 350;
    standBtn = Button(renderer);
    standBtn.drect.x = 150;
    standBtn.drect.y = 350;
}

game::~game() {

}

bool game::joinTable() {
    // new player initialised like this so its reference is
    // not overwritten in the stack frame
    Player* p = new Player(this->renderer, 600, 800);
    players.push_back(p);
    if(currentPlayer == -1) {
        currentPlayer++;
    }
    return true;
}

void game::update() {
    draw();
    handleGameState();
}

void game::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderClear(renderer);

    hitBtn.update();
    standBtn.update();

    dealer->draw();
    for(Player * p : players) {
        (*p).draw();
    }

    SDL_RenderPresent(renderer);
}

void game::handleBtnPress() {
    Player * cp = nullptr;
    for(Player * p : players) {
        if(p->getHandState() == PLAYING)
            cp = p;
    }
    if(hitBtn.isSelected) {
        cout << "player hits \n";
        hit(cp);
    }else if(standBtn.isSelected) {
        cout << "player stands \n";
        stand(cp);
    }
}

void game::handleGameState() {
    if(gameState == START) {
        startHand();
        gameState = OPTIONS;
    }else if(gameState == OPTIONS) {
        options();
    }else if(gameState == OUTCOME) {
        outcomes();
    }else if(gameState == END) {
        endHand();
    }
}

void game::startHand() {
    Card * tempCard = nullptr;

    for(Player * p : players) {
        tempCard = dealer->dealPlayer();
        p->takeCard(tempCard);
    }
    dealer->dealHand();

    for(Player * p : players) {
        tempCard = dealer->dealPlayer();
        p->takeCard(tempCard);
        p->printHand();
    }
    dealer->dealHand();
    dealer->printHand();


}

void game::options() {
    Player * cp = nullptr;
    for(int i=0; i<players.size(); i++) {
        cp = players[currentPlayer];
        if(i==0 && cp->getHandState() == WAITING) {
            cp->setHandState(PLAYING);
        }
        if(i == currentPlayer && i+1 == players.size()) {
            if(cp->getHandState() == STAND || cp->getHandState() == BUST) {
                gameState = OUTCOME;
            }
        }else if(i == currentPlayer) {
            if(cp->getHandState() == STAND || cp->getHandState() == BUST) {
                players[i+1]->setHandState(PLAYING);
            }
        }
    }
}

void game::outcomes() {
    while(dealer->getHandValue() < 17) {
        dealer->dealHand();
        draw();
        if(dealer->getHandValue()>21) {
            dealer->setHandState(BUST);
        }
    }
    for(Player * p : players) {
        if(dealer->getHandState() == BUST && p->getHandState() == STAND) {
            cout << "dealer bust\n";
            p->win();
            dealer->loss();
        }if(p->getHandState() == BUST) {
            cout << "player bust\n";
            p->loss();
            dealer->win();
        }else if(p->getHandValue() > dealer->getHandValue()) {
            cout << "player wins\n";
            p->win();
            dealer->loss();
        }else if(p->getHandValue() == dealer->getHandValue()){
            cout << "push\n";
        }else {
            cout << "player loss\n";
            dealer->win();
            p->loss();
        }
    }

    gameState = END;
}

void game::endHand() {
    dealer->clearHand();
    for(Player * p : players) {
        p->clearHand();
        p->setHandState(WAITING);
    }
    gameState = START;
}

void game::hit(Player * p) {
    Card * tempCard = nullptr;
    if(find(players.begin(), players.end(), p) != players.end()
       && p->getHandState() == PLAYING) {
        tempCard = dealer->dealPlayer();
        p->takeCard(tempCard);
        if(p->getHandValue() > 21) {
            p->setHandState(BUST);
        }
    }
}

void game::stand(Player * p) {
    if(find(players.begin(), players.end(), p) != players.end()
       && p->getHandState() == PLAYING) {
        p->setHandState(STAND);
    }
}
