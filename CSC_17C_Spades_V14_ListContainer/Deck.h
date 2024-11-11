/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: sterl
 *
 * Created on November 5, 2024, 11:28 PM
 */

#ifndef DECK_H
#define DECK_H

class Deck{
private:
    short nCards;   //Number of cards in deck
    short cardNum;  //Card number in deck
    Card **card;    //Card in deck
    int *index;     //index of cards
    int nShfls;     //number of shuffles
    int nDeals;
    int hand;
    //list <Card> cards;  //List of cards
public:
    Deck(short);
    ~Deck(){
        for(int i = 0; i < nCards; i++){
            delete [] card[i];
        }
        delete [] card;
        delete [] index;
    }
    void shuffle();
    void display();
    int *deal(int);
    void dispHnd(int *);
};
#endif /* DECK_H */