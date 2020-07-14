/*
*LineList.cpp
*
*Author: Misbahuddin Adil Syed
*/
#ifndef LINELIST_H_
#define LINELIST_H_
#include"Line.h"

class LineList
{
private:
	int theSize;
	class Node
	{
		public:
			Line data;
			Node *prev;
			Node *next;
			Node();
			Node(const Line& ln, Node *prv, Node *nxt);
	};
	Node *head;
	Node *tail;
public:

	LineList();//constructor
	virtual ~LineList();//destructor
	LineList(const LineList& rhs);//copy constructor
	const LineList& operator=(const LineList& linel);//assignment operator
	void push_front(const Line& line);//push element in front of list
	void push_back(const Line& line);//push element in back of list
	void pop_front();//remove element in front of list
	void pop_back();//remove element in back of list
	int size() const;//return size
	const bool empty();//check if empty
	void insert(const Line& line, int k);//insert at position k
	void remove(int k);//remove at position k
	Line get(int k) const;//get Line at position k
	void print();//print list
};

#endif // !LINELIST_H_