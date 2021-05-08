/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Drake
 *
 * Created on October 30, 2020, 4:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Game.h"
#include "Menu.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); // Rand seed
    Game *gameInst = new Game();
    //Menu *menuInst = new Menu();
    //Cards *srryCds = new Cards(); // Initialize deck
    //Board *gameBrd = new Board(); // Initialize deck
    gameInst->outputBrd();
    //gameInst->getPlayers();
    cout << gameInst->getPawnPosition("R1");
    cout << gameInst->getPawnPosition("G3") << endl;
    //cout << gameInst->swapMove("B1", "Bs0", true, "R3", "Rs4", false);
    cout << gameInst->backwardMove("Y1", "Yn0", true, 4);
    gameInst->outputBrd();
    cout << gameInst->backwardMove("R2", "Ys1", true, 1);
    //cout << gameInst->forwardMove("B2", "Bb", true, 1);
    gameInst->outputBrd();
    //gameInst->turn();
    //cout << gameInst->nextColor('G');
    //menuInst->rules();
    delete gameInst;
    //delete menuInst;
    return 0;
}

