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

#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "Hand.h"

class Player{
private:
    string name;                //Player's name
    Hand *hand;                 //Player's hand
    int value;                  //Value of the card
    char suit;                  //Suit of the card
    char face;                  //Face of the card
    list<char> playFace;        //We will use this list of faces to play the game
    list<char> playSuit;        //We will use this list of faces to play the game
    list<int>  playVal;         //We will use this list of values to play the game
    list<char>::iterator it;    //Iterator for list
    int nCards = 13;            //Number of cards in Player's hand
    
public:
    Player(string);
    void setHand(Hand *);
    string getName(){return name;}
    void printHnd();
    void showChc(int);  //Show the choice of the card the player chose
    void setVal(int);   //Set the value of the card the player chose
    void setSuit(int);  //Set the suit of the card the player chose
    void setFace(int);
    int getVal();       //return the value of the card the player chose
    char getSuit();     //return the suit of the card the player chose
    char getFace();
    void setPlay();     /*Set the list of faces, suits, and values
                         *to use for the game*/
};
#endif /* PLAYER_H */