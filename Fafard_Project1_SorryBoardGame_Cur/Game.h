/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Drake
 *
 * Created on May 2, 2021, 11:16 PM
 */

#ifndef GAME_H
#define GAME_H
#include "Cards.h"

class Game : public Cards {
private:
    list <string> plyrList; // Manages order of players
    map <string, char> plyrMap; // Manages player association to color on board
    map <string, string> pwnInf;
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void turn();
    void getPlayers();
    void SorryCard();
    void updatePwnInf();
    char checkWin();
    void start();
};

#endif /* GAME_H */

