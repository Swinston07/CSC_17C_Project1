/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 4, 2024, 1:55PM
 * This program is used to create a set of cards for a spades game
 *simply using static arrays in the main functions
 */

#include <iostream>

using namespace std;

//User Libraries

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    
    //Declare Variables
    const short NCARDS=52;
    const short NUMFACE = 13;
    const short NUMSUIT = 4;
    const short NUMVAL = 10;
    char face[NUMFACE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'K', 'Q'};
    char suit[NUMSUIT] = {'S', 'C', 'D', 'H'};
    int val[NUMVAL] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //Initialize inputs4
    
    for(int i = 0; i < NCARDS; i++){
        cout << i+1 << " " << face[i%13] << " ";
        cout << suit[i/13] << " ";
        if(i%13>=10){
            cout << val[NUMVAL-1];
        }
        else{
            cout << val[i%13];
        }
        cout << " ";
        cout << endl;
    }
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Exit stage right
    return 0;
}