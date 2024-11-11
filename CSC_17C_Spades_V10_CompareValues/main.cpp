/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 6, 2024, 8:58PM
 * In this program I will create a getter function that will return the value of
 * each player's card and return the value of the card. This is b/c in order to
 * get a book in the game of Spades, a team must have the highest value on the
 * table. So we must compare the values of the cards in order to see who has the
 * the highest value. The player hand with highest value card of that particular
 * round will then become the winner
 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Dealer.h"

//Global COnstants - Math/Physics/Chemistry/Conversions Only

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Set Random number seed
    srand(static_cast<int>(time(0)));
    
    //Declare Variables
    const short NCARDS=52;  //Number of cards
    int numHand = 13;       //Number of cards in each hand
    int pChoice;            //player choice
    string p1Name, p2Name, p3Name, p4Name; /*player1, player2, and player4
                                           * player 3 names*/

    //Prompt players to enter their names
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
    
    //Display player3's hand
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
    
    //Display Player 4's hand
    cout << player4.getName() << "'s hand\n";
    player4.printHnd();
    cout << endl;
    
    //Prompt Player4 to make a choice
    cout << player4.getName() << " choose a card\n";
    cin >>pChoice;
    
    //Set Player 4's value
    player4.setVal(pChoice);
    
    //Show Player 4's choice
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