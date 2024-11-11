/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 4, 2024, 2:30PM
 * This program is used to use functions in order to crate a deck of cards
 */

#include <iostream>

using namespace std;

//User Libraries

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
    const short NUMFACE = 13;
    const short NUMSUIT = 4;
    const short NUMVAL = 10;
    
    //Initialize inputs4
    
    for(int i = 0; i < NCARDS; i++){
        cout << i+1 << " " << getFace(i) << " " << getSuit(i) << " " << getVal(i)
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