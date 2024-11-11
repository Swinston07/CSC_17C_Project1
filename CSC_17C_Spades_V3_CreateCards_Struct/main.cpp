/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 4, 2024, 9:47PM
 * 
 * This program is used to use Structures and functions to create the cards
 * I will be implementing an array of a card structure to store the values
 * of face, suits, and values of cards
 */

#include <iostream>

using namespace std;

//User Libraries
struct Card{
    char face;
    char suit;
    int val;
};

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
    Card cards[NCARDS];
    
    //Initialize inputs4
    
    for(int i = 0; i < NCARDS; i++){
        cards[i].face=getFace(i);
        cards[i].suit = getSuit(i);
        cards[i].val=getVal(i);
    }
    
    for(int i = 0; i < NCARDS; i++){
        cout << i+1 << " " << cards[i].face << " " << cards[i].suit << " " << cards[i].val
             << endl;
    }
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Exit stage right
    return 0;
}

int getVal(int n){
    n>=52?0:n;
    n%=13;
    n++;
    
    n=n>10?10:n;
    return n;
}

char getSuit(int n){
    n/=13;
    
    char suit[] = {'S', 'C', 'D', 'H'};
    return suit[n];
}

char getFace(int n){
    n%=13;
    char face[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'K', 'Q'};
    
    return face[n];
}