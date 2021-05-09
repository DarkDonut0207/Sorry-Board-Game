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
    Menu *menuInst = new Menu();
    delete menuInst;
    return 0;
}

