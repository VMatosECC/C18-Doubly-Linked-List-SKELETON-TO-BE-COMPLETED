#pragma once
#include "Node.h"
//--------------------------------------------------------------
//Doubly-Linked list (Using RAW pointers and GENERIC data Nodes)
//--------------------------------------------------------------
template <class T>
class DList
{
private:
public:
	// OBSERVATION: All data and function members are public for now!
	Node<T>* head;
	Node<T>* tail;
	int      size;

	//Constructor
	DList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	//Destructor
	~DList()
	{
		cout << this << " DList destructor called\n";
		//remove individual nodes
		Node<T>* p1 = head;
		while (p1 != nullptr)
		{
			Node<T>* p2 = p1->next;
			delete p1;
			p1 = p2;
		}
	}

	// ----------------------
	// Talk about yourself
	// ----------------------
	string toString()
	{
		ostringstream sout;
		sout << this << " DList [ Head: " << head << ", Tail: " << tail
			<< ", Size: " << size << "]\n";

		Node<T>* p = head;
		while (p != nullptr)
		{
			sout << "\t" << *p << endl;
			p = p->next;
		}
		return sout.str();
	}


	void insertInOrder(T newDataValue)
	{
		//********************************
		// HERE YOU ADD THE NEW FUNCTION
		// *******************************

		//is the list empty?
		if (head == nullptr)
		{
			insertLast(newDataValue);
			return;
		}

		//is new value larger than the last?
		if (tail->data <= newDataValue)
		{
			insertLast(newDataValue);
			return;
		}

		//is new value smaller than the first?
		if (head->data >= newDataValue)
		{
			Node<T>* newNode = new Node<T>(newDataValue);
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
			size++;
			return;
		}

		//find first value that is larger than the new data
		Node<T>* p = head;
		while (p != nullptr && newDataValue >= p->data)
		{
			p = p->next;
		}
		Node<T>* beforeNode = p->previous;
		Node<T>* newNode = new Node<T>(newDataValue);
		newNode->next = p;
		newNode->previous = beforeNode;
		beforeNode->next = newNode;
		p->previous = newNode;
		size++;

	}


	// ---------------------------------------------------------
	// Add new node holding newDataValue at the end of the list
	// ---------------------------------------------------------
	void insertLast(T newDataValue)
	{
		Node<T>* newNode = new Node<T>(newDataValue);

		//CASE1 - The list is empty
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			size++;
			return;
		}

		//CASE2 - We do have some nodes in the list
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
		size++;
		return;
	}

	// -----------------------------------
	// Find first node matching dataValue
	// -----------------------------------
	Node<T>* find(T dataValue)
	{
		Node<T>* p = head;
		while (p != nullptr)
		{
			if (p->data == dataValue) return p;
			p = p->next;
		}
		return nullptr;
	}

	//---------------------------------------------------
	// Insert a new node BEFORE the given ptr node 
	//---------------------------------------------------
	void insertBeforeGivenNode(Node<T>* ptr, T dataValue)
	{
		size++;
		Node<T>* newNode = new Node<T>(dataValue);

		//CASE1 - ptr is the first node in the list
		if (ptr == head)
		{
			newNode->next = head;
			ptr->previous = newNode;
			head = newNode;
			return;
		}

		//CASE2 – ptr is not the first node
		Node<T>* beforeNode = ptr->previous;
		newNode->previous = beforeNode;
		newNode->next = ptr;
		beforeNode->next = newNode;
		ptr->previous = newNode;

	}

	// ----------------------------------------------------
	// Remove from this list nodes included in otherList
	// ----------------------------------------------------
	void removeFromMeGivenNodes(DList<T>& otherList)
	{

		//remove from me nodes present in lst2
		Node<int>* p1 = head;
		while (p1 != nullptr)
		{
			int spy1 = p1->data, spyBefore = -1, spyAfter = -1;

			Node<T>* before = p1->previous;
			Node<T>* after = p1->next;
			if (before != nullptr) spyBefore = before->data;
			if (after != nullptr) spyAfter = after->data;

			Node<int>* p2 = otherList.find(p1->data);
			if (p2 != nullptr)
			{
				size--;

				//Case1 - is p1 the head of the list?
				if (head == p1)
				{
					head = after;
					after->previous = nullptr;
				}
				//Case2 - is p1 the tail of the list?
				else if (p1 == tail)
				{
					before->next = nullptr;
					tail = before;
				}
				else
					//Case3- p1 is an interior node
				{
					before->next = after;
					after->previous = before;
				}
				delete p1;
			}
			p1 = after;
		}

	}

};
