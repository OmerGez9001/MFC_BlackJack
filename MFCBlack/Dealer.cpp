#include "stdafx.h"
#include "Dealer.h"

Dealer::Dealer()
{
}
Card Dealer::Action_draw() {
	return D.draw();
}
const void Dealer::getHelp(const short index) {
	setTV(0);
	for (short i = 0; i < index; i++) {
		setCard(Action_draw(), i);
		setTV(getTV() + GetCardValue(i));
	}
	if (getTV() > 21) setTV(0);
}
Dealer::~Dealer()
{
}

