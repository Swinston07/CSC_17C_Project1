/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 4, 2024, 10:39PM
 * In This Program I will create a Deck in the main function by utilizing a
 * two-dimensional dynamic card Array to create the deck of cards in the main
 * function
 */

#include <iostream>

using namespace std;

//User Libraries
#include "Card.h"

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    const short NCARDS=52;  //Number of cards
    Card **deck;            //Deck of cards
    
    //Initialize inputs4
    deck = new Card*[NCARDS];
    
    for(int i = 0; i < NCARDS; i++){
        deck[i] = new Card(i);
        
        cout << i+1 << " " << deck[i]->getFace() << " " << deck[i]->getSuit() << " "
             << deck[i]->getVal() << endl;
    }
    cout << endl;
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Delete allocated memory
    for(int i = 0; i < NCARDS; i++){
        delete [] deck[i];
    }
    
    delete [] deck;
    
    //Exit stage right
    return 0;
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
    char face[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'K', 'Q'};
    
    return face[n];
}

Card::Card(int n){
    crdNum = n;
}
