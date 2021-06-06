/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: Drake
 * 
 * Created on May 3, 2021, 11:31 AM
 */

#include "Menu.h"

Menu::Menu() {
    string sInp;
    gameInst = new Game();
    this->rules();
    cout << "\nStart new game? (yes/no): ";
    cin >> sInp;
    cin.ignore();
    while (sInp=="yes") {
        gameInst->start();
        cout << "\nStart new game? (yes/no): ";
        cin >> sInp;
        cin.ignore();
    }
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
    delete gameInst;
}

void Menu::rules() {
    cout << "***Rules***\nhttps://www.ultraboardgames.com/sorry/game-rules.php";
    cout << "\n> Pawns <\n(1) There are 3 pawns for each color.\n";
    cout << "(2) Each pawn starts at the start zone on their color's side.\n";
    cout << "> Goal <\n(1) The goal is to have all 3 pawns for your color";
    cout << "reach home.\n(2) Whoever reaches the goal first wins the game.\n";
    cout << "> Starting a pawn <\n(1) Any forward moving card can move a pawn ";
    cout << "out of start.";
    cout << "> The Board <\n(1) The pawns move clockwise through the board.\n";
    cout << "(2) The pawns cannot slide on a slide on their color's side.\n";
    cout << "(3) When a pawn finishes the move at the start of a slide, it";
    cout << " will slide to the end of the slide,\nknocking down *any* pawns";
    cout << " in the path and sending them back to their start.";
    cout << "\n(4) When moving normally, the pawn will jump over other pawns ";
    cout << ",leaving them unaffected.\n";
    cout << "(5) When landing on a space, the pawn will bump any pawn on that ";
    cout << "space back to their start.\n(6) Safety zones are the zones filled";
    cout << " with ** proceeding Home, they prohibit swaps from other pawns\n";
    cout << "(7) Safety zone entrances of your color cannot be passed with ";
    cout << "forward movement,\nbut you may move backwards to before the ";
    cout << "entrance.\n";
    cout << "> Home <\n(1) To reach home, the pawn must land in home with no";
    cout << " movement left, otherwise the move is invalid.\n";
    cout << "> Cards <\n";
    cout << gameInst->getCrdRule(1);
    cout << gameInst->getCrdRule(2);
    cout << gameInst->getCrdRule(3);
    cout << gameInst->getCrdRule(4);
    cout << gameInst->getCrdRule(5);
    cout << gameInst->getCrdRule(7);
    cout << gameInst->getCrdRule(8);
    cout << gameInst->getCrdRule(10);
    cout << gameInst->getCrdRule(11);
    cout << gameInst->getCrdRule(12);
    cout << gameInst->getCrdRule(0);
}