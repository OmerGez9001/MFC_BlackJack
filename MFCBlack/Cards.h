#pragma once
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Card
{
private:
	short suit;
	short value;
public:
	Card();
	~Card();

	const void set_Card(); //to make a difference between this func and players func
	const void getCard();
	const short getValue() const;
	const short getSuit() const;
};

