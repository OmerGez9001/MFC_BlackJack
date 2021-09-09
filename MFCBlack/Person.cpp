#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}
const void Person::setName(const CString NAME) {
	this->name = NAME;
}
const CString Person::getName() const {
	return this->name;
}
Person::~Person()
{
}

