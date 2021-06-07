/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cards.h
 * Author: Drake
 *
 * Created on October 30, 2020, 9:12 PM
 */

#ifndef CARDS_H
#define CARDS_H
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
#include <string>
#include "Board.h"
#include "CardTree.h"
using namespace std;

class Cards : public Board{
public:
    Cards();
    virtual ~Cards();
    void shuffle();
    int draw();
    string getCrdRule(int);
    void merge(int[], int, int, int);
    void mergeSort(int[],int,int);
    void outputCardTypes();
    void cardDisp(int);
    string cardTree();
private:
    int deckSze;
    // CardTps is array so shuffle will work with it
    int *cardTps; // List of all the card types and repeated for how many of each
    map<int, string> cardDesc; // Map of cards and their description
    stack <int> deck; // The deck
    CardTree *CardNode;
};

#endif /* CARDS_H */

