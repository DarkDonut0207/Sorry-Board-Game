/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Drake
 * 
 * Created on May 2, 2021, 11:16 PM
 */

#include "Game.h"

Game::Game() {
    ifstream recWinF;
    int indx = 0;
    string gName;
    recWinF.open("recentWinners.txt");
    while(!recWinF.eof()) {
        //if (indx>0) recWinF.ignore(2);
        getline (recWinF,gName);
        if (!gName.empty() && gName[gName.size() - 1] == '\r') {
            gName.erase(gName.size() - 1);
        }
        if (!gName.empty() && gName[gName.size() - 1] == '\n') {
            gName.erase(gName.size() - 1);
        }
        recWinner.push(gName);
        indx++;
    }
    pwnInf.insert(pair<string, string>("B1", "Bb")); // b represents beginning
    pwnInf.insert(pair<string, string>("B2", "Bb"));
    pwnInf.insert(pair<string, string>("B3", "Bb"));
    pwnInf.insert(pair<string, string>("Y1", "Yb"));
    pwnInf.insert(pair<string, string>("Y2", "Yb"));
    pwnInf.insert(pair<string, string>("Y3", "Yb"));
    pwnInf.insert(pair<string, string>("G1", "Gb"));
    pwnInf.insert(pair<string, string>("G2", "Gb"));
    pwnInf.insert(pair<string, string>("G3", "Gb"));
    pwnInf.insert(pair<string, string>("R1", "Rb"));
    pwnInf.insert(pair<string, string>("R2", "Rb"));
    pwnInf.insert(pair<string, string>("R3", "Rb"));
    recWinF.close();
}

Game::~Game() {
    ofstream recWinF;
    queue<string> winList = recWinner;
    // Open recent winners file
    recWinF.open ("recentWinners.dat", ofstream::trunc);
    while (!winList.empty()) {
        recWinF << winList.front();
        winList.pop();
        if (!winList.empty()) {
            recWinF << "\n";
        }
    }
    // Close recent winners file
    recWinF.close();
}

void Game::getPlayers() {
    string tempName;
    int choice;
    int itr = 0;
    cout << "\n***Setting Up Players***\n";
    cout << "\nInput player name: ";
    getline(cin, tempName);
    plyrList.push_back(tempName);
    for (int i=1; i<4; i++) {
        cout << "Input player name: ";
        getline(cin, tempName);
        for(pLstItr = plyrList.begin(); pLstItr != plyrList.end(); ++pLstItr) {
            while (tempName==*pLstItr) {
                cout << "Name is already in use, input player name: ";
                getline(cin, tempName);
            }
        }
        plyrList.push_back(tempName);
    }
    cout << "Go in order of:\n(1) inputted name\n(2) alphabetical order\n";
    cout << "(3) reverse alphabetical order\nInput choice: ";
    cin >> choice;
    if (choice == 2) {
        plyrList.sort();
    } else if (choice == 3) {
        plyrList.sort();
        plyrList.reverse();
    }
    cout << "Order of play: ";
    for(pLstItr = plyrList.begin(); pLstItr != plyrList.end(); ++pLstItr) {
        itr++;
        plyrMap.insert(pair<string, char>(*pLstItr, this->nextColor()));
        cout << *pLstItr << " ("; 
        cout << plyrMap[*pLstItr];
        cout << ")";
        if (itr<4) cout << " >> ";
    }
    cout << endl;
}
void Game::turn () {
    map<string, char>::iterator curPlyr;
    map<string, string>::iterator pawnItr;
    string pawn;
    string p1;
    string p2;
    string p3;
    string swapPawn;
    //char numCho;
    int curCard = 0;
    int itr;
    int sp1;
    int sp2;
    int sp3;
    int choice;
    curPlyr = plyrMap.find(plyrList.front());
    do {
        this->outputBrd();
        // Move validity, starts at false until a case appears that is valid
        bool vlidSwap = false;
        bool vlidMove = false;
        bool vlidMBck = false;
        bool pswap[this->getPwnCnt()];
        bool pbmove[this->getPwnCnt()];
    bool pmove[this->getPwnCnt()];
    for (int i=0; i<this->getPwnCnt(); i++) {
        pswap[i] = false;
        pmove[i] = false;
        pbmove[i] = false;
    }
    
    curCard = this->draw(); // Draw a card
    cout << "\n*" << curPlyr->first << "'s turn (color " << curPlyr->second;
    cout << ")\nDrawing card...\n";
    switch (curCard) {
        case 0:
            cout << this->getCrdRule(curCard); // Output Card rule
            // Test moves on all of player's pawns
            itr = 0;
            //swapMove(string pawn, string pos, bool realMove, 
            //         string swapPawn, string swapPos, bool sorrySwp)
            for (pawnItr=pwnInf.begin();pawnItr!=pwnInf.end();++pawnItr) { // Loop through the pawns
                for (int i=0; i<this->getPwnCnt(); i++) {
                    pawn = curPlyr->second;
                    pawn+= '1'+i;
                    pswap[i] = this->swapMove(pawn, pwnInf[pawn], false, pawnItr->first, pawnItr->second, true);
                    if (pswap[i]) vlidSwap = true;
                }
            }
            for (int i=0; i<this->getPwnCnt(); i++) {
                pawn = curPlyr->second;
                pawn+= '1'+i;
                pmove[i] = this->forwardMove(pawn, pwnInf[pawn], false, 4);
                if (pmove[i]) vlidMove = true;
            }
            if (vlidMove || vlidSwap) {
                cout << "Available Pawn Moves: \nSwap: ";
                for (int i=0; i<this->getPwnCnt(); i++) {
                    if (pswap[i]) {
                        pawn = curPlyr->second;
                        pawn+= '1'+i;
                    }
                }
                cout << "\nMove Forward: ";
                for (int i=0; i<this->getPwnCnt(); i++) {
                    if (pmove[i]) {
                        pawn = curPlyr->second;
                        pawn+= '1'+i;
                    }
                }
                cout << "Which pawn would you like to move?";
                cout << "\nInput choice: ";
                cin >> pawn;
                pawn[0] = curPlyr->second;
                if (vlidSwap && vlidMove) {
                cout << "(1) Use Sorry Card Swap\n(2) Move Forward 4";
                cout << "\nInput choice: ";
                cin >> choice;
                    while (choice !=1 && choice!=2) {
                        cout << "(1) Use Sorry Card Swap\n(2) Move Forward 4";
                        cout << "\nInput choice: ";
                        cin >> choice;
                    }
                    if (choice == 1) {
                        cout << "Which pawn would you like to swap with?";
                    cout << "\nInput choice: ";
                    cin >> swapPawn;
                    while (!this->swapMove(pawn, pwnInf[pawn], false, swapPawn, pwnInf[swapPawn], true)) {
                        cout << "\nInvalid Move\n";
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                        cout << "Which pawn would you like to swap with?";
                        cout << "\nInput choice: ";
                        cin >> swapPawn;
                    }
                    this->swapMove(pawn, pwnInf[pawn], true, swapPawn, pwnInf[swapPawn], true);
                    } else {
                        while (!this->forwardMove(pawn, pwnInf[pawn], false, 4)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                    this->forwardMove(pawn, pwnInf[pawn], true, 4);
                    }
                } else if (vlidSwap) {
                    cout << "Which pawn would you like to swap with?";
                    cout << "\nInput choice: ";
                    cin >> swapPawn;
                    while (!this->swapMove(pawn, pwnInf[pawn], false, swapPawn, pwnInf[swapPawn], true)) {
                        cout << "\nInvalid Move\n";
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                        cout << "Which pawn would you like to swap with?";
                        cout << "\nInput choice: ";
                        cin >> swapPawn;
                    }
                    this->swapMove(pawn, pwnInf[pawn], true, swapPawn, pwnInf[swapPawn], true);
                } else if (vlidMove) {
                    while (!this->forwardMove(pawn, pwnInf[pawn], false, 4)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                    this->forwardMove(pawn, pwnInf[pawn], true, 4);
                }
            } else cout << "No Available Pawn Moves, Skipping Turn";
            break;
        case 4: 
            cout << this->getCrdRule(curCard);
            for (int i=0; i<this->getPwnCnt(); i++) {
                pawn = curPlyr->second;
                pawn+= '1'+i;
                pbmove[i] = this->backwardMove(pawn, pwnInf[pawn], false, curCard);
                if (pbmove[i]) vlidMove = true;
            }
            if (vlidMove) {
                cout << "Which pawn would you like to move?";
                cout << "\nInput choice: ";
                cin >> pawn;
                pawn[0] = curPlyr->second;
                while (!this->backwardMove(pawn, pwnInf[pawn], false, curCard)) {
                    cout << "\nInvalid Move\n";
                    cout << "Which pawn would you like to move?";
                    cout << "\nInput choice: ";
                    cin >> pawn;
                    pawn[0] = curPlyr->second;
                }
                this->backwardMove(pawn, pwnInf[pawn], true, curCard);
            } else cout << "\nNo Available Pawn Moves, Skipping Turn\n";
            break;
        case 1: // Cards 1, 2, 3, 4, 5, 8 have the same mechanics
        case 2: 
        case 3: 
        case 5: 
        case 8:
        case 12: 
            cout << this->getCrdRule(curCard);
            for (int i=0; i<this->getPwnCnt(); i++) {
                pawn = curPlyr->second;
                pawn+= '1'+i;
                pmove[i] = this->forwardMove(pawn, pwnInf[pawn], false, curCard);
                if (pmove[i]) vlidMove = true;
            }
            if (vlidMove) {
                cout << "Which pawn would you like to move?";
                cout << "\nInput choice: ";
                cin >> pawn;
                pawn[0] = curPlyr->second;
                while (!this->forwardMove(pawn, pwnInf[pawn], false, curCard)) {
                    cout << "\nInvalid Move\n";
                    cout << "Which pawn would you like to move?";
                    cout << "\nInput choice: ";
                    cin >> pawn;
                }
                this->forwardMove(pawn, pwnInf[pawn], true, curCard);
            } else cout << "\nNo Available Pawn Moves, Skipping Turn\n";
            break;
        case 7: 
            p1 = curPlyr->second;
            p1+= '1';
            p2 = curPlyr->second;
            p2+= '2';
            p3 = curPlyr->second;
            p3+= '3';
            cout << this->getCrdRule(curCard);
            cout << "How many spaces would you like to move pawn 1? ";
            sp1 = intInput();
            cout << "How many spaces would you like to move pawn 2? ";
            sp2 = intInput();
            cout << "How many spaces would you like to move pawn 3? ";
            sp3 = intInput();
            choice = 2;
            while (((!this->forwardMove(p1, pwnInf[p1], false, sp1) 
                    || !this->forwardMove(p2, pwnInf[p2], false, sp2) 
                    || !this->forwardMove(p3, pwnInf[p3], false, sp3)) || sp1+sp2+sp3!=7)
                    && choice == 2) {
                cout << "\nInvalid move, forfeit or try again? (1, 2): ";
                choice = intInput();
                if (choice == 2) {
                    cout << "How many spaces would you like to move pawn 1? ";
                    sp1 = intInput();
                    cout << "How many spaces would you like to move pawn 2? ";
                    sp2 = intInput();
                    cout << "How many spaces would you like to move pawn 3? ";
                    sp3 = intInput();
                }
            }
            if (choice == 2) {
                this->forwardMove(p1, pwnInf[p1], true, sp1);
                this->forwardMove(p2, pwnInf[p2], true, sp2);
                this->forwardMove(p3, pwnInf[p3], true, sp3);
            }
            break;
        case 10: 
            cout << this->getCrdRule(curCard);
            for (int i=0; i<this->getPwnCnt(); i++) {
                pawn = curPlyr->second;
                pawn+= '1'+i;
                pmove[i] = this->forwardMove(pawn, pwnInf[pawn], false, curCard);
                pbmove[i] = this->backwardMove(pawn, pwnInf[pawn], false, 1);
                if (pmove[i]) vlidMove = true;
                if (pbmove[i]) vlidMBck = true;
            }
            
            if (vlidMove || vlidMBck) {
                if(vlidMove && vlidMBck) {
                    cout << "Which pawn would you like to move?";
                    cout << "\nInput choice: ";
                    cin >> pawn;
                    pawn[0] = curPlyr->second;
                    cout << "Move pawn (1) Forward 10 (2) Backward 1: ";
                    choice = intInput();
                    while (choice != 1 && choice != 2) {
                        cout << "Invalid choice, re-enter: ";
                        choice = intInput();
                    }
                    if (choice==2) {
                        while (!this->backwardMove(pawn, pwnInf[pawn], false, 1)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move backward 1?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                        this->backwardMove(pawn, pwnInf[pawn], true, 1);
                    } else if (choice == 1) {
                        while (!this->forwardMove(pawn, pwnInf[pawn], false, curCard)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move forward 10?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                        this->forwardMove(pawn, pwnInf[pawn], true, curCard);
                    }
                }
                else if (vlidMBck) {
                    cout << "Which pawn would you like to move backward 1?";
                    cout << "\nInput choice: ";
                    cin >> pawn;
                    pawn[0] = curPlyr->second;
                    while (!this->backwardMove(pawn, pwnInf[pawn], false, 1)) {
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move backward 1?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                    }
                    this->backwardMove(pawn, pwnInf[pawn], true, 1);
                }
                else if (vlidMove) {
                    cout << "Which pawn would you like to move forward 10?";
                    cout << "\nInput choice: ";
                    cin >> pawn;
                    pawn[0] = curPlyr->second;
                    while (!this->forwardMove(pawn, pwnInf[pawn], false, curCard)) {
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move forward 10?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                    }
                    this->forwardMove(pawn, pwnInf[pawn], true, curCard);
                }
            } else cout << "\nNo Available Pawn Moves, Skipping Turn\n";
            break; 
        case 11: 
            for (pawnItr=pwnInf.begin();pawnItr!=pwnInf.end();++pawnItr) { // Loop through the pawns
                for (int i=0; i<this->getPwnCnt(); i++) {
                    pawn = curPlyr->second;
                    pawn+= '1'+i;
                    pswap[i] = this->swapMove(pawn, pwnInf[pawn], false, pawnItr->first, pawnItr->second, false);
                    if (pswap[i]) vlidSwap = true;
                }
            }
            for (int i=0; i<this->getPwnCnt(); i++) {
                pawn = curPlyr->second;
                pawn+= '1'+i;
                pmove[i] = this->forwardMove(pawn, pwnInf[pawn], false, 11);
                if (pmove[i]) vlidMove = true;
            }
            cout << this->getCrdRule(curCard);
            if (vlidMove || vlidSwap) {
                cout << "Which pawn would you like to move?";
                cout << "\nInput choice: ";
                cin >> pawn; 
                pawn[0] = curPlyr->second;
                if (vlidSwap && vlidMove) {
                cout << "(1) Use Swap\n(2) Move Forward 11";
                cout << "\nInput choice: ";
                choice = intInput();
                    while (choice !=1 && choice!=2) {
                        cout << "(1) Use Swap\n(2) Move Forward 11";
                        cout << "\nInput choice: ";
                        choice = intInput();
                    }
                    if (choice == 1) {
                        cout << "Which pawn would you like to swap with?";
                    cout << "\nInput choice: ";
                    cin >> swapPawn;
                    while (!this->swapMove(pawn, pwnInf[pawn], false, swapPawn, pwnInf[swapPawn], false)) {
                        cout << "\nInvalid Move\n";
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                        cout << "Which pawn would you like to swap with?";
                        cout << "\nInput choice: ";
                        cin >> swapPawn;
                    }
                    this->swapMove(pawn, pwnInf[pawn], true, swapPawn, pwnInf[swapPawn], false);
                    } else {
                        while (!this->forwardMove(pawn, pwnInf[pawn], false, 11)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                    this->forwardMove(pawn, pwnInf[pawn], true, 11);
                    }
                } else if (vlidSwap) {
                    cout << "Which pawn would you like to swap with?";
                    cout << "\nInput choice: ";
                    cin >> swapPawn;
                    while (!this->swapMove(pawn, pwnInf[pawn], false, swapPawn, pwnInf[swapPawn], false)) {
                        cout << "\nInvalid Move\n";
                        cout << "\nInvalid Move\n";
                        cout << "Which pawn would you like to move?";
                        cout << "\nInput choice: ";
                        cin >> pawn;
                        pawn[0] = curPlyr->second;
                        cout << "Which pawn would you like to swap with?";
                        cout << "\nInput choice: ";
                        cin >> swapPawn;
                    }
                    this->swapMove(pawn, pwnInf[pawn], true, swapPawn, pwnInf[swapPawn], false);
                } else if (vlidMove) {
                    while (!this->forwardMove(pawn, pwnInf[pawn], false, 11)) {
                            cout << "\nInvalid Move\n";
                            cout << "Which pawn would you like to move?";
                            cout << "\nInput choice: ";
                            cin >> pawn;
                            pawn[0] = curPlyr->second;
                        }
                    this->forwardMove(pawn, pwnInf[pawn], true, 11);
                }
            } else cout << "\nNo Available Pawn Moves, Skipping Turn\n";
            break;
    }
    this->updatePwnInf();
    } while (curCard == 2 && this->checkWin()==' '); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    plyrList.pop_front();
    plyrList.push_back(curPlyr->first);
}
void Game::updatePwnInf() {
    map <string, string>::iterator pwnItr;
    string newPos;
    for (pwnItr=pwnInf.begin(); pwnItr!=pwnInf.end();++pwnItr) {
        newPos = this->getPawnPosition(pwnItr->first);
        pwnItr->second = newPos;
    }
}
char Game::checkWin() {
    map <string, string>::iterator pwnItr;
    int gInc = 0;
    int bInc = 0;
    int rInc = 0;
    int yInc = 0;
    for (pwnItr=pwnInf.begin(); pwnItr!=pwnInf.end();++pwnItr) {
        if (pwnItr->first[0] == 'G') {
            if (pwnItr->second[1] == 'h') {
                gInc++;
            }
        }
        if (pwnItr->first[0] == 'B') {
            if (pwnItr->second[1] == 'h') {
                bInc++;
            }
        }
        if (pwnItr->first[0] == 'R') {
            if (pwnItr->second[1] == 'h') {
                rInc++;
            }
        }
        if (pwnItr->first[0] == 'Y') {
            if (pwnItr->second[1] == 'h') {
                yInc++;
            }
        }
    }
    if (gInc >= 3) {
        return 'G';
    }
    if (yInc >= 3) {
        return 'Y';
    }
    if (bInc >= 3) {
        return 'B';
    }
    if (rInc >= 3) {
        return 'R';
    }
    return ' ';
}
void Game::start() {
    map <string, char>::iterator plyrItr;
    char winColor;
    string winPlyr = "\0";
    if (!recWinner.empty()) {
        this->outputRecWinners();
    }
    this->getPlayers();
    while (this->checkWin()==' ') {
        this->turn();
    }
    this->outputBrd();
    winColor = this->checkWin();
    for (plyrItr = plyrMap.begin(); plyrItr != plyrMap.end(); ++plyrItr) {
        if (plyrItr->second == winColor) {
            winPlyr = plyrItr->first;
        }
    }
    cout << winPlyr << " (" << this->checkWin() << ") has won.";
    if (winPlyr!="\0") {
        recWinner.push(winPlyr);
        if (recWinner.size() > 10) {
            recWinner.pop();
        }
    }
}
int Game::intInput() {
    int anInt;
    cin >> anInt;
    if (!cin.good()) { // If the input wasnt an integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Issue with input, re-input: \n";
        cin >> anInt;
    }
    return anInt;
}
void Game::outputRecWinners() {
    queue<string> winList = recWinner;
    int inc = 0;
    cout << "Recent winners:  ";
    while (!winList.empty() && inc<10) {
        if (inc!=0) cout << " - ";
        cout << winList.front();
        winList.pop();
        inc++;
    }
}