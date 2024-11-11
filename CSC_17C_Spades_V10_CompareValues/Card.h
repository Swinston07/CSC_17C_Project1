/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Card.h
 * Author: sterl
 *
 * Created on November 4, 2024, 9:50 PM
 */

#ifndef CARD_H
#define CARD_H

class Card{
private:
    char face;      //Card Face
    char suit;      //Card Suit
    int val;        //Card Val
    short crdNum;   //Which card number are we on 0-51(52 Cards)
public:
    Card(int);
    char getFace();
    char getSuit();
    int getVal();
};
#endif /* CARD_H */