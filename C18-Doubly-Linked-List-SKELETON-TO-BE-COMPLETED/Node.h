#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Generic doubly-linked node
template <class T>
class Node
{
private:
public:
	Node* previous;
	Node* next;
	T     data;

	Node(T dataValue = {})
	{
		data = dataValue;
		next = nullptr;
		previous = nullptr;
	}

	~Node()
	{
		cout << this << "(" << this->data << ") Node destructor called\n";
	}

	string toString()
	{
		ostringstream sout;
		sout << this << " Node [ previous: " << previous
			<< ", next: " << next
			<< ", Data: " << data
			<< "]";
		return sout.str();
	}

	friend ostream& operator<< (ostream& sout, Node& n)
	{
		sout << n.toString();
		return sout;
	}
};


