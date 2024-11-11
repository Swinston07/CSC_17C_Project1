/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 7, 2024, 12:02PM
 * This program is just setting all the cards to the correct values.
 * For the game of spades the highest face card other than joker for each suit
 * is the ACE. This program sets all face cards to their respective values from
 * 2-ACE. 2 having the least value, ACE having the highest
 */

#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Dealer.h"

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes
void rules();

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    const short NCARDS=52;                  //Number of cards
    int numHand = 13;                       //Number of cards in each hand
    int pChoice;                            //player choice
    string p1Name, p2Name, p3Name, p4Name;  /*player1, player2, and player4
                                            * player 3 names*/

    //Prompt players to enter their names
    rules();
    
    cout << "Player 1 enter your name: ";
    getline(cin, p1Name);
    
    cout << "Player 2 enter your name: ";
    getline(cin, p2Name);
    
    cout << "Player 3 enter your name: ";
    getline(cin, p3Name);
    
    cout << "Player 4 enter your name: ";
    getline(cin, p4Name);
    
    cout << endl;
    
    Dealer player1(p1Name, NCARDS, numHand);
    Player player2(p2Name);
    Player player3(p3Name);
    Player player4(p4Name);
    
    //Show deck before and after shuffling
    player1.display();
    player1.shuffle();
    cout<<endl;
    player1.display();
    
    //Set Players' hands
    player1.setHand(player1.deal());   
    player2.setHand(player1.deal());
    player3.setHand(player1.deal());
    player4.setHand(player1.deal());
    cout << endl;
    
    //Display Player 1 hand
    cout << player1.getName() << "'s hand" << endl;
    player1.printHnd();
    cout << endl;
    
    //Prompt Player 1 to make a choice
    cout << player1.getName() << " choose a card" << endl;
    cin >> pChoice;
    
    //Set Player 1's card Value
    player1.setVal(pChoice);
    
    //Display the player1's choice
    cout << player1.getName() << " chose:\n";
    player1.showChc(pChoice);
    cout << endl;
    
    //Display player2's hand
    cout << player2.getName() <<"'s hand\n";
    player2.printHnd();
    cout << endl;
    
    //Prompt Player2's to make a choice
    cout << player2.getName() << " choose a card\n";
    cin >> pChoice;
    
    //Set player2's value
    player2.setVal(pChoice);
    
    //Show player2's choice
    cout << player2.getName() << " chose:\n";
    player2.showChc(pChoice);
    cout << endl;
    
//    //Display player3's hand
    cout << player3.getName() << "'s hand\n";
    player3.printHnd();
    cout << endl;
    
    //Prompt Player 3 to make a choice
    cout << player3.getName() << " choose a card\n";
    cin >> pChoice;
    
    //Set Player 3's value
    player3.setVal(pChoice);
    
    //Show Player3's choice
    cout << player3.getName() << " chose:\n";
    player3.showChc(pChoice);
    cout << endl;
    
//    //Display Player 4's hand
    cout << player4.getName() << "'s hand\n";
    player4.printHnd();
    cout << endl;
    
//    //Prompt Player4 to make a choice
    cout << player4.getName() << " choose a card\n";
    cin >>pChoice;
    
    //Set Player 4's value
    player4.setVal(pChoice);
    
//    //Show Player 4's choice
    cout << player4.getName() << " chose:\n";
    player4.showChc(pChoice);
    cout << endl;
    
    if(player1.getVal() > player2.getVal() && player1.getVal() > player3.getVal()
       && player1.getVal() > player4.getVal()){
        cout << player1.getName() << " win's book\n";
    }
    else if(player2.getVal() > player1.getVal() && player2.getVal() > player3.getVal()
            && player2.getVal() > player4.getVal()){
        cout << player2.getName() << " win's book\n";
    }
    else if(player3.getVal() > player1.getVal() && player3.getVal() > player2.getVal()
            && player3.getVal() > player4.getVal()){
        cout << player3.getName() << " win's book\n";
    }
    else{
        cout << player4.getName() << " win's book\n";
    }
        
    //Map inputs to Outputs - Process

    //Display output
    
    //Delete allocated memory

    //Exit stage right
    return 0;
}

void rules(){
    cout << "SPADES\n";
    cout << "- The game of spades is a four player card game that utilizes two"
            " teams of two player each\n";
    cout << "- Each team will have a hand of 13 cards\n";
    cout << "- The player who is sitting to the left of the current dealer plays"
            " his/her card first\n";
    cout << "- The opening move at the start of each set CANNOT be a spade UNLESS"
            " somebody has 'cut' another player earlier in the set(will be"
            " discussed more later\n";
    cout <<"- Each player must match the suit of the opening move UNLESS the"
            " player does not have a card matching the suit. Thus the player can"
            " then 'cut' by using another suit. Once a player has cut, any player"
            " can now use a spade as an opening move\n";
    cout << "- Each card will contain a value based on the face\n";
    cout << "- The value of each card will be in order from 2-ACE, 2 being the"
            " lowest value, and ACE being the highest\n";
    cout << "- There are also two joker cards. A high and low joker. Nothing can"
            " beat a high joker and only a high joker can beat the low joker."
            " High and low jokers are considered 'spades'. \n";
    cout << "- Any spade card has more value than any other suit. For example"
            " if somebody plays ane ACE of Hearts, then another plays a 2 of"
            " Spades, the 2 of Spades will have more value\n";
    cout << "- Once each player has played all of their cards, each team will"
            " observe their books and see if they met their bid\n";
    cout << "- If the team has met their bid or higher, they receive a point"
            " total of 10 multiplied by their bid number\n";
    cout << "= If a team doesn't meet their bid, they will lose the number of"
            " they would have gained had they made their bid\n";
    cout << "= The first team to a point total of 150 points wins\n\n";
}

int Player::getVal(){
    return value;
}

void Player::setVal(int n){
    value = hand->getVal(n);
}

void Player::showChc(int n){
    hand->dispChc(n);
}

void Player::printHnd(){
    hand->dispHand();
}

void Player::setHand(Hand* h){
    hand = h;
}

Player::Player(string name){
    this->name = name;
}

int Hand::getVal(int n){
    return hand[n]->getVal();
}

void Hand::dispChc(int n){
    cout << hand[n]->getFace() << hand[n]->getSuit() << " "
         << hand[n]->getVal() << endl;
}

void Hand::dispHand(){
    for(int i = 0; i < nCards; i++){
        cout << i << " " << hand[i]->getFace() << hand[i]->getSuit()
             << " " << hand[i]->getVal() << endl;
    }
}

Hand::Hand(int *cards, int nCards){
    this->cards = cards;
    this->nCards = nCards;
    hand = new Card*[nCards];
    
    for(int i = 0; i < nCards; i++){
        hand[i] = new Card(cards[i]);
    }
}

int* Deck::deal(int n){
    int *hand = new int[n];
    
    for(int i = 0; i < n; i++){
        hand[i] = index[nDeals++];
    }
    
    //nDeals=(nDeals==52)?0:nDeals;
    
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
    
    //Set the ACE card for all suits to the highest value
    n=(n==0)?13:n;
    n++;
    
    //n=n>10?10:n; 
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