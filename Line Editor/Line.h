/*
*LineList.cpp
*
*Author: Misbahuddin Adil Syed
*/
#ifndef LINE_H_
#define LINE_H_


#include<cstring>
#include<stdio.h>
#include<iostream>
#include<ostream>
using namespace std;
class Line
{
private:
	char * linePtr;
	int lineLength;
	int capacity;
public:
	Line();
	Line(const char *text);//constructor
	Line(const Line&);//copy constructor
	const Line& operator=(const Line& rhs);//assignment operator
	virtual ~Line();//destructor
	const char* cstr() const;// to cstring
	int length() const;// return length of line;
	bool empty() const;
	bool full() const;
	int getCapacity() const;
	void resize();
	void push_back(char & ch);
	void pop_back();
	friend ostream& operator<< (ostream& out, const Line& line);
	friend istream& operator>> (istream& in, Line& line);
	friend bool operator!=(const Line &l1, const Line &l2);
	friend bool operator == (const Line &l1, const Line &l2);
};
#endif // !LINE_H_