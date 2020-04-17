//Filename: cards.h
//Authors: Chen Li

// FILE: stats.h
// Written by: Michael Main (main@colorado.edu)
// CLASS PROVIDED: Player
//   (a class to keep card player's name and cards in hand and some 
//		opeartions)
//
// CONSTRUCTOR 
//  Player(string name);
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of cards. 
//
// PUBLIC MODIFICATION member functions for the Player class:
//	int search(card* c1);
//		postcondition: return the position of c1 and remove the card if exit, return 0  otherwise
//	void insert(char s, char n);
//		Insert one card to the end of player's cards.
//	void removeCard(int n);
//		delete the card at position n;
//	void compare(card* ptr, Player);
//		compare ptr to all the cards in player p's hand. If any is the same
//		print to terminal and delete both cards.

//   
// PUBLIC CONSTANT member functions for the Player class:
//	string Name() const;
//		return the name of player
//	card* first() const;
//		return the pointer to the first card in hand
//
//
// NON-MEMBER functions for the Player class:
//	ostream& operator<<(ostream& out, const Player& p);
//		print the card in player p's hand.

// CLASS PROVIDED: Player
//   (a class to keep card player's name and cards in hand and some 
//		opeartions)
//
// CONSTRUCTOR 
//	card(char s, char n);
//		create a card with suit s and number n;
//   
// PUBLIC CONSTANT member functions for the Player class:
//	char getS() const; return suit;
//		
//	char getN() const; return number;
//
// NON-MEMBER functions for the Player class:
//	friend bool operator==(const card& c1, const card& c2);
//		return true in c1 and c2 have the same suit and number, false otherwise



#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

class card{
private:
	char suit;
	char num;

public:
	card* next;
	card(char s, char n);
	char getS() const;
	char getN() const;
	//void setS(char s);
	//void setN(char n);
	friend bool operator==(const card& c1, const card& c2);
};


/*
class Cardlist{
public:
	card* head;
	Cardlist();
	~Cardlist();
};
*/

class Player{
private:
	string name;
	card* head;
	int len;

public:
	Player(string playername);
	~Player();
	int search(card* c1);
	bool Myturn(Player& p2);
	void insert(card c);
	void removeCard(int n);
	friend ostream& operator<<(ostream& out, const Player& p);
};

#endif
