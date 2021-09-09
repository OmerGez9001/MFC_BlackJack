#include "stdafx.h"
#include "Cards.h"


Card::Card() {
	value = rand() % 13 + 1;
	suit = rand() % 4 + 1;
}

const void Card::set_Card() {
	value = rand() % 13 + 1;
	suit = rand() % 4 + 1;
}

const void Card::getCard() {
	cout << " ----" << endl << "|    |" << endl << "| ";

	if (value == 1) cout << 'A';
	else if (value == 10) cout << '0';
	else if (value == 11) cout << 'J';
	else if (value == 12) cout << 'Q';
	else if (value == 13) cout << 'K';
	else cout << value;

	if (suit == 1) cout << (char)3;
	else if (suit == 2) cout << (char)4;
	else if (suit == 3) cout << (char)5;
	else cout << (char)6;

	cout << " |" << endl << "|    |" << endl << " ---- " << endl;
}

const short Card::getSuit() const {
	return suit;
}

const short Card::getValue() const {
	return value;
}

Card::~Card() {

}

