#include "stdafx.h"
#include "Deck.h"

Deck::Deck() {
	Card card;
	bool match = false;
	for (int i = 0; i < 51; i++) {
		do {
			card.set_Card();
			match = cardInDeck(card, i);
		} while (match == true);
		match = false;
		cards[i] = card;
	}
	numDrawn = 0;
}
const bool Deck::cardInDeck(Card &card, int index) {
	bool match = false;
	for (int i = 0; i <= index; i++) {
		if ((card.getValue() == cards[i].getValue()) && (card.getSuit() == cards[i].getSuit())) {
			match = true;
			break;
		}
		else match = false;
	}
	return match;
}
const Card Deck::draw() {
	short temp = numDrawn;
	numDrawn++;
	return cards[temp];
}
Deck::~Deck() {

}
