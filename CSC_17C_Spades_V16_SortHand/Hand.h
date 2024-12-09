/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Hand.h
 * Author: sterl
 *
 * Created on November 6, 2024, 10:57 AM
 */

#ifndef HAND_H
#define HAND_H
#include <list>

class Hand{
private:
    int nCards; //Number of cards that are in the player's hand
    int *cards; //indexes of the cards that are in the player's hand
    Card **hand; //actual cards in the players hand
    list<Card> listHand;
    list<Card>::iterator choice;
    
public:
    Hand(int*, int);
    ~Hand(){
        for(int i = 0; i < nCards ; i++){
            delete [] hand[i];
        }
        delete [] hand;
        delete [] cards;
    }
    void dispHand();
    void dispChc(int);
    void remvChc(int);
    int getVal(int);
    char getSuit(int);
    void sortHnd();
};
#endif /* HAND_H */