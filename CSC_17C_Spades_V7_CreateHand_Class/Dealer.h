/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Dealer.h
 * Author: sterl
 *
 * Created on November 6, 2024, 5:55 PM
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Deck.h"

class Dealer:public Player{
    protected:
        Deck *deck;
        int nDeal;
    public:
        Dealer(string name, int nCards, int nDeal):Player(name){
            deck = new Deck(nCards);
            this->nDeal = nDeal;
        }
        ~Dealer(){
            delete deck;
        }
        Hand *deal(){
            Hand *hand = new Hand(deck->deal(nDeal), nDeal);
            return hand;
        }
        void display(){
            deck->display();
        }
        void shuffle(){
            deck->shuffle();
        }
};
#endif /* DEALER_H */

