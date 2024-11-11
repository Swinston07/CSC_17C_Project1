/* 
 * File:   main.cpp
 * Author: Sterling Winston
 *
 * Created on November 6, 2024, 3:00PM
 * In This Program I will create a Dealer class that uses an aggregate of the
 * deck class in order to deal to the players. I will also use polymorphism
 * but inheriting the player class in the dealer class as well, allowing the
 * dealer to act as a player in the game. In this program, the only functionality
 * is that the dealer will deal himself and another player a hand of 13 cards.
 * Each player will then be able to choose a card
 */

#include <iostream>
#include <ctime>

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
    //Card **deck;          //Deck of cards
    //Deck deck(NCARDS);
    Dealer dealer("Sterling", NCARDS, numHand);
    
    //Initialize inputs4  
    dealer.display();
    dealer.shuffle();
    cout << endl;
    dealer.display();
    cout << endl;
    
    //Set dealer hand
    dealer.setHand(dealer.deal());        
    
    //Display dealer hand
    cout << "Dealer hand" << endl;
    dealer.printHnd();
    cout << endl;
    
    //Prompt Dealer to make a choice
    cout << dealer.getName() << " choose a card" << endl;
    cin >> pChoice;
    
    //Display the dealer's choice
    cout << dealer.getName() << " chose:\n";
    dealer.showChc(pChoice);
    cout << endl;
    
    Player player1("Mak");
    
    //Set player1 hand
    player1.setHand(dealer.deal());
    
    //Display player1 hand
    cout << "Player1 hand\n";
    player1.printHnd();
    
    //Prompt Player1 to make a choice
    cout << player1.getName() << " choose a card\n";
    cin >> pChoice;
    
    cout << player1.getName() << " chose:\n";
    player1.showChc(pChoice);
    cout << endl;
    
    //Map inputs to Outputs - Process

    //Display output
    
    //Delete allocated memory

    //Exit stage right
    return 0;
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

//void Deck::dispHnd(int *h){
//    for(int i = 0; i < nDeals; i++){
//        cout << h[i] << " " << card[h[i]]->getFace()
//             << card[h[i]]->getSuit() << " " << card[h[i]]->getVal() << endl;
//    }
//}

int* Deck::deal(int n){
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