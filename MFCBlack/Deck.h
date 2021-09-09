#pragma once
#include "Cards.h"
class Deck
{
private:
	Card cards[52];
	int numDrawn;
public:
	Deck();
	~Deck();

	const Card draw();
	const bool cardInDeck(Card &card, int index);
};

