#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person
{
	CString name = NULL;
public:
	Person();
	virtual ~Person();
	const void setName(const CString NAME);
	const CString getName() const;
};

