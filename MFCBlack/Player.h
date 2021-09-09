#pragma once
#include "Person.h"
#include "Cards.h"
class Player :public Person
{
private:
	Card Your_cards[5];
	bool BlackJack_indicator = false;
	short total_value = 0;
public:
	Player();
	virtual ~Player();
    
	//const void CurrentCard(const short i);
	const void BlackJack(const bool T_or_F);
	const void setTV(const short v);
	const void setCard(const Card &drawn_card, const short i);
	const short GetCardValue(const short i) const;
	const bool getBlackJack() const;
	const short getTV() const;
	virtual const void getHelp(const short index);
};

