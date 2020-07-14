/*
*Line.cpp
*
*Author: Misbahuddin Adil Syed
*/

#include "Line.h"
#include<iostream>
#include<cstring>
using namespace std;
Line::Line()
{
	linePtr = nullptr;
	lineLength = 0;
	capacity = 0;
}
Line::Line(const char *text)
{
	lineLength = strlen(text);
	linePtr = new char[lineLength + 1];
	capacity = lineLength + 1;
	//strcpy(linePtr, text);
	for (int i = 0; i < lineLength; i++)
	{
		linePtr[i] = text[i];

	}
	linePtr[lineLength] = '\0';
//	cout << linePtr << "-" << lineLength;

}
Line::Line(const Line& line)
{
	lineLength = line.lineLength;
	capacity = line.capacity;
	linePtr = new char[capacity];
	for (int i = 0; i < lineLength; i++)
	{
		linePtr[i] = line.linePtr[i];

	}
	linePtr[lineLength] = '\0';
//	cout << "copy" << linePtr << "-" << lineLength;
}
const Line& Line::operator=(const Line& rhs)
{
	//cout << rhs.cstr() << rhs.capacity << rhs.lineLength<<"assign";
	lineLength = rhs.lineLength;
	capacity = rhs.capacity;
	linePtr = new char[capacity];
	for (int i = 0; i < lineLength; i++)
	{
		linePtr[i] = rhs.linePtr[i];
//		cout << linePtr[i] << i;
	}
//	cout << lineLength << capacity << rhs.lineLength << rhs.capacity;
	linePtr[lineLength] = '\0';
//	cout << "assign" << linePtr << "-" << lineLength;
	return *this;
}

const char* Line::cstr() const
{
	char * cstr1 = new char[lineLength];
	for (int i = 0; i < lineLength; i++)
	{
		cstr1[i] = linePtr[i];
	}
	cstr1[lineLength] = '\0';
///	cout << "cstr" << cstr1;
	return cstr1;
}

int Line::length() const
{
	return lineLength;
}

bool Line::empty() const
{
	return lineLength == 0;
}

bool Line::full() const
{
	return lineLength == capacity;
}
int Line::getCapacity() const
{
	return capacity;
}
void Line::resize()
{
	if (lineLength == capacity)
	{
		linePtr = new char[2 * capacity];
	}
}
void Line::push_back(char &ch)
{
	if (lineLength == capacity)
	{
		resize();
	}
	linePtr[lineLength] = ch;
	linePtr[lineLength + 1] = '\0';
	lineLength++;
//	cout << "push" << linePtr << "-" << lineLength;
}


void Line::pop_back()
{
	linePtr[lineLength - 1] = '\0';
	lineLength--;
//	cout << linePtr << "-" << lineLength;
}

ostream& operator<<(ostream& out, const Line& line)
{
	out << "Line(" << line.linePtr << "," << line.lineLength << "," << line.capacity << ")";
	return out;
}

istream& operator>>(istream& in, Line& line)
{
	char * temp = new char[100];
	in >> temp;
	line.lineLength = strlen(temp);
	line.capacity = line.lineLength;
	line.linePtr = new char[line.capacity + 1];
	for (int i = 0; i < line.lineLength; i++)
	{
		line.linePtr[i] = temp[i];

	}
	line.linePtr[line.lineLength] = '\0';
//	cout << "<<" << line.linePtr << "-" << line.lineLength;
	return in;
}
Line::~Line()
{
	delete[] linePtr;
}
bool operator == (const Line &l1, const Line &l2)
{
	int res = strcmp(l1.cstr(), l2.cstr());
	if (res == 0)
	{
		return true;
	}
	return false;
}
bool operator != (const Line &l1, const Line &l2)
{
	int res = strcmp(l1.cstr(), l2.cstr());
	if (res == 0)
	{
		return false;
	}
	return true;
}