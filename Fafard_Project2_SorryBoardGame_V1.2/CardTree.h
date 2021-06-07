/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CardTree.h
 * Author: Drake
 *
 * Created on June 6, 2021, 6:52 PM
 */

#ifndef CARDTREE_H
#define CARDTREE_H
#include <string>
using namespace std;
class CardTree {
public:
    CardTree(string);
    CardTree(string, int);
    virtual ~CardTree();
    string getCard();
    void setLink(int, CardTree *);
    CardTree *accessLink(int);
private:
    string data;
    CardTree **CardNode;
    int size;
};

#endif /* CARDTREE_H */

