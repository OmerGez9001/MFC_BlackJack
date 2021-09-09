#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}
const void Player::setCard(const Card &drawn_card, const short i) {
	this->Your_cards[i] = drawn_card;
}
const short Player::GetCardValue(const short i) const {
	return this->Your_cards[i].getValue();
}
const void Player::BlackJack(const bool T_or_F) {
	this->BlackJack_indicator = T_or_F;
}
const void Player::setTV(const short v) {
	this->total_value = v;
}
const short Player::getTV() const {
	return this->total_value;
}

const bool Player::getBlackJack() const {
	return BlackJack_indicator;
}
const void Player::getHelp(const short index) {
	total_value -= Your_cards[index].getValue();
}

//const void Player::CurrentCard(const short i) {
//	this->Your_cards[i].getCard();
//}
Player::~Player()
{
}

