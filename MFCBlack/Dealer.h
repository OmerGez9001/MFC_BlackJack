#pragma once
#include "Player.h"
#include "Deck.h"

class Dealer :public Player
{
private:
	Deck D;
public:
	Dealer();
	virtual ~Dealer();
	const void getHelp(const short index);
	Card Action_draw();
};

