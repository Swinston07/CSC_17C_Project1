/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Player.h
 * Author: sterl
 *
 * Created on November 6, 2024, 5:57 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

#include "Hand.h"

class Player{
private:
    string name;
    Hand *hand;
public:
    Player(string);
    void setHand(Hand *);
    string getName(){return name;}
    void printHnd();
    void showChc(int);
};
#endif /* PLAYER_H */

