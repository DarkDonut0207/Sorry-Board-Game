/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cards.cpp
 * Author: Drake
 * 
 * Created on October 30, 2020, 9:12 PM
 */

#include "Cards.h"

Cards::Cards() {
    deckSze = 45;
    cardTps = new int [deckSze];
    string gDesc;
    // Initialize cards
    fill (cardTps, cardTps+4, 0);
    fill (cardTps+4, cardTps+9, 1);
    fill (cardTps+9, cardTps+13, 2);
    fill (cardTps+13, cardTps+17, 3);
    fill (cardTps+17, cardTps+21, 4);
    fill (cardTps+21, cardTps+25, 5);
    fill (cardTps+25, cardTps+29, 7);
    fill (cardTps+29, cardTps+33, 8);
    fill (cardTps+33, cardTps+37, 10);
    fill (cardTps+37, cardTps+41, 11);
    fill (cardTps+41, cardTps+45, 12);
    gDesc = "(Sorry) Move a pawn from your start area to take the place of ";
    gDesc+= "another player's pawn, which must\n       return to its own start";
    gDesc+= " area. Or move one of your pawns forward four spaces.\n     - If ";
    gDesc+= "there is no pawn on your start or no opponent's pawn is on any ";
    gDesc+= "space you can move to and\n       you cannot move any of your ";
    gDesc+= "pawns four spaces, you forfeit your turn.\n";
    cardDesc.insert(pair<int, string>(0, gDesc));
    gDesc = "(1) Move one of your pawns forward one space.\n";
    cardDesc.insert(pair<int, string>(1, gDesc));
    gDesc = "(2) Move one of your pawns forward two spaces.\n";
    gDesc = "    Then draw again.\n";
    cardDesc.insert(pair<int, string>(2, gDesc));
    gDesc = "(3) Move one of your pawns forward three spaces.\n";
    cardDesc.insert(pair<int, string>(3, gDesc));
    gDesc = "(4) Move one of your pawns backward four spaces.\n";
    cardDesc.insert(pair<int, string>(4, gDesc));
    gDesc = "(5) Move one of your pawns forward five spaces.\n";
    cardDesc.insert(pair<int, string>(5, gDesc));
    gDesc = "(7) Move one of your pawns forward seven spaces or split";
    gDesc+= " the forward move between two of your pawns\n  - If you use part";
    gDesc+= " of the seven to get a pawn home, you must be able to use the";
    gDesc+= " balance \n    of the move for another pawn.\n";
    cardDesc.insert(pair<int, string>(7, gDesc));
    gDesc = "(8) Move one of your pawns forward eight spaces.\n";
    cardDesc.insert(pair<int, string>(8, gDesc));
    gDesc = "(10) Move one of your pawns forward ten spaces or move one of";
    gDesc+= " your pawns backward one space.\n";
    cardDesc.insert(pair<int, string>(10, gDesc));
    gDesc = "(11) Move one of your pawns forward 11 spaces or switch any one ";
    gDesc+= "of your pawns with an opponent's.\n  - You may forfeit your move ";
    gDesc+= "if you do not wish to change places and it is impossible to go";
    gDesc+= "\n    forward 11 spaces.\n  - You may only switch pawns in play ";
    gDesc+= "on the open track, not at start, home, or in a safety zone.\n  - ";
    gDesc+= "If your switch landed you on a triangle at the beginning of a ";
    gDesc+= "slide that shows your color,\n    slide to the end.\n";
    cardDesc.insert(pair<int, string>(11, gDesc));
    gDesc = "(12) Move one of your pawns forward 12 spaces.\n";
    cardDesc.insert(pair<int, string>(12, gDesc));
    this->shuffle();
}

Cards::~Cards() {
    cout << "DELETING CARDS";
    delete []cardTps;
}

void Cards::shuffle() {
    random_shuffle (cardTps, cardTps+deckSze); // Shuffle card list
    while (!deck.empty()) // Reset deck
        deck.pop();
    for(int i = 0; i<deckSze; i++)
        deck.push(cardTps[i]);
}

int Cards::draw() {
    if (!deck.empty()) {
        int tempCd = deck.top();
        deck.pop();
        return tempCd;
    }
    else this->shuffle();
        int tempCd = deck.top();
        deck.pop();
        return tempCd;
}

string Cards::getCrdRule(int gCard) {
    return cardDesc[gCard];
}