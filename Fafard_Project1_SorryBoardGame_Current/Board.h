/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: Drake
 *
 * Created on October 30, 2020, 10:21 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <ios>
#include <limits>
#include <list>
#include <queue>
using namespace std;

class Board {

private:
    // The info on how the board works, is used to determine how spots work
    map<string, string> brdInf;
    map<string, string>::iterator brdItr;
    // The sets which hold home for each color
    set<string, greater<string>> bHome;
    set<string, greater<string>> yHome;
    set<string, greater<string>> gHome;
    set<string, greater<string>> rHome;
    // The sets which hold start for each color
    set<string, greater<string>> bStart;
    set<string, greater<string>> yStart;
    set<string, greater<string>> gStart;
    set<string, greater<string>> rStart;
    set<string, greater<string>>::iterator setItr; // Iterator for start/home
    const int pwnCnt = 3; // Number of pawns 
    queue <char> colors; // A queue to manage color order on board
    // Info on each pawns position, can be efficiently searched through
public:
    Board();
    virtual ~Board();
    void outputBrd();
    void initColors();
    char nextColor(char); // next color after a given color
    char nextColor(); // next color after the current color
    int getPwnCnt() { return pwnCnt; }
    bool swapMove(string, string, bool, string, string, bool);
    bool forwardMove(string, string, bool, int);
    string getPawnPosition(string);
    void erasePos(string, string);
    bool backwardMove(string, string, bool, int);
};

#endif /* BOARD_H */

