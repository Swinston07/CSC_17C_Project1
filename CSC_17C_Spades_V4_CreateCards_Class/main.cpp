/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 4, 2024, 10:15PM
 * 
 * This program is going to use classes as well as access and getter functions 
 * to create the cards. I will be using a constructor and passing in two integer
 * values used to initialize all of the values of each card(face, suit, val) as
 * well as the number of cards
 */

#include <iostream>

using namespace std;

//User Libraries
#include "Card.h"

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes
char getFace(int);
char getSuit(int);
int getVal(int);

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    const short NCARDS=52;
    
    //Initialize inputs4
    
    for(int i = 0; i < NCARDS; i++){
        Card card(i);
        
        cout << i+1 << " " << card.getFace() << " " << card.getSuit() << " "
             << card.getVal() << endl;
    }
    cout << endl;
    
    //Map inputs to Outputs - Process

    //Display output
    
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
