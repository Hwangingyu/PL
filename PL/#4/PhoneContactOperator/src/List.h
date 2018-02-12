#ifndef MYLIST_H
#define MYLIST_H

//#include <string>
#include "String.h"
#include <iostream>
#include <cassert>
#include "Entry.h"

using namespace std;


class List;
class Iterator;

class Node
{
public:
   /* 
      Constructs a node with a given data value.
      @param s the data to store in this node
   */
   Node(Entry s);
   ~Node();
   static int get_Count() { return  ncount; }
   static void set_Count(int n) { ncount = n; }
private:
   Entry data;
   Node* previous;
   Node* next;
   static int ncount;
friend class List;
friend class Iterator;
};

class List
{
public:
   /**
      Constructs an empty list;
   */
   List() {
	   first = NULL;
	   last = NULL;
	}

   /**
      Appends an element to the list.
      @param s the value to append
   */
   ~List();
   void push_back(Entry s);
   /**
      Inserts an element into the list.
      @param iter the position before which to insert
      @param s the value to append
   */
   void insert(Iterator iter, Entry s);
   /**
      Removes an element from the list.
      @param i the position to remove
      @return an iterator pointing to the element after the
      erased element
   */
   Iterator erase(Iterator i);
   /**
      Gets the beginning position of the list.
      @return an iterator pointing to the beginning of the list
   */
   Iterator begin() const;
   /**
      Gets the past-the-end position of the list.
      @return an iterator pointing past the end of the list
   */
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
   /**  
      Looks up the value at a position.
      @return the value of the node to which the iterator points
   */
   Entry get() const;
   /**
      Advances the iterator to the next node.
   */
   void next();
   /**
      Moves the iterator to the previous node.
   */
   void previous();
   /**
      Compares two iterators
      @param b the iterator to compare with this iterator
      @return true if this iterator and b are equal
   */
   bool equals(Iterator b) const;
   Iterator& operator++(int);
   Iterator& operator--(int);
   Entry operator*() const;
   Entry* operator->();
   bool operator==(const Iterator& b) const;
   bool operator!=(const Iterator& b) const;
private:
   Node* position;
   Node* last;
friend class List;
};

#endif
