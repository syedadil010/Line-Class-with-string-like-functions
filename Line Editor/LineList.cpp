/*
*LineList.cpp
*
*Author: Misbahuddin Adil Syed
*/

#include"LineList.h"
#include"Line.h"
LineList::LineList()
{
	theSize = 0;
	head = NULL;
	tail = NULL;
}

LineList::LineList(const LineList& rhs)
{
	if (rhs.head == NULL || rhs.theSize==0)
	{
		head = NULL;
		tail = NULL;
		theSize = 0;
	}
	else
	{
		theSize = rhs.theSize;
		head = rhs.head;
		tail = rhs.tail;
	}
}

LineList::Node::Node()
{
	this->data = NULL;
	this->next = NULL;
	this->prev = NULL;
}

LineList::Node::Node(const Line& ln, Node *prv, Node *nxt)
{
	this->data = ln;
	this->prev = prv;
	this->next = nxt;
}

LineList::~LineList()
{
	delete head;
	delete tail;
}

const LineList& LineList::operator=(const LineList& linel)
{
	theSize=linel.theSize;
	head=linel.head;
	tail=linel.tail;
	return *this;
	
}

void LineList::push_front(const Line& line)
{
	if (size() == 0)
	{
		Node *t1 = new Node(line, NULL, NULL);
		head = t1;
		tail = t1;
		theSize++;
	}
	else
	{
		//cout << line.cstr()<<"line";
		Node *t2 = new Node(line, NULL, head);
		Node *th = head;
		th->prev = t2;
		head = t2;
		theSize++;
	}
}

void LineList::push_back(const Line& line)
{
	if (theSize == 0)
	{
		Node *t1 = new Node(line, NULL, NULL);
		head = t1;
		tail = t1;
		theSize++;
	}
	else
	{
		Node *t2 = new Node(line, tail, NULL);
		tail->next = t2;
		tail = t2;
		theSize++;
	}
}
void LineList::pop_front()
{
	if (head == NULL || theSize == 0)
	{
		//cout << "Empty List";
	}
	else if(theSize==1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		theSize--;
		// << "deleted";
	}
	else
	{
		Node *t = head->next;
		delete head;
		head = t;
		theSize--;
	//	cout << "deleted";
	}
}
void LineList::pop_back()
{
	if (theSize == 0)
	{
	//	cout << "empty list";
	}
	else if (theSize == 1)
	{
		delete tail;
		head = NULL;
		tail = NULL;
		theSize--;
	//	cout << "deleted";
	}
	else
	{
		Node *t = tail->prev;
		delete tail;
		tail = t;
		tail->next = NULL;
		theSize--;
//		cout << "deleted";
	}
}
int LineList::size() const
{
	return theSize;
}
const bool LineList::empty()
{
	return theSize == 0;
}
void LineList::insert(const Line& line, int k)
{
	k = k - 1;
	if (k == 0)
	{
		push_front(line);
		//cout << "added to 0th position";
	}
	else if (k == theSize)
	{
		push_back(line);
		//cout<< "added to last position";
	}
	else
	{
		Node *current = head;
		int pos = 0;
		while (k != pos)
		{
			pos++;
			current = current->next;
			if (k == pos)
			{
				
				Node *t = new Node(line, current->prev, current);
				current->prev->next=t;
				current->prev = t;
				theSize++;
				return;
			}
		}
	}
}
void LineList::remove(int k)
{
	if (k == 0)
	{
		pop_front();
		//cout << "removed from 0th position";
	}
	else if (k == theSize)
	{
		pop_back();
		//cout << "removed from last position";
	}
	else
	{
		Node *current = head;
		int pos = 0;
		while (pos!=theSize)
		{
			pos++;
			current = current->next;
			if (k == pos)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
				theSize--;
				return;
			}
		}
	}
}

Line LineList::get(int k) const
{
	k = k - 1;
	Node *current = head;
	int pos = 0;
	while (pos!=theSize+1)
	{
		
		if (k== pos)
		{
			//cout << current->data.cstr()<<"in get"<<current->prev->data;
			Line n1(current->data);
			return n1;
		}
		pos++;
		current = current->next;
	}
}
void LineList::print()
{
	int count=0;
	Node *current = head;
	while (theSize!=count)
	{
		count++;
		cout << "(" << count << ")\t" << current->data.cstr()<<"\n";
		current = current->next;
	}
	cout << "\n";
}
