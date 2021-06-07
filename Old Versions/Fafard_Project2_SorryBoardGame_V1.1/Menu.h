/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: Drake
 *
 * Created on May 3, 2021, 11:31 AM
 */

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Game.h"
using namespace std;
class Menu {
private:
    Game *gameInst;
public:
    Menu();
    virtual ~Menu();
    void rules();
};

#endif /* MENU_H */

