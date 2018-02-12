#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <cassert>
#include <string>

#include "Entry.h"

using namespace std;

class List;
class Iterator;

class Node
{
public:
	Node(Entry s);
private:
	Entry data;
	Node* previous;
	Node* next;

	friend class List;
	friend class Iterator;
};

class List
{
public:
	/**
	   Constructs an empty list;
	*/
	List();
	/**
	   Appends an element to the list.
	   @param s the value to append
	*/
	List(const List& right);
	~List();
	List& operator=(const List& right);

	void push_back(Entry s);
	void push_front(Entry s);
	void insert(Iterator iter, Entry s);
	Iterator erase(Iterator i);
	Iterator begin() const;
	Iterator end() const;

	bool empty() const;
	int size() const;
private:
	Node* first;
	Node* last;
};

class Iterator
{
public:
	/**
	   Constructs an iterator that does not point into any list.
	*/
	Iterator();
	Entry get() const;
	void next();
	void previous();

	bool equals(Iterator b) const;
	Iterator& operator++(int);
	Iterator& operator--(int);
	Entry operator*() const;
	Entry& operator*();
	Entry* operator->();
	bool operator==(const Iterator& b) const;
	bool operator!=(const Iterator& b) const;
private:
	Node* position;
	Node* last;
	friend class List;
};

#endif
