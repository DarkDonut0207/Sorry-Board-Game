/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: Drake
 * 
 * Created on October 30, 2020, 10:21 PM
 */

#include "Board.h"

Board::Board() {
    // Initialize the map containing board information
    brdInf.insert(pair<string, string>("Bn0", "--"));
    brdInf.insert(pair<string, string>("Bn1", "--"));
    brdInf.insert(pair<string, string>("Bn2", "--"));
    brdInf.insert(pair<string, string>("Bn3", "--"));
    brdInf.insert(pair<string, string>("Bn4", "--"));
    brdInf.insert(pair<string, string>("Bn5", "--"));
    brdInf.insert(pair<string, string>("Bs0", "->"));
    brdInf.insert(pair<string, string>("Bs1", ">>"));
    brdInf.insert(pair<string, string>("Bs2", ">>"));
    brdInf.insert(pair<string, string>("Bs3", ">-"));
    brdInf.insert(pair<string, string>("Bs4", "->"));
    brdInf.insert(pair<string, string>("Bs5", ">>"));
    brdInf.insert(pair<string, string>("Bs6", ">>"));
    brdInf.insert(pair<string, string>("Bs7", ">>"));
    brdInf.insert(pair<string, string>("Bs8", ">-"));
    brdInf.insert(pair<string, string>("Bg0", "**")); // g: guarded (safe zone)
    brdInf.insert(pair<string, string>("Bg1", "**")); 
    brdInf.insert(pair<string, string>("Bg2", "**"));
    brdInf.insert(pair<string, string>("Bg3", "**"));
    brdInf.insert(pair<string, string>("Bg4", "**"));
    brdInf.insert(pair<string, string>("Yn0", "--"));
    brdInf.insert(pair<string, string>("Yn1", "--"));
    brdInf.insert(pair<string, string>("Yn2", "--"));
    brdInf.insert(pair<string, string>("Yn3", "--"));
    brdInf.insert(pair<string, string>("Yn4", "--"));
    brdInf.insert(pair<string, string>("Yn5", "--"));
    brdInf.insert(pair<string, string>("Ys0", "-v"));
    brdInf.insert(pair<string, string>("Ys1", "vv"));
    brdInf.insert(pair<string, string>("Ys2", "vv"));
    brdInf.insert(pair<string, string>("Ys3", "v-"));
    brdInf.insert(pair<string, string>("Ys4", "-v"));
    brdInf.insert(pair<string, string>("Ys5", "vv"));
    brdInf.insert(pair<string, string>("Ys6", "vv"));
    brdInf.insert(pair<string, string>("Ys7", "vv"));
    brdInf.insert(pair<string, string>("Ys8", "v-"));
    brdInf.insert(pair<string, string>("Yg0", "**"));
    brdInf.insert(pair<string, string>("Yg1", "**"));
    brdInf.insert(pair<string, string>("Yg2", "**"));
    brdInf.insert(pair<string, string>("Yg3", "**"));
    brdInf.insert(pair<string, string>("Yg4", "**"));
    brdInf.insert(pair<string, string>("Gn0", "--"));
    brdInf.insert(pair<string, string>("Gn1", "--"));
    brdInf.insert(pair<string, string>("Gn2", "--"));
    brdInf.insert(pair<string, string>("Gn3", "--"));
    brdInf.insert(pair<string, string>("Gn4", "--"));
    brdInf.insert(pair<string, string>("Gn5", "--"));
    brdInf.insert(pair<string, string>("Gs0", "<-"));
    brdInf.insert(pair<string, string>("Gs1", "<<"));
    brdInf.insert(pair<string, string>("Gs2", "<<"));
    brdInf.insert(pair<string, string>("Gs3", "-<"));
    brdInf.insert(pair<string, string>("Gs4", "<-"));
    brdInf.insert(pair<string, string>("Gs5", "<<"));
    brdInf.insert(pair<string, string>("Gs6", "<<"));
    brdInf.insert(pair<string, string>("Gs7", "<<"));
    brdInf.insert(pair<string, string>("Gs8", "-<"));
    brdInf.insert(pair<string, string>("Gg0", "**"));
    brdInf.insert(pair<string, string>("Gg1", "**"));
    brdInf.insert(pair<string, string>("Gg2", "**"));
    brdInf.insert(pair<string, string>("Gg3", "**"));
    brdInf.insert(pair<string, string>("Gg4", "**"));
    brdInf.insert(pair<string, string>("Rn0", "--"));
    brdInf.insert(pair<string, string>("Rn1", "--"));
    brdInf.insert(pair<string, string>("Rn2", "--"));
    brdInf.insert(pair<string, string>("Rn3", "--"));
    brdInf.insert(pair<string, string>("Rn4", "--"));
    brdInf.insert(pair<string, string>("Rn5", "--"));
    brdInf.insert(pair<string, string>("Rs0", "^-"));
    brdInf.insert(pair<string, string>("Rs1", "^^"));
    brdInf.insert(pair<string, string>("Rs2", "^^"));
    brdInf.insert(pair<string, string>("Rs3", "-^"));
    brdInf.insert(pair<string, string>("Rs4", "^-"));
    brdInf.insert(pair<string, string>("Rs5", "^^"));
    brdInf.insert(pair<string, string>("Rs6", "^^"));
    brdInf.insert(pair<string, string>("Rs7", "^^"));
    brdInf.insert(pair<string, string>("Rs8", "-^"));
    brdInf.insert(pair<string, string>("Rg0", "**"));
    brdInf.insert(pair<string, string>("Rg1", "**"));
    brdInf.insert(pair<string, string>("Rg2", "**"));
    brdInf.insert(pair<string, string>("Rg3", "**"));
    brdInf.insert(pair<string, string>("Rg4", "**"));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
    for (brdItr=brdInf.begin(); brdItr!=brdInf.end(); ++brdItr) {
        cout << brdItr->first << " - " << brdItr->second << endl;
    }
    // Initialize start sets, home sets are uninitialized since empty at first
    bStart.insert("B1");
    bStart.insert("B2");
    bStart.insert("B3");
    yStart.insert("Y1");
    yStart.insert("Y2");
    yStart.insert("Y3");
    gStart.insert("G1");
    gStart.insert("G2");
    gStart.insert("G3");
    rStart.insert("R1");
    rStart.insert("R2");
    rStart.insert("R3");
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
    // Initialize pawn information map, used to track their location quickly
    this->initColors();
}

Board::~Board() {
    cout << "DELETING BOARD";
}

void Board::outputBrd() {
    // Temporary set iterators
    set<string, greater<string>>:: iterator bStItr = bStart.begin();
    set<string, greater<string>>:: iterator yStItr = yStart.begin();
    set<string, greater<string>>:: iterator gStItr = gStart.begin();
    set<string, greater<string>>:: iterator rStItr = rStart.begin();
    set<string, greater<string>>:: iterator bHoItr = bHome.begin();
    set<string, greater<string>>:: iterator yHoItr = yHome.begin();
    set<string, greater<string>>:: iterator gHoItr = gHome.begin();
    set<string, greater<string>>:: iterator rHoItr = rHome.begin();
    cout << "\n                       B L U E\n";
    cout << "          s l i d e                s l i d e\n";
    cout << "     |" << brdInf["Bn0"] << "|" << brdInf["Bs0"] << "|";
    cout << brdInf["Bs1"] << "|" << brdInf["Bs2"] << "|" << brdInf["Bs3"];
    cout << "|" << brdInf["Bn1"] << "|" << brdInf["Bn2"] << "|";
    cout << brdInf["Bn3"] << "|" << brdInf["Bn4"] << "|" << brdInf["Bs4"];
    cout << "|" << brdInf["Bs5"] << "|" << brdInf["Bs6"] << "|";
    cout << brdInf["Bs7"] << "|" << brdInf["Bs8"] << "|" << brdInf["Bn5"];
    cout << "|" << brdInf["Yn0"] << "|\n     |" << brdInf["Rn5"] << "|  |";
    cout << brdInf["Bg0"] << "|  |";
    cout << ((bStItr != bStart.end()) ? *(bStItr++) : "  ");
    cout << "| S                           |" << brdInf["Ys0"] << "| s\n   s |";
    cout << brdInf["Rs8"] << "|  |" << brdInf["Bg1"] << "|  |";
    cout << ((bStItr != bStart.end()) ? *(bStItr++) : "  ") << "| T      H  |";
    cout << ((yHoItr != yHome.end()) ? *(yHoItr++) : "  ");
    cout << "|" << brdInf["Yg4"] << "|" << brdInf["Yg3"] <<  "|";
    cout << brdInf["Yg2"] << "|" << brdInf["Yg1"] << "|" << brdInf["Yg0"];
    cout << "|" << brdInf["Ys1"] << "| l\n   l |" << brdInf["Rs7"] << "|  |";
    cout << brdInf["Bg2"] << "|  |";
    cout << ((bStItr != bStart.end()) ? *(bStItr++) : "  ") << "| A      O  |";
    cout << ((yHoItr != yHome.end()) ? *(yHoItr++) : "  ")<< "|              |";
    cout << brdInf["Ys2"] << "| i\n   i |" << brdInf["Rs6"] << "|  |";
    cout << brdInf["Bg3"] << "|       R      M  |";
    cout << ((yHoItr != yHome.end()) ? *(yHoItr++) : "  ") << "|       |";
    cout << ((yStItr != yStart.end()) ? *(yStItr++) : "  ");
    cout << ((yStItr != yStart.end()) ? *(yStItr++) : "  ");
    cout << ((yStItr != yStart.end()) ? *(yStItr++) : "  ") << "|";
    cout << brdInf["Ys3"] << "| d Y\n   d |" << brdInf["Rs5"] << "|  |";
    cout << brdInf["Bg4"] << "|       T      E          S T A R T |";
    cout << brdInf["Yn1"] << "| e E\n   e |" << brdInf["Rs4"] << "|  |";
    cout << ((bHoItr != bHome.end()) ? *(bHoItr++) : "  ");
    cout << ((bHoItr != bHome.end()) ? *(bHoItr++) : "  ");
    cout << ((bHoItr != bHome.end()) ? *(bHoItr++) : "  ");
    cout << "|                               |" << brdInf["Yn2"] << "|   L\n R";
    cout << "   |" << brdInf["Rn4"] << "|  H O M E                            ";
    cout << "    |" << brdInf["Yn3"] << "|   L\n E   |" << brdInf["Rn3"];
    cout << "|                               H O M E   |" << brdInf["Yn4"];
    cout << "|   O\n D   |" << brdInf["Rn2"] << "|                            ";
    cout << "   |" << ((gHoItr != gHome.end()) ? *(gHoItr++) : "  ");
    cout << ((gHoItr != gHome.end()) ? *(gHoItr++) : "  ");
    cout << ((gHoItr != gHome.end()) ? *(gHoItr++) : "  ") << "|  |";
    cout << brdInf["Ys4"] << "| s W\n   s |" << brdInf["Rn1"] << "| S T A R T ";
    cout << "        H       S       |" << brdInf["Gg4"] << "|  |";
    cout << brdInf["Ys5"] << "| l\n   l |" << brdInf["Rs3"] << "|";
    cout << ((rStItr != rStart.end()) ? *(rStItr++) : "  ");
    cout << ((rStItr != rStart.end()) ? *(rStItr++) : "  ");
    cout << ((rStItr != rStart.end()) ? *(rStItr++) : "  ") << "|       |";
    cout << ((rHoItr != rHome.end()) ? *(rHoItr++) : "  ") << "| O       T    ";
    cout << "   |" << brdInf["Gg3"] << "|  |" << brdInf["Ys6"] << "| i\n   i |";
    cout << brdInf["Rs2"] << "|              |";
    cout << ((rHoItr != rHome.end()) ? *(rHoItr++) : "  ") << "| M       A |";
    cout << ((gStItr != gStart.end()) ? *(gStItr++) : "  ") << "|  |";
    cout << brdInf["Gg2"] << "|  |" << brdInf["Ys7"] << "| d\n   d |";
    cout << brdInf["Rs1"] << "|" << brdInf["Rg0"] << "|" << brdInf["Rg1"]<< "|";
    cout << brdInf["Rg2"] << "|" << brdInf["Rg3"] << "|" << brdInf["Rg4"]<< "|";
    cout << ((rHoItr != rHome.end()) ? *(rHoItr++) : "  ") << "| E       R |";
    cout << ((gStItr != gStart.end()) ? *(gStItr++) : "  ") << "|  |";
    cout << brdInf["Gg1"] << "|  |" << brdInf["Ys8"] << "| e\n   e |";
    cout << brdInf["Rs0"] << "|                           T |";
    cout << ((gStItr != gStart.end()) ? *(gStItr++) : "  ") << "|  |";
    cout << brdInf["Gg0"] << "|  |" << brdInf["Yn5"] << "|\n     |";
    cout << brdInf["Rn0"] << "|" << brdInf["Gn5"] << "|" << brdInf["Gs8"] <<"|";
    cout << brdInf["Gs7"] << "|" << brdInf["Gs6"] << "|" << brdInf["Gs5"] <<"|";
    cout << brdInf["Gs4"] << "|" << brdInf["Gn4"] << "|" << brdInf["Gn3"] <<"|";
    cout << brdInf["Gn2"] << "|" << brdInf["Gn1"] << "|" << brdInf["Gs3"] <<"|";
    cout << brdInf["Gs2"] << "|" << brdInf["Gs1"] << "|" << brdInf["Gs0"] <<"|";
    cout << brdInf["Gn0"] << "|\n               s l i d e               ";
    cout << " s l i d e\n                         G R E E N";
}
void Board::initColors() {
    this->colors.push('B');
    this->colors.push('Y');
    this->colors.push('G');
    this->colors.push('R');
}
char Board::nextColor(char curClr) {
    char nxtClr;
    
    while(colors.front() != curClr) {
        nxtClr = colors.front();
        colors.pop();
        colors.push(nxtClr);
    }
    nxtClr = this->colors.front();
    this->colors.pop();
    this->colors.push(nxtClr);
    nxtClr = this->colors.front();
    return nxtClr;
}
char Board::nextColor() {
    char nxtClr;
    nxtClr = this->colors.front();
    this->colors.pop();
    this->colors.push(nxtClr);
    nxtClr = this->colors.front();
    return nxtClr;
}
bool Board::swapMove(string pawn, string pos, bool realMove, 
                     string swapPawn, string swapPos, bool sorrySwp) {
    int sldTpe = 0; // Slide type
    string elimPawn; // Eliminated pawn
    if (pawn.length() > 2) return false;
    if (pos.length() > 3) return false;
    if (swapPawn.length() > 2) return false;
    if (swapPos.length() > 3) return false;
    if (pawn[1] != '1' && pawn[1] != '2' && pawn[1] != '3') return false;
    if (swapPawn[1] != '1' && swapPawn[1] != '2' && swapPawn[1] != '3') return false;
    if (pawn[0] != 'B' && pawn[0] != 'R' && pawn[0] != 'G' && pawn[0] != 'Y')
        return false;
    if (swapPawn[0] != 'B' && swapPawn[0] != 'R' 
            && swapPawn[0] != 'G' && swapPawn[0] != 'Y')
        return false;
    if (pos[1] == 'h' || swapPos[1] == 'h') return false; // home, cant be moved
    else if (pos[1] == 'g' || swapPos[1] == 'g') { 
        return false; // guarded, cant be moved
    } else if (swapPos[1] == 'b') {
        return false; // other pawn is in start, cant swap with it
    } else if (sorrySwp) { // If this is a sorry card type swap
        if (pos[1] == 'b') {
            if (realMove) {
                brdItr = brdInf.find(swapPos);
                // If this lands in a sliding spot
                if (swapPos[1] == 's' && (swapPos[2] == '0' || swapPos[2] == '4')
                        && pawn[0] != swapPos[0]) {
                    if (swapPos[2] == '0') sldTpe = 4;
                    if (swapPos[2] == '4') sldTpe = 5;
                    for (int i=0; i<sldTpe; i++) { // Loop through the slide, removing pawns on it
                        cout << "SLIDE: " << brdItr->first << endl;
                        if (i==0) { // start of slides have unique appearance
                            if (brdItr->second != "->" && brdItr->second != "-v" &&
                                brdItr->second != "<-" && brdItr->second != "^-") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                // Determine what color pawn was eliminated
                                if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                            }
                        } else if (i==sldTpe-1) { // End of slide
                            if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                brdItr->second != "-<" && brdItr->second != "-^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                // Determine what color pawn was eliminated
                                if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                            }
                            // Take new pawn out of their start
                            if (pawn[0] == 'B') bStart.erase(pawn);
                            else if (pawn[0] == 'Y') yStart.erase(pawn);
                            else if (pawn[0] == 'G') gStart.erase(pawn);
                            else if (pawn[0] == 'R') rStart.erase(pawn);  
                            brdItr->second = pawn; // Set the pawn here
                        } else { // rest of slide
                            if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                brdItr->second != "<<" && brdItr->second != "^^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                // Determine what color pawn was eliminated
                                if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                            }
                        }
                        brdItr++;
                    }
                } else {
                    // Send the swapped pawn back to their start
                    if (swapPawn[0] == 'B') bStart.insert(swapPawn);
                    else if (swapPawn[0] == 'Y') yStart.insert(swapPawn);
                    else if (swapPawn[0] == 'G') gStart.insert(swapPawn);
                    else if (swapPawn[0] == 'R') rStart.insert(swapPawn); 
                    brdItr->second = pawn; // Assign new pawn to that spot
                    // Take new pawn out of their start
                    if (pawn[0] == 'B') bStart.erase(pawn);
                    else if (pawn[0] == 'Y') yStart.erase(pawn);
                    else if (pawn[0] == 'G') gStart.erase(pawn);
                    else if (pawn[0] == 'R') rStart.erase(pawn);  
                }
            }
            return true;
        } else {
            return false; // If the original pawn wasnt at start, cant swap
        }
    } else if (!sorrySwp) { // 11 card type swap
        if (pos[1] == 'b') {
            return false; // Cannot swap if at start
        } else {
            if (realMove) {
                brdItr = brdInf.find(swapPos);
                // If this lands in a sliding spot
                if (swapPos[1] == 's' && (swapPos[2] == '0' || swapPos[2] == '4')
                        && pawn[0] != swapPos[0]) {
                    if (swapPos[2] == '0') sldTpe = 4;
                    if (swapPos[2] == '4') sldTpe = 5;
                    for (int i=0; i<sldTpe; i++) { // Loop through the slide, removing pawns on it
                        cout << "SLIDE: " << brdItr->first << endl;
                        if (i==0) { // start of slides have unique appearance
                            if (brdItr->second != "->" && brdItr->second != "-v" &&
                                brdItr->second != "<-" && brdItr->second != "^-") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != swapPawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                                
                            }
                        } else if (i==sldTpe-1) {
                            if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                brdItr->second != "-<" && brdItr->second != "-^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != swapPawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                                
                            }
                            brdItr->second = pawn; // Set the pawn here
                        } else { // rest of slide
                            if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                brdItr->second != "<<" && brdItr->second != "^^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != swapPawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                            }
                        }
                        brdItr++;
                    }
                } else {
                    brdItr->second = pawn; // Place new pawn in the other spot 
                } 
                brdItr = brdInf.find(pos); // Get position of the given pawn
                // If this lands in a sliding spot
                if (pos[1] == 's' && (pos[2] == '0' || pos[2] == '4')
                        && swapPawn[0] != pos[0]) {
                    if (pos[2] == '0') sldTpe = 4;
                    if (pos[2] == '4') sldTpe = 5;
                    for (int i=0; i<sldTpe; i++) { // Loop through the slide, removing pawns on it
                        cout << "SLIDE: " << brdItr->first << endl;
                        if (i==0) { // start of slides have unique appearance
                            if (brdItr->second != "->" && brdItr->second != "-v" &&
                                brdItr->second != "<-" && brdItr->second != "^-") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != pawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                                
                            }
                        } else if (i==sldTpe-1) {
                            if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                brdItr->second != "-<" && brdItr->second != "-^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != pawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                            }
                            brdItr->second = swapPawn; // Set the pawn here
                        } else { // rest of slide
                            if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                brdItr->second != "<<" && brdItr->second != "^^") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                if (elimPawn != pawn) {
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                            }
                        }
                        brdItr++;
                    }
                } else {
                    brdItr->second = swapPawn; // place swapped pawn in other spot
                }
            }
            return true;
        }
    } else return false;
}
bool Board::forwardMove(string pawn, string pos, bool realMove, int moveNum) {
    char newColor;
    string origPos = pos; // Original position
    string newPos;  // New position
    string elimPawn; // Eliminated pawn
    if (pawn.length() > 2) return false;
    if (pos.length() > 3) return false;
    if (pawn[1] != '1' && pawn[1] != '2' && pawn[1] != '3') return false;
    if (pawn[0] != 'B' && pawn[0] != 'R' && pawn[0] != 'G' && pawn[0] != 'Y')
        return false;
    if (moveNum == 0) return true; // Skip computations if it is a 0 move
    if (pos[1] == 'h') return false; // home, cant be moved
    for (int i=0; i<moveNum; i++) {
        if (pos[1] == 'b') { // Handle start
            newPos = pawn[0];
            newPos+= "s3";
            cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
            if (realMove) { // do a replace if this isn't just a test move
                if (i==moveNum-1) { // if this is the last move, push any pawn  
                    brdItr = brdInf.find(newPos);                
                    // account for the 4 starts, determine if there is a pawn outside
                    if (brdItr->second != ">-" && brdItr->second != "v-" &&
                        brdItr->second != "-<" && brdItr->second != "-^") { 
                        elimPawn = brdItr->second;
                        // Determine what color pawn was eliminated
                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                    }
                    brdItr->second = pawn; // Store the pawn in this spot
                    this->erasePos(origPos, pawn); // Take pawn off original spot
                }
            }
        } else if (pos[1] == 'n') { // Handle normal spots
            if (pos[2] == '0') { // First normal spot transitions to first slide
                newPos = pos[0];
                newPos+= "s0"; // Determine new position
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) { // do a replace if this isn't just a test move
                    // Slide is activated if this is the end of the move
                    if (i==moveNum-1) {
                        brdItr = brdInf.find(newPos); // find the start of slide
                        if (pawn[0] != newPos[0]) {// slides dont work on same color
                            for (int i=0; i<4; i++) { // Loop through the slide, removing pawns on it
                                cout << "SLIDE: " << brdItr->first << endl;
                                if (i==0) { // start of slides have unique appearance
                                    if (brdItr->second != "->" && brdItr->second != "-v" &&
                                        brdItr->second != "<-" && brdItr->second != "^-") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                } else if (i==3) {
                                    if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                        brdItr->second != "-<" && brdItr->second != "-^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                    brdItr->second = pawn; // Set the pawn here
                                } else { // rest of slide
                                    if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                        brdItr->second != "<<" && brdItr->second != "^^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                }
                                brdItr++;
                            }
                        } else {
                            // Eliminate a pawn on that spot
                            if (brdItr->second != "->" && brdItr->second != "-v" &&
                                    brdItr->second != "<-" && brdItr->second != "^-") { 
                                    elimPawn = brdItr->second;
                                    this->erasePos(brdItr->first, elimPawn);
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                            brdItr->second = pawn;
                        }
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                        return true;
                    }
                }
                
            } else if (pos[2] == '4') { // 5th normal spot transitions to 2nd slide
                newPos = pos[0];
                newPos+= "s4"; // Determine new position
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) { // do a replace if this isn't just a test move
                    // Slide is activated if this is the end of the move
                    if (i==moveNum-1) {
                        brdItr = brdInf.find(newPos); // find the start of slide
                        if (pawn[0] != newPos[0]) {// slides dont work on same color
                            for (int i=0; i<5; i++) { // Loop through the slide, removing pawns on it
                                cout << "SLIDE: " << brdItr->first << endl;
                                if (i==0) { // start of slides have unique appearance
                                    if (brdItr->second != "->" && brdItr->second != "-v" &&
                                        brdItr->second != "<-" && brdItr->second != "^-") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                } else if (i==4) {
                                    if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                        brdItr->second != "-<" && brdItr->second != "-^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                    brdItr->second = pawn; // Set the pawn here
                                } else { // rest of slide
                                    if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                        brdItr->second != "<<" && brdItr->second != "^^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                        // Determine what color pawn was eliminated
                                        if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                        else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                }
                                brdItr++;
                            }
                        } else {
                            // Eliminate a pawn on that spot
                            if (brdItr->second != "->" && brdItr->second != "-v" &&
                                    brdItr->second != "<-" && brdItr->second != "^-") { 
                                    elimPawn = brdItr->second;
                                    this->erasePos(brdItr->first, elimPawn);
                                    // Determine what color pawn was eliminated
                                    if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                    else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                }
                            brdItr->second = pawn;
                        }
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                        return true;
                    }
                }
            } else if (pos[2] == '5') { // Handle transition to another color side
                newColor = this->nextColor(pos[0]);
                newPos = newColor;
                newPos+= "n0";
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else { // Cover other normal positions
                newPos = pos[0]; // Same color
                newPos+= 'n'; // Does not transition to slide
                newPos+= pos[2]+1;
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        } else if (pos[1] == 's') { // Handle movement across slide spaces without sliding
            if (pos[2] == '3' || pos[2] == '8') { // End of slide: transition to normal spot
                newPos = pos[0]; // Same color
                newPos+= 'n'; // Transition to normal
                if (pos[2] == '3') newPos+= '1';
                else if (pos[2] == '8') newPos+= '5';
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else if (pos[2] == '1' && pos[0] == pawn[0]) { // Handle safety zone entrance
                newPos = pos[0]; // Same color
                newPos+= "g0"; // Beginning of safety zone
                cout << "SAFETY ZONE: " <<  newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "**") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else {
                newPos = pos[0]; // Same color
                newPos+= 's'; // Does not transition to slide
                newPos+= pos[2]+1;
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        } else if (pos[1] == 'g') { // Handle safety zones
            if (pos[2] == '4') { // Spot before home
                if (i==moveNum-1) { // If this is the end of the move
                    newPos = pos[0];
                    newPos+= 'h';
                    cout << newPos;
                    if (realMove) {
                        if (pawn[0] == 'B') bHome.insert(pawn);
                        else if (pawn[0] == 'Y') yHome.insert(pawn);
                        else if (pawn[0] == 'G') gHome.insert(pawn);
                        else if (pawn[0] == 'R') rHome.insert(pawn); 
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                    return true;
                } else return false;
            } else { // Rest of safety zone
                newPos = pos[0]; // Same color
                newPos+= 'g'; // Does not transition to slide
                newPos+= pos[2]+1;
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "**") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        }

            

        pos = newPos; // This will store the new position for further looping
    }
    return true;
}
string Board::getPawnPosition(string pawn) {
    string pos;
    // Search start and home for a color
    if (pawn[0] == 'B') { // Blue
        for (setItr = bStart.begin(); setItr!= bStart.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Bb";
            }
        }
        for (setItr = bHome.begin(); setItr!= bHome.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Bh";
            }
        }
    } else if (pawn[0] == 'Y') { // Yellow
        for (setItr = yStart.begin(); setItr!= yStart.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Yb";
            }
        }
        for (setItr = yHome.begin(); setItr!= yHome.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Yh";
            }
        }
    } else if (pawn[0] == 'G') { // Green
        for (setItr = gStart.begin(); setItr!= gStart.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Gb";
            }
        }
        for (setItr = gHome.begin(); setItr!= gHome.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Gh";
            }
        }
    } else if (pawn[0] == 'R') { // Red
        for (setItr = rStart.begin(); setItr!= rStart.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Rb";
            }
        }
        for (setItr = rHome.begin(); setItr!= rHome.end(); ++setItr) {
            if (*setItr == pawn) {
                return "Rh";
            }
        }
    }
    // Search the rest
    for (brdItr = brdInf.begin(); brdItr!= brdInf.end(); ++brdItr) {
        if (brdItr->second == pawn) return brdItr->first;
    }
    return "err"; // indicates an error: missing pawn
}
void Board::erasePos(string origPos, string pawn) {
    if (origPos[1] == 'b') { // If the pawn was originally at start
        if (pawn[0] == 'B') bStart.erase(pawn); // Take out of start
        else if (pawn[0] == 'Y') yStart.erase(pawn);
        else if (pawn[0] == 'G') gStart.erase(pawn);
        else if (pawn[0] == 'R') rStart.erase(pawn); 
    } else {
        brdItr = brdInf.find(origPos);    
        // Replace with blank space formatted to the type of spot
        if (origPos[1] == 'n') brdItr->second = "--"; // Normal spot
        else if (origPos[1] == 'g') { // safe zone (guarded)
            brdItr->second = "**";
        } else if (origPos[1] == 's') { // Slide
            if (origPos[0] == 'B') {
                if (origPos[2] == '0' || origPos[2] == '4') 
                    brdItr->second = "->"; // start
                else if (origPos[2] == '3' || origPos[2] == '8') 
                    brdItr->second = ">-"; // end
                else brdItr->second = ">>"; // middle
            } else if (origPos[0] == 'Y') {
                if (origPos[2] == '0' || origPos[2] == '4') 
                    brdItr->second = "-v"; // start
                else if (origPos[2] == '3' || origPos[2] == '8') 
                    brdItr->second = "v-"; // end
                else brdItr->second = "vv"; // middle
            } else if (origPos[0] == 'G') {
                if (origPos[2] == '0' || origPos[2] == '4') 
                    brdItr->second = "<-"; // start
                else if (origPos[2] == '3' || origPos[2] == '8') 
                    brdItr->second = "-<"; // end
                else brdItr->second = "<<"; // middle
            } else if (origPos[0] == 'R') {
                if (origPos[2] == '0' || origPos[2] == '4') 
                    brdItr->second = "^-"; // start
                else if (origPos[2] == '3' || origPos[2] == '8') 
                    brdItr->second = "-^"; // end
                else brdItr->second = "^^"; // middle
            }
        }
    }
}
bool Board::backwardMove(string pawn, string pos, bool realMove, int moveNum) {
    string newPos;
    string origPos = pos;
    string elimPawn;
    char newColor;
    int sldTpe;
    if (pawn.length() > 2) return false;
    if (pos.length() > 3) return false;
    if (pawn[1] != '1' && pawn[1] != '2' && pawn[1] != '3') return false;
    if (pawn[0] != 'B' && pawn[0] != 'R' && pawn[0] != 'G' && pawn[0] != 'Y')
        return false;
    if (pos[1] == 'h') return false; // home, cant be moved
    if (pos[1] == 'b') return false; // start, cant be moved backwards
    brdItr = brdInf.find(newPos);   
    for (int i=0; i<moveNum; i++) {
        if (pos[1] == 's') {
            if (pos[2] == '0' || pos[2] == '4') {
                newPos = pos[0]; // Same color
                newPos+= 'n'; // Transitions to normal
                newPos+= pos[2];
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else if (pos[2] == '1' || pos[2] == '5') {
                if (pos[0] != pawn[0]) {
                    newPos = pos[0]; // Same color
                    newPos+= 's';
                    newPos+= pos[2]-1;
                    if (i==moveNum-1) {
                        if (realMove) {
                            brdItr = brdInf.find(newPos);
                            if (pos[2] == '1') sldTpe = 4;
                            if (pos[2] == '5') sldTpe = 5;
                            for (int i=0; i<sldTpe; i++) { // Loop through the slide, removing pawns on it
                                cout << "SLIDE: " << brdItr->first << endl;
                                if (i==0) { // start of slides have unique appearance
                                    if (brdItr->second != "->" && brdItr->second != "-v" &&
                                        brdItr->second != "<-" && brdItr->second != "^-") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                            // Determine what color pawn was eliminated
                                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 

                                    }
                                } else if (i==sldTpe-1) {
                                    if (brdItr->second != ">-" && brdItr->second != "v-" &&
                                        brdItr->second != "-<" && brdItr->second != "-^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                            // Determine what color pawn was eliminated
                                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 

                                    }
                                    brdItr->second = pawn; // Set the pawn here
                                } else { // rest of slide
                                    if (brdItr->second != ">>" && brdItr->second != "vv" &&
                                        brdItr->second != "<<" && brdItr->second != "^^") { 
                                        elimPawn = brdItr->second;
                                        this->erasePos(brdItr->first, elimPawn);
                                            // Determine what color pawn was eliminated
                                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                                    }
                                }
                                brdItr++;
                            }    
                        }
                        if (pos[2] == '1') {
                            newPos = pos[0]; // Same color
                            newPos+= "s3";
                            cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                        } else if (pos[2] == '5') {
                            newPos = pos[0]; // Same color
                            newPos+= "s8";
                            cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                        }
                    }
                } else {
                    newPos = pos[0]; // Same color
                    newPos+= 's';
                    newPos+= pos[2]-1;
                    cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                    if (realMove) {
                        if (i==moveNum-1) { // If this is the end of a real move 
                            brdItr = brdInf.find(newPos);
                            if (brdItr->second != "--") { 
                                elimPawn = brdItr->second;
                                this->erasePos(brdItr->first, elimPawn);
                                // Determine what color pawn was eliminated
                                if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                                else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                                else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                                else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                            }
                            brdItr->second = pawn;
                            this->erasePos(origPos, pawn); // Take pawn off original spot
                        }
                    }
                } 
            } else {
                newPos = pos[0]; // Same color
                newPos+= 's'; // Transitions to normal
                newPos+= pos[2]-1;
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        } else if (pos[1] == 'n') {
            if (pos[2] == '0') {
                newColor = this->nextColor(pos[0]);
                newColor = this->nextColor(newColor);
                newColor = this->nextColor(newColor);
                newPos = newColor;
                newPos+= "n5"; // Transitions to normal
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else if (pos[2] == '1') {
                newPos = pos[0];
                newPos+= "s3";
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else if (pos[2] == '5') {
                newPos = pos[0];
                newPos+= "s8";
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else {
                newPos = pos[0];
                newPos+= 'n';
                newPos+= pos[2]-1;
                cout << newPos; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// debug
                if (realMove) {
                    if (i==moveNum-1) { // If this is the end of a real move 
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "--") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        } else if (pos[1] == 'g') {
            if (pos[2]=='0') {
                newPos = pos[0];
                newPos+= "s1";
                if (realMove) {
                    if (i==moveNum-1) {
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != ">>" && brdItr->second != "<<"
                         && brdItr->second != "vv" && brdItr->second != "^^") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            } else {
                newPos = pos[0];
                newPos = 'g';
                newPos+= pos[2]-1;
                if (realMove) {
                    if (i==moveNum-1) {
                        brdItr = brdInf.find(newPos);
                        if (brdItr->second != "**") { 
                            elimPawn = brdItr->second;
                            this->erasePos(brdItr->first, elimPawn);
                            // Determine what color pawn was eliminated
                            if (elimPawn[0] == 'B') bStart.insert(elimPawn);
                            else if (elimPawn[0] == 'Y') yStart.insert(elimPawn);
                            else if (elimPawn[0] == 'G') gStart.insert(elimPawn);
                            else if (elimPawn[0] == 'R') rStart.insert(elimPawn); 
                        }
                        brdItr->second = pawn;
                        this->erasePos(origPos, pawn); // Take pawn off original spot
                    }
                }
            }
        }
        pos = newPos;
    }
    return true;
}