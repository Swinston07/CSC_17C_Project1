/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 6, 2024, 10:55AM
 * In This Program I will create a Hand class and initialize the hand using a
 * constructor. I will also implement a shuffle function in order to shuffle the 
 * cards as well. The program also uses the Deck class in order to deal a hand
 * as well display the hand it dealt to each individual player.
 */

#include <iostream>
#include <ctime>

using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    const short NCARDS=52;  //Number of cards
    //Card **deck;            //Deck of cards
    Deck deck(NCARDS);
    
    //Initialize inputs4    
    deck.display();
    deck.shuffle();
    cout << endl;
    deck.display();
    int *hand = deck.deal(13);
    cout << endl;
    cout << "Hand\n";
    deck.dispHnd(hand);
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Delete allocated memory

    //Exit stage right
    return 0;
}
void Deck::dispHnd(int *h){
    for(int i = 0; i < nDeals; i++){
        cout << h[i] << " " << card[h[i]]->getFace()
             << card[h[i]]->getSuit() << " " << card[h[i]]->getVal() << endl;
    }
}

int* Deck::deal(int n){
    nDeals = 0;
    int *hand = new int[n];
    for(int i = 0; i < n; i++){
        hand[i] = index[nDeals++];
    }
    return hand;
}

void Deck::display(){
    for(int i = 0; i < nCards; i++){
        cout << index[i] << " " << card[index[i]]->getFace() << card[index[i]]->getSuit() << " "
             << card[index[i]]->getVal() << endl;
    }
}

void Deck::shuffle(){
    for(int i = 0; i < nShfls; i++){
        for(int j = 0; j < nCards; j++){
            int temp = rand()%nCards;
            int crd = index[j];
            index[j] = index[temp];
            index[temp] = crd;
        }
    }
}

Deck::Deck(short nCards){
    this->nCards = nCards;
    this->cardNum = cardNum;
    card = new Card*[nCards];
    index = new int[this->nCards];
    nShfls = 7;
    
    for(int i = 0; i < this->nCards; i++){
        card[i] = new Card(i);
        index[i] = i;
    }
}

int Card::getVal(){
    short n = crdNum;
    
    n=n>=52?0:n;
    n%=13;
    
    n++;
    
    n=n>10?10:n;
    
    return n;
}

char Card::getSuit(){
    short n = crdNum;
    
    n/=13;
    
    char suit[] = {'S', 'C', 'D', 'H'};
    return suit[n];
}

char Card::getFace(){
    short n = crdNum;
    n%=13;
    char face[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    
    return face[n];
}

Card::Card(int n){
    crdNum = n;
}