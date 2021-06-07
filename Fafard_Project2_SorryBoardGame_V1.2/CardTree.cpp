/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CardTree.cpp
 * Author: Drake
 * 
 * Created on June 6, 2021, 6:52 PM
 */

#include "CardTree.h"

CardTree::CardTree(string newData) {
    CardNode = new CardTree*[0];
    data = newData;
    size = 0;
}
CardTree::CardTree(string newData, int newSize) {
    CardNode = new CardTree*[size];
    for (int i=0; i<newSize; i++) {
        CardNode[i] = NULL;
    }
    data = newData;  
    size = newSize;
}

CardTree::~CardTree() {
    delete []CardNode;
}

void CardTree::setLink(int lnkIndx, CardTree *obj) {
    if (lnkIndx < size && lnkIndx>= 0)
        CardNode[lnkIndx] = obj;
}
CardTree *CardTree::accessLink(int lnkIndx) {
    if (lnkIndx < size && lnkIndx>= 0)
        return CardNode[lnkIndx];
    else return NULL;
}
string CardTree::getCard() {
    return data;
}